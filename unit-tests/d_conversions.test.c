//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 100
#include "cmocka/my_macro_overlay.h"

#include "printf_diff.c"

int		main(int ac, char ** av)
{
	T(test1,
		char	t = 0;

		printf_diff("%hhd", t);
	)

	T(test2,
		short	t = 0;

		printf_diff("%hd", t);
	)

	T(test3,
		int		t = 0;

		printf_diff("%d", t);
	)

	T(test4,
		long int	t = 0;

		printf_diff("%ld", t);
	)

	T(test5,
		long long int	t = 0;

		printf_diff("%lld", t);
	)

	T(test6,
		char	t = 0;

		printf_diff("%hhd", t);
	)

	T(test7,
		short	t = 0;

		printf_diff("%hd", t);
	)

	T(test8,
		int		t = 0;

		printf_diff("%d", t);
	)

	T(test9,
		long int	t = 0;

		printf_diff("%ld", t);
	)

	T(test10,
		long long int	t = 0;

		printf_diff("%lld", t);
	)

	T(test11,
		ssize_t	t = 1234;

		printf_diff("%zd", t);
	)

	T(test12,
		ptrdiff_t	t = 789456;

		printf_diff("%td", t);
	)

	T(test13,
		int		t = 0;

		printf_diff("%#d", t);
	)

	T(test14,
		int		t = 0;

		printf_diff("% d", t);
	)

	T(test15,
		int		t = 0;

		printf_diff("%-d", t);
	)

	T(test16,
		int		t = 0;

		printf_diff("%+d", t);
	)

	T(test17,
		int		t = 0;

		printf_diff("%+ d", t);
	)

	T(test18,
		int		t = 7894;

		printf_diff("%#d", t);
	)

	T(test19,
		int		t = 7894;

		printf_diff("% d", t);
	)

	T(test20,
		int		t = 7894;

		printf_diff("%-d", t);
	)

	T(test21,
		int		t = 7894;

		printf_diff("%+d", t);
	)

	T(test22,
		int		t = 7894;

		printf_diff("%+ d", t);
	)

	T(test23,
		int		t = 7894;

		printf_diff("%+d", t);
	)

	T(test24,
		int		t = -7894;

		printf_diff("%+d", t);
	)

	T(test25,
		int		t = -7894;

		printf_diff("%d", t);
	)

	T(test26,
		int		t = 0;

		printf_diff("%.0d", t);
	)

	T(test27,
		int		t = 1000;

		printf_compare(UTEST_DIR"/d_test27.ref", "%'d", t);
	)

	T(test28,
		int		t = -1000;

		printf_compare(UTEST_DIR"/d_test28.ref", "%'d", t);
	)

	T(test29,
		int		t = 12;

		printf_compare(UTEST_DIR"/d_test29.ref", "%'d", t);
	)

	T(test30,
		int		t = 12;

		printf_compare(UTEST_DIR"/d_test30.ref", "%'012d", t);
	)

	T(test31,
		int		t = 12;

		printf_compare(UTEST_DIR"/d_test30.ref", "%'.12d", t);
	)

	return (run_test_arr(ac, av));
}
