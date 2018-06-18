#include "my_valtobuffers.h"

t_s_cc	my_uv_tob(uintmax_t val,
					char const * const basestr,
					t_mib *b)
{
	t_s_cc	ret;
	char	*b_end;

	b_end = (char*)b + e_mib_offset;
	*b_end = 0;
	ret.len = my_valtobuffer(val, basestr, b_end - 1);
	ret.c = b_end - ret.len;
	return (ret);
}

t_s_cc
	my_lowv_tob(
		uintmax_t val,
		int	val_sz,
		char const * const basestr,
		t_mib *b)
{
	t_s_cc	ret;
	char	*b_end;

	b_end = (char*)b + e_mib_offset;
	*b_end-- = 0;
	ret.len = my_lowvaltob(val, val_sz, basestr, b_end);
	ret.c = b_end - ret.len + 1;
	return (ret);
}

t_s_cc	my_v_tob(intmax_t val,
				char const * const basestr,
				t_mib *b,
				t_e_sp sign_f)
{
	t_s_cc	ret;
	char	*b_end;

	b_end = (char*)b + e_mib_offset;
	*b_end-- = 0;
	ret.len = my_signvaltob(val, basestr, b_end, sign_f);
	ret.c = b_end - ret.len + 1;
	return (ret);
}
