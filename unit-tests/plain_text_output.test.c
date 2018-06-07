#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"

#include "printf_diff.c"

int		main(void)
{
	T(test1,
		printf_diff("this is some text");
	)
	T(test2,
		printf_diff("this text has a \n line break");
	)
	T(test3,
		printf_diff("this text has a percent sign : "
			"%%");
	)
    return (\
		_cmocka_run_group_tests("TEST_ARR", TEST_ARR,\
					test_index, 0, 0)\
	);
}
