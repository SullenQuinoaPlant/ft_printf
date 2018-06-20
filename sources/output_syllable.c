#include "ft_printf_inner.h"

int		output_syllable(t_s_so this)
{
	enum e_sot	const type = this.type;

	if (type == e_sot_cc)
		return (output_cc(this.cc, this.len));
	return (output_c(this.len, this.c));
}

int		output_syllables(t_s_so *these, int count)
{
	t_s_so	* const limit = these + count;
	int		r;

	r = 1;
	while (these < limit && r)
		r = output_syllable(*these++);
	return (r);
}

int
	out_sylinter(
		t_s_so* ar, size_t ar_sz,
		char sep, int interval)
{
	t_s_so	* const ar_lim = ar + ar_sz;
	char	*p;
	char	*p_lim;
	int		pos;
	int		r;

	pos = interval > 0 ? -interval : THOUSAND_GROUP;
	r = 1;
	while (ar < ar_lim && r)
	{
		if (ar->type == e_sot_cc)	
			p = ar->cc;
		else
			p = &ar->c;
		p_lim = p + (ar++)->len;
		while (p < p_lim && r &&
			(pos || (r = output_c(1, sep))))
		{
			r &= output_c(1, *p++);
			pos = (pos + 1) % interval;
		}
	}
	return (r);
}
