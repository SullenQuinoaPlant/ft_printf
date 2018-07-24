#include "ft_printf_inner.h"

int
	is_apstr(
		t_s_pct *chk)
{
	return (chk->flags & APSTR_FLAG ? 1 : 0);
}

size_t
	apstr_only_grp_len(
		t_s_sgd *gd)
{
	t_s_so	* const lim = gd->first + gd->sz;
	t_s_so	*syl;
	size_t	ret;

	syl = gd->first;
	ret = 0;
	while (syl < lim)
	{
		if (syl->type == e_sot_apstr_c ||
			syl->type == e_sot_apstr_cc ||
			syl->type == e_sot_apstr_f)
			ret += syl->len;
		syl++;
	}
	return (ret);
}

size_t
	apstr_len_raw(
		size_t len, size_t grp)
{
	if (!(grp && len))
		return (len);
	return (len + len / grp - (len % grp ? 0 : 1));
}

int
	apstr_offset(
		size_t len, size_t grp)
{
	size_t	mod;

	if (!grp)
		return (0);
	if ((mod = len % grp))
		return (grp - mod);
	return (0);
}

void
	apstr_grp_props_offset(
		size_t grp_sz, char grp_c,
		t_s_sgd *gd)
{
	gd->apstr_grp = grp_sz;
	gd->apstr_c = grp_c;
	gd->apstr_pos = apstr_offset(apstr_only_grp_len(gd), grp_sz);
}

void
	apstr_grp_props_nooffset(
		size_t grp_sz, char grp_c,
		t_s_sgd *gd)
{
	gd->apstr_grp = grp_sz;
	gd->apstr_c = grp_c;
	gd->apstr_pos = 0;
}

void
	noapstr_grp_props(
		t_s_sgd *gd)
{
	gd->apstr_grp = 0;
	gd->apstr_c = 0;
	gd->apstr_pos = 0;
}


void
	apstr_zpad_adjust(
		t_s_so *pad, t_s_sgd *grps)
{
	size_t	grp;

	while (pad > grps->first)
		grps++;
	grp = grps->apstr_grp;
	apstr_zpad(grp, pad, &grps->apstr_pos);
}

/*Fearlessly casting between int and size_t because 
**values ought to be small and positive at all times.
**grp size is meant to be friendly to the human eye,
**padding can't be more than MAX_INT.
*/
void
	apstr_zpad(
		size_t grp,
		t_s_so *pad, int *pos_offset)
{
	size_t	len;
	size_t	pos;
	size_t	a;
	size_t	b;

	len = pad->len;
	pos = (size_t)(*pos_offset);
	if (pos >= len)
		pos -= len;
	else
	{
		a = (len - pos);
		b = a % (grp + 1);
		len -= a / (grp + 1) + (b ? 1 : 0);
		pos = b ? grp - (b - 1) : 0;
	}
	pad->len = len;
	*pos_offset = (int)pos;
}

int
	apstr_purge_ornot(
		t_s_pct *chk,
		t_s_so *syls, size_t count)
{
	t_s_so	* const lim = syls + count;
	t_e_sot	type;

	if (is_apstr(chk))
		return (0);
	while (syls < lim)
		if ((type = syls->type) == e_sot_apstr_c)
			syls++->type = e_sot_c;
		else if (type == e_sot_apstr_cc)
			syls++->type = e_sot_cc;
		else if (type == e_sot_apstr_f)
			syls++->type = e_sot_f;
		else
			syls++;
	return (1);
}
