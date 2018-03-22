#include "h.h"

char	*percent_char(char const *in)
{
	char		*(* const f_str[])(char const *) = {
				parse_text,
				parse_percent,
				0};
	char		*p_str;
	int			i;
	t_list		*out_bit;
	t_s_char	*pct;

	if (*in != '%')
		return (in);
	if ((pct = malloc(sizeof(t_s_char))) &&
		(out_bit = ft_lstnew(pct, sizeof(t_s_char))))
	{
		((t_s_char*)out_bit->content)->c = '%';
		my_lstappend(&g_ps.out_bits_anchor.content, out_bit);
		p_str = ++in;
		i = -1;
		while (f_str[++i] && p_str == in)
			in = f_str[i](in);
	}
	else if (pct)
		free(pct);
	return (in);
}
