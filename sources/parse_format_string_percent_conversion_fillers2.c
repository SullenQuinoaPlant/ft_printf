#include "ft_printf_inner.h"

char	*percenconvert_t_length_mod(char const *in)
{
	t_s_pct * const	p_pct = get_p_pct();
	t_s_lmp const	mods[] = {
					{e_hh, "hh"},
					{e_h, "h"},
					{e_l, "l"},
					{e_ll, "ll"},
					{e_bigl, "L"},
					{e_j, "j"},
					{e_z, "z"},
					{e_t, "t"}};
	size_t const	len = sizeof(mods) / sizeof(mods[0]);
	int				i;

	if (*in)
	{
		i = -1;
		while (++i < len)
			if (! ft_strncmp(mods[i].str, in, ft_strlen(mods[i].str)))
			{
				p_pct->len_mod = mods[i].mod;
				in += ft_strlen(mods[i].str);
				break;
			}
		if (i == len)
			p_pct->len_mod = e_no_len;
	}
	return (in);
}

char	*percenconvert_t_specifier(char const *in)
{
	t_s_pct * const	p_pct = get_p_pct();
	char const *	specifiers = "aAcdeEfFgGinoupsxX"
	char *			p_str;

	if (*in && (p_str = ft_strchr(specifiers, *in)))
	{
		p_pct->specifier = (t_e_cs)(p_str - specifiers + 1);
		in++;
	}
	else
		p_pct->specifier = e_no_specifier;
	return (in);
}
