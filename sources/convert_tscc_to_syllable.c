#include "inner.h"

t_s_so
	syl_uv_tob(
		uintmax_t val,
		char const * basestr,
		t_mib *b)
{
	t_s_vtb_cc	inter;
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
		int val_sz,
		char const * basestr,
		t_mib *b)
{
	t_s_vtb_cc	inter;
	t_s_so	ret;

	inter = vtb_lv_tscc(val, val_sz, basestr, b);
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
		t_e_vtb_sp sign_f)
{
	t_s_vtb_cc	inter;
	t_s_so	ret;

	inter = vtb_v_tscc(val, basestr, b, sign_f);
	ret.len = inter.len;
	ret.type = e_sot_cc;
	ret.cc = inter.c;
	return (ret);
}
