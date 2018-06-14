#include "ft_printf_inner.h"

void	stuff_syllables(
	t_stuffer *f_str, t_s_pct *chk,
	void *p_stf, int pad_pos[])
{
	t_stuffer	f;
	e_pad_pos	pad;
	int			i;

	pad = e_left;
	i = -1;
	while ((f = f_str[++i]))
		if (f == &pad_syllable)
			pad_pos[pad++] = i;
		else
			(*f)(i, p_stf, chk);
}

void	pad_syllable(int i, void *v, t_s_pct *t)
{
	(void)i;
	(void)v;
	(void)t;
}
