#include "ft_printf_inner.h"

char canst	*parse_text(char const *in)
{
	size_t	const sz = sizeof(t_s_cw);
	size_t	i;
	char	c;
	t_list	*p_cw;
	t_s_txt	*chk;

	if (!*in || *in == '%')
		return (in);
	if ((chk = malloc(sizeof(t_s_txt))) &&
		(p_cw = ft_lstnew(&(t_s_cw){e_ts_txt, chk}, sz)))
	{
		i = 1;
		while ((c = in[i]) != '%' && c)
			i++;
		*chk = (t_s_txt){in, i};
		my_lstappend(&g_ps.chunks.tail, p_cw);
		in += i;
	}
	else
	{
		g_ps.errored++;
		if (chk)
			my_clean_free(chk, sizeof(t_s_txt));
	}
	return (in);
}
