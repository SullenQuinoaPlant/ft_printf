#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"

#include "printf_diff.c"

void	test_declarations()
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
}
