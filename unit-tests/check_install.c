#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"


int		main(void)
{
	T(nop,
		printf("Successful call to cmocka\n");
		(void)state;
	)
    return (\
		_cmocka_run_group_tests("TEST_ARR", TEST_ARR,\
					test_index, 0, 0)\
	);
}
