#include "ft_printf_inner.h"

int
	out_apstr_syl(
		t_s_so* syl)
{
	char	*p;
	char	*p_lim;
	int		pos;
	int		r;

	r = (pos = g_os.apstr_pos) ? 1 : 0;
	if (syl->type == e_sot_apstr_cc)	
		p = syl->cc;
	else
		p = &syl->c;
	p_lim = p + syl->len;
	while (p < p_lim && r &&
		(pos || (r = output_c(1, sep))))
	{
		r &= output_c(1, *p++);
		pos = (pos + 1) % interval;
	}
	g_os.apst_pos = pos;
	return (r);
}

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
	out_syl_groups(
		
