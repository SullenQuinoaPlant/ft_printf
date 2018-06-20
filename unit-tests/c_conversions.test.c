//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"

#include "printf_diff.c"

int		main(int ac, char ** av)
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

	return (run_test_arr(ac, av));
}
