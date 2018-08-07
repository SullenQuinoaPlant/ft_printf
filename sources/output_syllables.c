#include "ft_printf_inner.h"

static int
	out_syl_chars(
		size_t count, t_s_so *syl)
{
	int			r;
	t_e_sot		type;

	r = 0;
	if ((type = syl->type) == e_sot_apstr_c)
		r = output_c(count, syl->c);
	else if (type == e_sot_apstr_cc)
		r = output_cc(count, syl->cc++);
	else if (type == e_sot_apstr_f)
		r = syl->f(count, syl->arg);
	return (r);
}

int
	out_apstr_syl(
		t_s_so *syl)
{
	t_s_so	eat_this;
	size_t	pos;
	size_t	count;
	int		r;

	pos = (size_t)g_os.apstr_pos;
	eat_this = *syl;
	r = 1;
	while (eat_this.len && r)
		if	(pos >= g_os.apstr_grp &&
			(r = output_c(1, g_os.apstr_c))
			pos = 0;
		else
		{
			count = g_os.apstr_grp - pos;
			if (count > eat_this.len)
				count = eat_this.len;
			eat_this.len -= count;
			pos += count;
			r = out_syl_chars(count, &eat_this);
		}
	g_os.apstr_pos = pos;
	return (r);
}

int
	output_syllable(
		t_s_so *this)
{
	t_e_sot	const type = this->type;
	int		r;

	r = 0;
	if (type == e_sot_cc)
		r = output_cc(this->len, this->cc);
	else if (type == e_sot_c)
		r = output_c(this->len, this->c);
	else if (type == e_sot_f)
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
