#include "ft_printf_inner.h"

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
	mod = len % (grp + 1);
	return (grp - mod);
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
**grp size bigger than t_mib size would be useless,
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

void
	purge_apstr(
		t_s_pct *chk,
		t_s_so *syls, size_t count)
{
	t_s_so	* const lim = syls + count;
	t_e_sot	type;

	if (chk->flags & APSTR_FLAG)
		return;
	while (syls < lim)
		if ((type = syls->type) == e_sot_apstr_c)
			syls++->type = e_sot_c;
		else if (type == e_sot_apstr_cc)
			syls++->type = e_sot_cc;
		else if (type == e_sot_apstr_f)
			syls++->type = e_sot_f;
}
