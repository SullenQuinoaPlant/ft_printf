#include "my_stupidmath.h"

int		my_log2(uintmax_t x)
{
	int		i;

	i = 0;
	while (x)
	{
		x /= 2;
		i++;
	}
	return (i);
}
