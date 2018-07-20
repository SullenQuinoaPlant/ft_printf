#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(test_unicode1,
		wchar_t	*vals;

		vals = ((wchar_t[4]){0xc6, 0xa9, 0x0a, 0});

		printf_compare("s_test_unicode1.ref", "%ls", vals);
	)

	T(test_unicode2,
		wchar_t	*vals;

		vals = ((wchar_t[5]){0xc6, 0x0a, 0xa9, 0x0a, 0});

		printf_compare("s_test_unicode2.ref", "%.3ls", vals);
	)

	T(test_unicode3,
		wchar_t	*vals;

		vals = ((wchar_t[5]){0xc6, 0x0a, 0xa9, 0x0a, 0});

		printf_compare("s_test_unicode2.ref", "%.4ls", vals);
	)

	return(run_test_arr(all_of, these));
}
