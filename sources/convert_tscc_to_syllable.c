#include "ft_printf_inner.h"

t_s_so
	syl_uv_tob(
		uintmax_t val,
		char const * basestr,
		t_mib *b)
{
	t_s_cc	inter;
	t_s_so	ret;

	inter = my_uv_tob(val, basestr, b);
	ret.len = inter.len;
	ret.type = e_sot_cc;
	ret.cc = inter.c;
	return (ret);
}

t_s_so
	syl_lowv_tob(
		uintmax_t val,
		char const * basestr,
		t_mib *b)
{
	t_s_cc	inter;
	t_s_so	ret;

	inter = my_lowv_tob(val, basestr, b);
	ret.len = inter.len;
	ret.type = e_sot_cc;
	ret.cc = inter.c;
	return (ret);
}

t_s_so
	syl_v_tob(
		intmax_t val,
		char const * basestr,
		t_mib *b,
		t_e_sp sign_f)
{
	t_s_cc	inter;
	t_s_so	ret;

	inter = my_v_tob(val, basestr, b, sign_f);
	ret.len = inter.len;
	ret.type = e_sot_cc;
	ret.cc = inter.c;
	return (ret);
}
