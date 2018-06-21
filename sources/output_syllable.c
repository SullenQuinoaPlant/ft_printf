#include "ft_printf_inner.h"

int		output_syllable(t_s_so *this)
{
	enum e_sot	const type = this.type;
	int			r;

	if (type == e_sot_cc)
		r = output_cc(this->len, this->cc);
	else if (type == e_sot_c)
		r = output_c(this->len, this->c);
	else if (type == e_sot_apstr_c ||
		type == e_sot_apstr_cc)
		r = out_apstr_syl(this);
	return (r);
}

int		output_syllables(t_s_so *these, int count)
{
	t_s_so	* const limit = these + count;
	int		r;

	r = 1;
	while (these < limit && r)
		output_syllable(these++);
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
