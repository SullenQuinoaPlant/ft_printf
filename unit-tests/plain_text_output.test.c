#define HOW_MANY_TESTS 10
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

int	declare_tests_and_run(int all_of, char *these[])
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
	return(run_test_arr(all_of, these));
}
