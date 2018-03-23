#include "h.h"

char	*dollar(char const *in, int val)
{
	int **	const p_res = &((t_s_pct*)g_ps.chunks.content)->width;
	t_list	*new_arg;
	t_list	*new_chunk;

	if (! *in == '$')
		return (in);
	if ((new_arg = ft_lstnew(&(t_s_arg){e_int, val, 0}
	
}

char	*no_dollar(char const *in, int val)
{
}

char	*percent_conversion_width_literal(char const *in)
{
	char	*(*f_str[])(char const *, int) = {
			dollar,
			no_dollar,
			0};
	int		literal;
	int		i;
	char	*p_str;

	if ((p_str = parse_literal_integer(in, &literal)) != in)
	{
		in = p_str;
		i = -1;
		while (in == p_str && f_str[++i])
			in = f_str[i](in, literal);
	}
	return (in);
