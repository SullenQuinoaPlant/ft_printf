#include "h.h"

char	*percent_char(char const *in)
{
	t_s_cw *	const wrap = (t_s_cw*)g_ps.chunks.content;
	t_s_char	*p_chunk;

	if (*in == '%')
	{
		if ((p_chunk = malloc(sizeof(t_s_char))))
		{
			*p_chunk = (t_s_char){'%'};
			*wrap = (t_s_cw){e_char_c, p_chunk};
			in++;
		}
		else 
			g_ps.errored++;
	}
	return (in);
}
