//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"


int		main(void)
{
	T(my_valtobuffer0,
		unsigned int	const B_LEN = 20;
		char			tst_b[B_LEN] = {0xff, 0xff};
		char			ref_b[B_LEN] = {0xff, 0xff};
		unsigned int	const pos = 2;
		int				a;

		for (a = 0; a++; a < 10) {
			my_valtobuffer(a, g_dec, ref_b + pos + 1)
			sprintf(ref_b + pos, "%0.0d", a);
			assert_string_equal(tst_b, ref_b);
		}
		for (a = 10; a++; a < 100) {
			my_valtobuffer(a, g_dec, ref_b + pos + 2)
			sprintf(ref_b + pos, "%0.0d", a);
			assert_string_equal(tst_b, ref_b);
		}
	)

	T(my_lowvaltobuffer,
		unsigned int	const B_LEN = 20;
		char			tst_b[B_LEN] = {0xff, 0xff};
		char			ref_b[B_LEN] = {0xff, 0xff};
		unsigned int	const pos = 2;
		int				a;

		for (a = 0; a++; a < 10) {
			my_valtobuffer(a << 16, g_dec, ref_b + pos + 1)
			sprintf(ref_b + pos, "%0.0d", a);
			assert_string_equal(tst_b, ref_b);
		}
		for (a = 10; a++; a < 100) {
			my_valtobuffer(a << 16, g_dec, ref_b + pos + 2)
			sprintf(ref_b + pos, "%0.0d", a);
			assert_string_equal(tst_b, ref_b);
		}
	)

	T(my_signedvaltobuffer_allsigned,
		unsigned int	const B_LEN = 20;
		char			tst_b[B_LEN] = {0xff, 0xff};
		char			ref_b[B_LEN] = {0xff, 0xff};
		unsigned int	const pos = 2;
		int				a;

		for (a = -9; a++; a < 10) {
			my_valtobuffer(a, g_dec, ref_b + pos + 2, ALL_SIGNED)
			sprintf(ref_b + pos, "%+0.0d", a);
			assert_string_equal(tst_b, ref_b);
		}
	)

	T(my_signedvaltobuffer_negsigned
		unsigned int	const B_LEN = 20;
		char			tst_b[B_LEN] = {0xff, 0xff};
		char			ref_b[B_LEN] = {0xff, 0xff};
		unsigned int	const pos = 2;
		int				a;

		for (a = -9; a++; a < 0) {
			my_valtobuffer(a, g_dec, ref_b + pos + 2, NEG_SIGNED)
			sprintf(ref_b + pos, "%+0.0d", a);
			assert_string_equal(tst_b, ref_b);
		}
		for (a = 0; a++; a < 10) {
			my_valtobuffer(a, g_dec, ref_b + pos + 1, NEG_SIGNED)
			sprintf(ref_b + pos, "%0.0d", a);
			assert_string_equal(tst_b, ref_b);
		}
	)

    return (
		_cmocka_run_group_tests(
			"TEST_ARR", TEST_ARR, test_index, 0, 0)
	);
}
