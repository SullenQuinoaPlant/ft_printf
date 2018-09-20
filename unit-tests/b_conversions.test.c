#define HOW_MANY_TESTS 10
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(achar,
		char	c = '\377';

		printf_compare("b_achar.ref", "%hhb\n", &c);
	)
	T(achar_hex,
		char	c = '\377';

		printf_compare("B_achar.ref", "%hhB\n", &c);
	)

	T(twochars,
		char	*c;

		c = ((char[2]){0xAC, 0xCA});
		printf_compare("b_twochars.ref", "%.2hhb\n", c);
	)
	T(twochars_hex,
		char	*c;

		c = ((char[2]){0xAC, 0xCA});
		printf_compare("B_twochars.ref", "%.2hhB\n", c);
	)
	return(run_test_arr(all_of, these));
}
