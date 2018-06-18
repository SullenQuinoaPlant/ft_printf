#include "my_valtobuffers.h"

char const	* const g_oct = "01234567";
char const	* const g_dec =	"0123456789";
char const	* const g_hex =	"0123456789abcdef";
char const	* const g_bhex = "0123456789ABCDEF";

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
**ijk array:
**	i digits are trailing zeros
**	j digits are yummy
**	k digits may represent any uintmax_t
*/
#define I 0
#define J 1
#define K 2
size_t
	my_lowvaltob(
		uintmax_t val, int val_sz,
		char const * const basestr,
		char *b_end)
{
	unsigned char	r;
	int				log2;
	size_t			ijk[3];
	uintmax_t		mask;

	r = ft_strlen(basestr);
	log2 = my_log2(r);
	ijk[K] = (val_sz * 8) / log2;
	mask = ~0 << log2;
	ijk[I] = 0;
	while (!(~mask & val) && (ijk[I] < ijk[K]))
	{
		ijk[I]++;
		val /= r;
	}
	ijk[J] = 0;
	while ((ijk[I] + ijk[J]) < ijk[K] || ijk[J] == 0)
	{
		*(b_end - ijk[J]++) = basestr[val % r];
		val /= r;
	}
	return (ijk[J]);
}
#undef I
#undef J
#undef K

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
	if (val < 0 || sign_f == e_all ||
		(val && sign_f == e_abs))
		i++;
	return (i);
}
