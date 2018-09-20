#include "inner.h"

static t_s_lmp const
	g_mods[] = {
		{e_hh, "hh"},
		{e_h, "h"},
		{e_ll, "ll"},
		{e_l, "l"},
		{e_bigl, "L"},
		{e_j, "j"},
		{e_z, "z"},
		{e_t, "t"}};

#define MODS_COUNT 8
char const	*percent_convert_length_mod(char const *in)
{
	t_s_pct	*p_pct;
	size_t	i;
	size_t	len;

	if (!*in)
		return (in);
	p_pct = get_p_pct();
	p_pct->len_mod = e_no_len;
	i = -1;
	while (++i < MODS_COUNT)
	{
		len = ft_strlen(g_mods[i].s);
		if (!ft_strncmp(g_mods[i].s, in, len))
		{
			p_pct->len_mod = g_mods[i].mod;
			in += len;
			break;
		}
	}
	return (in);
}
#undef MODS_COUNT

char const	*percent_convert_specifier(char const *in)
{
	char const	*specifiers = "aAbBcdeEfFgGinopsuxX";
	t_s_pct 	*p_pct;
	char		*p_c;

	p_pct = get_p_pct();
	if (*in && (p_c = ft_strchr(specifiers, *in)))
	{
		p_pct->specifier = (t_e_cs)(p_c - specifiers + 1);
		in++;
	}
	else
		p_pct->specifier = e_no_specifier;
	return (in);
}
