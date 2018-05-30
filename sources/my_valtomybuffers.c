#inlude "my_voltobuffers.h"

size_t	my_uv_tob(uintmax_t val,
					char const * const basestr,
					t_s_mib *b)
{
	char	*b_end;

	b_end = b->b + e_mib_offset;
	return (my_valtobuffer(val, basestr, b_end));
}

size_t	my_lowv_tob(uintmax_t val,
					char const * const basestr,
					t_s_mib *b)
{
	char	*b_end;

	b_end = b->b + e_mib_offset;
	return (my_lowvaltob(val, basestr, b_end));
}

size_t	my_v_tob(intmax_t val,
				char const * const basestr,
				t_s_mib *b,
				t_e_sp sign_f)
{
	char	*b_end;

	b_end = b->b + e_mib_offset;
	return (my_signvaltob(val, basestr, b_end, sign_f));
}
