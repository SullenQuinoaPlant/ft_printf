#include "ft_printf_inner.h"

size_t
	apstr_len_raw(
		size_t len, size_t grp_sz)
{
	if (!grp_sz)
	{
		g_os.errored++;
		return (0);
	}
	return (len / grp_sz);
}

size_t
	apstr_len_syl(
		t_s_so *syl, unsigned int count, size_t grp_sz)
{
	t_s_so	* const lim = syl + count;
	size_t	added;
	size_t	tmp;
	size_t	over;
	

	if (!grp_sz)
	{
		g_os.errored++;
		return (0);
	}
	over = 0;
	added = 0;
	while (syl < lim)
	{
		tmp = over + syl->len;
		if (tmp < over)
			g_os.errored++;
		added += tmp / grp_sz;
		over = tmp % grp_sz;
	}
	return (added);
}

/*Fearlessly casting between int and size_t because 
**values ought to be small and positive at all times.
**grp size bigger than t_mib size would be useless,
**padding can't be more than MAX_INT.
*/
void
	apstr_pad_adjust(
		t_s_so *pad, t_s_sgb *grps)
{
	size_t	grp;
	size_t	pos;
	size_t	len;
	size_t	a;
	size_t	b;

	while (pad > grps->first)
		grps++;
	grp_sz = grps->apstr_grp;
	pos = (size_t)grps->apstr_pos;
	len = pad->len;
	if (pos >= len)
		pos -= len;
	else
	{
		a = (len - pos);
		b = a % (grp + 1);
		pos = b ? grp - (b - 1) : 0;
		len = a / (grp + 1) * grp;
		len += pos ? b - 1 : 0;
	}
	pad->len = len;
	grps->apstr_pos = (int);
}
