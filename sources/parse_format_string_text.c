#include "h.h"

char	*parse_text(char const *in)
{
	size_t	i;
	char	c;
	t_list	*new;

	if (*in && *in != '%')
	{
		i = 1;
		while ((c = in[i]) != '%' && c)
			i++;
		if ((new = ft_lstnew(&(t_s_txt){in, i}, sizeof(t_s_txt))))
		{
			my_lstappend(&g_ps.chunks.content, new);
			in += i;
		}
		else
			g_ps.errored++;
	}
	return (in + i);
}
