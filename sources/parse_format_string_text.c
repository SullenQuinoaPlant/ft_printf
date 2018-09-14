#include "inner.h"

static t_s_txt	*init_cw()
{
	size_t	const sz = sizeof(t_s_cw);
	t_list	*p_cw;
	t_s_txt	*chk;

	if ((chk = malloc(sizeof(t_s_txt))) &&
		(p_cw = ft_lstnew(&(t_s_cw){e_txt_c, chk}, sz)))
	{
		ft_lstappend(&g_ps.chunks.tail, p_cw);
		return (chk);
	}
	else if (chk)
		free(chk);
	return (0);
}

char const	*parse_text(char const *in)
{
	size_t	i;
	char	c;
	t_s_txt	*chk;

	if ((chk = init_cw()))
	{
		i = 1;
		while ((c = in[i]) != '%' && c)
			i++;
		*chk = (t_s_txt){in, i};
		in += i;
	}
	else
		g_ps.errored++;
	return (in);
}

char const	*parse_text_strict(char const *in)
{
	if (*in != '%')
		in = parse_text(in);
	return (in);
}
