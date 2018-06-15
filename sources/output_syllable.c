#include "ft_printf_inner.h"

int		output_syllable(t_s_so this)
{
	e_sot	const type = this.type;

	if (type == e_sot_cc)
		return (output_cc(this.cc, this.len));
	else if (type == e_sot_c)
		return (output_c(this.len, this.c));
}

int		output_syllables(t_s_so *these, int count)
{
	t_s_so	* const limit = these + count;
	int		r;

	r = 1;
	while (these < limit && r)
		r |= output_syllable(these++)
	return (r);
}
