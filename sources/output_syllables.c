#include "ft_printf_inner.h"

int
	out_apstr_syl(
		t_s_so* syl)
{
	char	*p;
	size_t	i;
	int		pos;
	int		r;
	int		inc;

	r = (pos = g_os.apstr_pos) ? 1 : 0;
	inc = syl->type == e_sot_apstr_cc ? 1 : 0;
	p = &syl->c;
	if (inc)	
		p = syl->cc;
	i = syl->len;
	while (i-- && r &&
		(pos || (r = output_c(1, g_os.apstr_c))))
	{
		r &= output_c(1, *p);
		p += inc;
		pos = (pos + 1) % g_os.apstr_grp;
	}
	g_os.apstr_pos = pos;
	return (r);
}

int		output_syllable(t_s_so *this)
{
	t_e_sot	const type = this->type;
	int		r;

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
		r = output_syllable(these++);
	return (r);
}

int
	out_syl_groups(
		t_s_sgd *grp, int count)
{
	t_s_sgd	* const lim = grp + count;
	int		r;

	while (grp < lim && r)
	{
		g_os.apstr_grp = grp->apstr_grp;
		g_os.apstr_pos = grp->apstr_pos;
		g_os.apstr_c = grp->apstr_c;
		r = output_syllables(grp->first, grp->sz);
	}
	return (r);
}
