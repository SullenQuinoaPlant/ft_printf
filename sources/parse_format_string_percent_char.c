#include "h.h"

char	*percent_char(char const *in)
{
	t_list		*out_bit;

	if (*in == '%')
	{
		if ((out_bit = ft_lstnew(&(t_s_char){'%'}, sizeof(t_s_char))))
		{
			my_lstappend(&g_ps.out_bits_anchor.content, out_bit);
			in++;
		}
		else 
			g_ps.errored++;
	}
	return (in);
}
