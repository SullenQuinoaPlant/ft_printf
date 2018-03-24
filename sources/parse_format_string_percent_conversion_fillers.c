#include "h.h"

char	*percent_conversion_flags(char const *in)
{
	const char		flags[] = {'#', '0', '-', ' ', '+', '\''};
	const size_t	len = sizeof(flags) / sizeof(char);
	char * 			const p_res = &((t_s_pct*)g_ps.chunks.content)->flags;
	size_t			i;

	while (*in)
	{
		i = 0;
		while (i < len)
		{
			if (*in == flags[i])
			{
				*p_res |= (0x01 << i);
				break;
			}
			i++;
		}
		if (i == len)
			break;
		in++;
	}
	return (in);
}


char	*percent_conversion_flags(char const *in)
{
}

char	*percent_conversion_flags(char const *in)
{
}

char	*percent_conversion_flags(char const *in)
{
}
