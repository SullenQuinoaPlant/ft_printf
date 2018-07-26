#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(test1,
		char	t = 0;

		printf_diff("%hhx", t);
	)

	T(test2,
		short	t = 0;

		printf_diff("%hx", t);
	)

	T(test3,
		int		t = 0;

		printf_diff("%x", t);
	)

	T(test4,
		long int	t = 0;

		printf_diff("%lx", t);
	)

	T(test5,
		long long int	t = 0;

		printf_diff("%llx", t);
	)

	T(test6,
		char	t = 0;

		printf_diff("%hhx", t);
	)

	T(test7,
		short	t = 0;

		printf_diff("%hx", t);
	)

	T(test8,
		int		t = 0;

		printf_diff("%x", t);
	)

	T(test9,
		long int	t = 0;

		printf_diff("%lx", t);
	)

	T(test10,
		long long int	t = 0;

		printf_diff("%llx", t);
	)

	T(test11,
		ssize_t	t = 1234;

		printf_diff("%zx", t);
	)

	T(test12,
		ptrdiff_t	t = 789456;

		printf_diff("%tx", t);
	)

	T(test13,
		int		t = 0;

		printf_diff("%#x", t);
	)

	T(test14,
		int		t = 0;

		printf_diff("% x", t);
	)

	T(test15,
		int		t = 0;

		printf_diff("%-x", t);
	)

	T(test16,
		int		t = 0;

		printf_diff("%+x", t);
	)

	T(test17,
		int		t = 0;

		printf_diff("%+ x", t);
	)

	T(test18,
		int		t = 7894;

		printf_diff("%#x", t);
	)

	T(test19,
		int		t = 7894;

		printf_diff("% x", t);
	)

	T(test20,
		int		t = 7894;

		printf_diff("%-x", t);
	)

	T(test21,
		int		t = 7894;

		printf_diff("%+x", t);
	)

	T(test22,
		int		t = 7894;

		printf_diff("%+ x", t);
	)

	T(test23,
		int		t = 7894;

		printf_diff("%+x", t);
	)

	T(test24,
		int		t = -7894;

		printf_diff("%+x", t);
	)

	T(test25,
		int		t = -7894;

		printf_diff("%x", t);
	)

	T(test26,
		int		t = 0;

		printf_diff("%.0x", t);
	)

	T(test27,
		int		t = 12;

		printf_diff("%012x", t);
	)

	return(run_test_arr(all_of, these));
}
