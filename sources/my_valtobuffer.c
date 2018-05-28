#include "h.h"

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

size_t	my_lowvaltobuffer(uintmax_t val,
					char const * const basestr,
					char *b_end)
{
	unsigned char	r;
	size_t			i;

	r = ft_strlen(basestr);
	while (!(val % r) && val)
		val /= r;
	i = 0;
	while (val)
	{
		*(b_end - i++) = basestr[val % r];
		val /= r;
	}
	return (i);
}

size_t	my_signedvaltobuffer(intmax_t val,
						char const * const basestr,
						char *b_end,
						t_e_sp sign_f)
{
	size_t		i;
	int			sign;

	sign = val < 0 ? -1 : 1;
	i = my_valtobuffer((val * sign), basestr, b_end);
	*(b_end - i) = sign < 0 ? '-' : '+';
	if (val < 0 || sign_f == e_all_signed ||
		(val && sign_f == e_abs_signed))
		i++;
}
