#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "my_macro_overlay.h"


int		main(void)
{
	T(nop,
		(void)state;
		assert_true(1);
	)
    return (\
		_cmocka_run_group_tests("TEST_ARR", TEST_ARR,\
					g_test_index, 0, 0)\
	);
}
