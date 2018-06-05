#include "ft_printf_inner.h"

char const	*percent_char(char const *in)
{
	t_s_cw		* const cw = g_ps.chunks.tail->content;
	t_s_char	*chunk;

	if (*in == '%')
	{
		in++;
		if ((chunk = malloc(sizeof(t_s_char))))
		{
			*chunk = (t_s_char){'%'};
			*cw = (t_s_cw){e_char_c, chunk};
		}
		else 
			g_ps.errored++;
	}
	return (in);
}
