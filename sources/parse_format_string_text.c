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
		ft_lstadd(&g_ps.p_out_bits, new);
	else
		return (in);
	return (in + i);
}
