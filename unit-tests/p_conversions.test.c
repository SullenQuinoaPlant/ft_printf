#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(test1,
		char	t = 0;

		printf_diff("%hhp", t);
	)

	T(test2,
		short	t = 0;

		printf_diff("%hp", t);
	)

	T(test3,
		int		t = 0;

		printf_diff("%p", t);
	)

	T(test4,
		long int	t = 0;

		printf_diff("%lp", t);
	)

	T(test5,
		long long int	t = 0;

		printf_diff("%llp", t);
	)

	T(test6,
		char	t = 0;

		printf_diff("%hhp", t);
	)

	T(test7,
		short	t = 0;

		printf_diff("%hp", t);
	)

	T(test8,
		int		t = 0;

		printf_diff("%p", t);
	)

	T(test9,
		long int	t = 0;

		printf_diff("%lp", t);
	)

	T(test10,
		long long int	t = 0;

		printf_diff("%llp", t);
	)

	T(test11,
		ssize_t	t = 1234;

		printf_diff("%zp", t);
	)

	T(test12,
		ptrdiff_t	t = 789456;

		printf_diff("%tp", t);
	)

	T(test13,
		int		t = 0;

		printf_diff("%#p", t);
	)

	T(test14,
		int		t = 0;

		printf_diff("% p", t);
	)

	T(test15,
		int		t = 0;

		printf_diff("%-p", t);
	)

	T(test16,
		int		t = 0;

		printf_diff("%+p", t);
	)

	T(test17,
		int		t = 0;

		printf_diff("%+ p", t);
	)

	T(test18,
		int		t = 7894;

		printf_diff("%#p", t);
	)

	T(test19,
		int		t = 7894;

		printf_diff("% p", t);
	)

	T(test20,
		int		t = 7894;

		printf_diff("%-p", t);
	)

	T(test21,
		int		t = 7894;

		printf_diff("%+p", t);
	)

	T(test22,
		int		t = 7894;

		printf_diff("%+ p", t);
	)

	T(test23,
		int		t = 7894;

		printf_diff("%+p", t);
	)

	T(test24,
		int		t = -7894;

		printf_diff("%+p", t);
	)

	T(test25,
		int		t = -7894;

		printf_diff("%p", t);
	)

	T(test26,
		int		t = 0;

		printf_diff("%.0p", t);
	)

	T(test27,
		int		t = 12;

		printf_diff("%012p", t);
	)

	T(test28,
		int		t = 0;

		printf_diff("%012p", t);
	)

	T(test29,
		int		t = 0;

		printf_diff("%12p", t);
	)

	return(run_test_arr(all_of, these));
}
