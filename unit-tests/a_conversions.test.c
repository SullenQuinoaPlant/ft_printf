#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"

#include "printf_diff.c"

int		main(void)
{
	T(test1,
		double	d;

		d = 0.0;
		printf_diff("%a", d);
	)
    return (\
		_cmocka_run_group_tests("TEST_ARR", TEST_ARR,\
					test_index, 0, 0)\
	);
}
