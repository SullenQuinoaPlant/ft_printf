#define HOW_MANY_TESTS 10
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(achar,
		char	c = 'c';

		printf_diff("%c", c);
	)

	T(char_newline,
		char	c = 'c';

		printf_diff("%c\n", c);
	)

	T(text_char_text,
		char	c = 'c';

		printf_diff("aoeu_%c_aoeu", c);
	)
	return(run_test_arr(all_of, these));
}
