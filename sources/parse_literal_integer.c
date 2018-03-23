#include "h.h"

char	*parse_literal_integer(char const *in, int	*p_res)
{
	int			res;
	t_list		*hold_res;

	if (! ft_isdigit(*in))
		return (in);
	res = 0;
	while (ft_isdigit(*in))
	{
		res *= 10;
		res += *in++ - '0';
	}
	*p_res = res;
	return (in)
}
