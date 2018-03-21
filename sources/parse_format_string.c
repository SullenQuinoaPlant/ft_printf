#include "h.h"

int		get_set_dollar_convention(unsigned int arg_count,
									unsigned int dollar_count)
{
	static t_eDollar	status = e_no_status;

	if (status == e_no_dollar && dollar_count ||
		status == e_all_dollar && dollar_count < arg_count)
		status = e_mix_dollar;
	else if (status == e_no_status)
	{
		if (arg_count != dollar_count)
			status = e_mix_dollar;
		else if (! dollar_count)
			status = e_no_dollar;
		else
			status = e_all_dollar;
	}
	return (status);
}

char	*parse_percent(char const *in,
							t_list **p_out_bits,
							t_list **p_req_args,
							t_list **p_known_ints)
{
	unsigned int	arg_index;
	unsigned int	dollar_count;

	arg_count = 0;
	dollar_count = 0;

	get_set_dollar_convention(arg_index, dollar_count);
	return (in);
}

char	*parse_text(char const *in, t_list **p_out_bits)
{
	t_sTxt	chunk;
	size_t	i;
	char	c;
	t_list	*new;

	chunk.strt = in;
	i = 1;
	while ((c = in[i]) != '%' && c)
		i++;
	chunk.len = i;
	new = ft_lstnew(&(t_sTxt){in, i}, sizeof(t_sTxt));
	ft_lstadd(p_out_bits, new);
	return (in + i);
}

int		parse_format_string(char const *in,
							t_list **p_out_bits,
							t_list **p_req_args,
							t_list **p_known_ints)
{
	t_list	*out_bits;
	t_list	*req_args;
	t_list	*known_ints;

	out_bits = 0;
	req_args = 0;
	known_ints = 0;
	while (*in)
		if (*in == '%')
			in = parse_percent(in, &out_bits, &req_args, &known_ints);
		else
			in = parse_text(in, &out_bits);
	*p_out_bits = out_bits;
	*p_req_args = req_args;
	*p_known_ints = known_ints;
	return ((int)*in)
}
