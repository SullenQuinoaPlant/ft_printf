#include "ft_printf_inner.h"

size_t
	apstr_len_raw(
		size_t len, size_t grp_sz)
{
	if (!grp_sz)
		return (0);
	return (len / grp_sz);
}

int
	apstr_offset(
		size_t len, size_t grp)
{
	size_t	mod;

	if (!grp)
		return (0);
	mod = len % grp;
	return (mod ? grp - mod : 0);
}

#define ADD 0
#define TMP 1
#define OVR 2
#define GSZ 3
size_t
	apstr_len_grp(
		t_s_sgd *grp)
{
	t_s_so	* const lim = grp->first + grp->sz;
	t_s_so	* syl;
	size_t	s[GSZ + 1];
	t_e_sot	type;

	if (!(s[GSZ] = grp->apstr_grp))
		return (0);
	s[ADD] = 0;
	s[OVR] = (size_t)grp->apstr_pos;
	syl = grp->first;
	while (syl < lim)
	{
		if ((type = syl->type) != e_sot_apstr_c &&
			type != e_sot_apstr_cc)
			continue;
		s[TMP] = s[OVR] + syl->len;
		if (s[TMP] < s[OVR])
			g_os.errored++;
		s[ADD] += s[TMP] / s[GSZ];
		s[OVR] = s[TMP] % s[GSZ];
	}
	return (s[ADD]);
}
#undef ADD
#undef TMP
#undef OVR
#undef GSZ

void
	apstr_grp_adjust(
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
