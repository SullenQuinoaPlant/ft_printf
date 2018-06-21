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
