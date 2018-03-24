#include "h.h"

char	*parse_conversion(char const *in)
{
	char	*(* const f_str[])(char const *) = {
			percent_conversion_dollar_arg,
			percent_conversion_flags,
			percent_conversion_width,
			percent_conversion_precision,
			percent_conversion_length_mod,
			percent_conversion_specifier,
			0};
	t_list	*out_bit;

	if (! *in)
		return (in);
	if ((out_bit = ft_lstnew(&((t_s_pct){0x00, 0, 0, 0}), sizeof(t_s_pct))))
	{
		my_lstappend(&g_ps.out_bits_anchor.content, out_bit);
		in = attempt_all(in, f_str);
	}
	else
		g_ps.errored++;
	return (in);
}
