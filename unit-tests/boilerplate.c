//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"


int		main(int ac, char ** av)
{
	T(nop,
		(void)state;
	)

	return (run_test_arr(ac, av));
}
