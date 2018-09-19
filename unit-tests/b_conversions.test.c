#define HOW_MANY_TESTS 10
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(achar,
		char	c = '\277';

		printf_compare("b_achar.ref", "%bhh\n", &c);
	)
	T(achar_hex,
		char	c = '\277';

		printf_compare("B_achar.ref", "%Bhh\n", &c);
	)

	T(twochars,
		char	*c;

		c = ((char[2]){0xAC, 0xCA});
		printf_compare("b_twochars.ref", "%.2bhh\n", c);
	)
	T(twochars_hex,
		char	*c;

		c = ((char[2]){0xAC, 0xCA});
		printf_compare("B_twochars.ref", "%.2Bhh\n", c);
	)
	return(run_test_arr(all_of, these));
}
