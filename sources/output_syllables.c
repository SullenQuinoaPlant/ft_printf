#include "ft_printf_inner.h"

static int
	out_a_syl_char(
		t_s_so *init_syl)
{
	static t_s_so	syl;
	int				r;

	if (init_syl && (syl = *init_syl))
		return (-1);
	if (!syl.len--)
		return (0);
	if (syl.type == e_sot_apstr_c)
		r = output_c(1, syl.c);
	else if (syl.type == e_sot_apstr_cc)
		r = output_cc(1, syl.cc++);
	else if (syl.type == e_sot_apstr_f)
		r = syl.f(1, syl.arg);
	return (r);
}

int
	out_apstr_syl(
		t_s_so *syl)
{
	char	*p;
	size_t	i;
	size_t	pos;
	int		r;
	int		inc;

	pos = (size_t)g_os.apstr_pos;
	r = out_a_syl_char(syl);
	while (r)
		if ((pos++) == g_os.apstr_grp)
		{
			pos = 0;
			r = output_c(1, g_os.apstr_c);
			continue;
		}
		else
			r = out_a_syl_char(0);
	g_os.apstr_pos = pos;
	return (r);
}

int
	output_syllable(
		t_s_so *this)
{
	t_e_sot	const type = this->type;
	int		r;

	if (type == e_sot_cc)
		r = output_cc(this->len, this->cc);
	else if (type == e_sot_c)
		r = output_c(this->len, this->c);
	else if (type == e_sot_f ||
		r = this->f(this->len, this->arg);
	else if (type == e_sot_apstr_c ||
		type == e_sot_apstr_cc ||
		type == e_sot_apstr_f)
		r = out_apstr_syl(this);
	return (r);
}

int
	output_syllables(
		t_s_so *these, int count)
{
	t_s_so	* const limit = these + count;
	int		r;

	r = -1;
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

	r = 1;
	while (grp < lim && r)
	{
		gos_set_grp(grp);
		r = output_syllables(grp->first, grp->sz);
		grp++;
	}
	return (r);
}
