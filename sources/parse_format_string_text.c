#include "h.h"

char	*parse_text(char const *in)
{
	size_t	i;
	char	c;
	t_list	*p_wrap;
	t_s_txt	*p_chunk;

	if (*in && *in != '%')
	{
		if ((p_chunk = malloc(sizeof(t_s_txt))) &&
			(p_wrap = ft_lstnew(&(t_s_cw){e_ts_txt, p_chunk}, sizeof(t_s_cw))))
		{
			i = 1;
			while ((c = in[i]) != '%' && c)
				i++;
			*p_chunk = (t_s_txt){in, i};
			my_lstappend(&g_ps.chunks.tail, p_wrap);
			in += i;
		}
		else
		{
			g_ps.errored++;
			if (p_chunk)
				my_clean_free(p_chunk, sizeof(t_s_txt));
		}
	}
	return (in + i);
}
