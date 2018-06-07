#include "my_valtobuffers.h"

char const	g_oct[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
char const	g_dec[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char const	g_hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
char const	g_bhex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

size_t	my_valtobuffer(uintmax_t val,
					char const * const basestr,
					char *b_end)
{
	unsigned char const	r = ft_strlen(basestr);
	size_t				i;

	i = 0;
	while (val || i == 0)
	{
		*(b_end - i++) = basestr[val % r];
		val /= r;
	}
	return (i);
}

/*only works with bases that are powers of 2,
**most significant bits set to 0 should be avoided
*/
size_t	my_lowvaltob(uintmax_t val,
					char const * const basestr,
					char *b_end)
{
	unsigned char	r;
	unsigned char	rmask;
	size_t			i;
	uintmax_t		mask;
	int				shift;

	r = ft_strlen(basestr);
	mask = ~0 << my_log2(r);
	while (!(~mask & val) && val)
		val /= r;
	i = 0;
	while (val || i == 0)
	{
		*(b_end - i++) = basestr[val % r];
		val /= r;
	}
	return (i);
}

size_t	my_signvaltob(intmax_t val,
						char const * const basestr,
						char *b_end,
						t_e_sp sign_f)
{
	size_t		i;
	int			sign;

	sign = val < 0 ? -1 : 1;
	i = my_valtobuffer((val * sign), basestr, b_end);
	*(b_end - i) = sign < 0 ? '-' : '+';
	if (val < 0 || sign_f == e_all_sign ||
		(val && sign_f == e_abs_sign))
		i++;
	return (i);
}
