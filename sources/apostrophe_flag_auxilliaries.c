#include "ft_printf_inner.h"

size_t
	apstr_len_raw(
		size_t len, size_t grp_sz)
{
	if (!grp_sz)
		return (0);
	return (len / grp_sz - len % grp_sz ? 0 : 1);
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

size_t
	apstr_len_syls(
		t_s_so *syl, size_t count,
		size_t grp)
{
	size_t	tmp;
	size_t	over;
	size_t	add;
	t_e_sot	type;
	
	add = 0;
	over = 0;
	while (count--)
	{
		if ((type = syl->type) != e_sot_apstr_c &&
			type != e_sot_apstr_cc)
			continue;
		tmp = over + syl->len;
		if (tmp < over)
			g_os.errored++;
		add += tmp / grp;
		over = tmp % grp;
	}
	add -= over ? 0 : 1;
	return (add);
}

size_t
	apstr_len_grp(
		t_s_sgd *grp)
{
	size_t	r;

	r = apstr_len_syls(grp->first, grp->sz, grp->apstr_grp);
	return (r);
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
