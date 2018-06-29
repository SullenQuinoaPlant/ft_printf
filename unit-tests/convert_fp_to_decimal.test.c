#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "convert_decompose_floating_point.c"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(near_low_10p__0,
		int32_t	t;

		t = near_low_10p(1);
		assert_true(t == 0);
		t = near_low_10p(0);
		assert_true(t == 0);
		t = near_low_10p(-1);
		assert_true(t == -1);
	)
	T(near_low_10p__1,
		int32_t	t;

		t = near_low_10p(10);
		assert_true(t == 3);
		t = near_low_10p(-10);
		assert_true(t == -4);
	)
	T(near_low_10p__2,
		int32_t	t;

		t = near_low_10p((1 << 14) - 1);
		assert_true(t == 4931 || t == 4930);
		t = near_low_10p(-(1 << 14) + 1);
		assert_true(t == -4931 || t == -4932);
	)
	return(run_test_arr(all_of, these));
}
