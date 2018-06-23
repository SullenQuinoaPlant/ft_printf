#define HOW_MANY_TESTS 10
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

void	test_declarations();
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
}
