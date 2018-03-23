#include "h.h"

char	*parse_text(char const *in)
{
	char	*(* const f_str[])(char const *) = {
			parse_percent,
			0};
	size_t	i;
	char	c;
	t_list	*new;

	if (! *in || *in == '%')
		return (in);
	i = 1;
	while ((c = in[i]) != '%' && c)
		i++;
	if ((new = ft_lstnew(&(t_s_txt){in, i}, sizeof(t_s_txt))))
		my_lstappend(&g_ps.out_bits_anchor.content, new);
	else
		return (in);
	p_str = (in = in + i);
	i = 0;
	while (f_str[i] && p_str == in)
		p_str = f_str[i++](in);
	return (p_str);
}
