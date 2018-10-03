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

	T(test1,
		printf_diff("%s", "this is a string");
	)

	T(test2,
		printf_diff("%.12s", "this is a string");
	)

	T(test3,
		printf_diff("%100s", "this is a string");
	)

	T(non_printable_0,
		printf_compare("s_non_printable_0.ref",
			"this is a string with all the non printables: %#s\n",
			"\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F"
			"\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1A\x1B\x1C\x1D\x1E\x1F");
	)
			
	T(non_printable_0_Lstring,
		wchar_t	*str;

		str = ((wchar_t[32]){
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0});

		printf_compare("s_non_printable_0_Lstring.ref",
			"this is a string with all the non printables: %#S\n", str);
	)
			
	return(run_test_arr(all_of, these));
}
