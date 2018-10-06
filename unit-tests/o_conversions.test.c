#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(test1,
		char	t = 0;

		printf_diff("%hho", t);
	)

	T(test2,
		short	t = 0;

		printf_diff("%ho", t);
	)

	T(test3,
		int		t = 0;

		printf_diff("%o", t);
	)

	T(test4,
		long int	t = 0;

		printf_diff("%lo", t);
	)

	T(test5,
		long long int	t = 0;

		printf_diff("%llo", t);
	)

	T(test6,
		char	t = 0;

		printf_diff("%hho", t);
	)

	T(test7,
		short	t = 0;

		printf_diff("%ho", t);
	)

	T(test8,
		int		t = 0;

		printf_diff("%o", t);
	)

	T(test9,
		long int	t = 0;

		printf_diff("%lo", t);
	)

	T(test10,
		long long int	t = 0;

		printf_diff("%llo", t);
	)

	T(test11,
		ssize_t	t = 1234;

		printf_diff("%zo", t);
	)

	T(test12,
		ptrdiff_t	t = 789456;

		printf_diff("%to", t);
	)

	T(test13,
		int		t = 0;

		printf_diff("%#o", t);
	)

	T(test14,
		int		t = 0;

		printf_diff("% o", t);
	)

	T(test15,
		int		t = 0;

		printf_diff("%-o", t);
	)

	T(test16,
		int		t = 0;

		printf_diff("%+o", t);
	)

	T(test17,
		int		t = 0;

		printf_diff("%+ o", t);
	)

	T(test18,
		int		t = 7894;

		printf_diff("%#o", t);
	)

	T(test19,
		int		t = 7894;

		printf_diff("% o", t);
	)

	T(test20,
		int		t = 7894;

		printf_diff("%-o", t);
	)

	T(test21,
		int		t = 7894;

		printf_diff("%+o", t);
	)

	T(test22,
		int		t = 7894;

		printf_diff("%+ o", t);
	)

	T(test23,
		int		t = 7894;

		printf_diff("%+o", t);
	)

	T(test24,
		int		t = -7894;

		printf_diff("%+o", t);
	)

	T(test25,
		int		t = -7894;

		printf_diff("%o", t);
	)

	T(test26,
		int		t = 0;

		printf_diff("%.0o", t);
	)

g_be_gentle = 1;
	T(test27,
		int		t = 1000;

		printf_compare("o_test27.ref", "%'o\n", t);
	)
g_be_gentle = 0;

g_be_gentle = 1;
	T(test28,
		int		t = -1000;

		if (sizeof(int) != 4)
			skip();
		else
			printf_compare("o_test28.ref", "%'o\n", t);
	)
g_be_gentle = 0;

g_be_gentle = 1;
	T(test29,
		int		t = 12;

		printf_compare("o_test29.ref", "%'o\n", t);
	)
g_be_gentle = 0;

g_be_gentle = 1;
	T(test30,
		int		t = 12;

		printf_compare("o_test30.ref", "%'012o\n", t);
	g_be_gentle = 1;
	)

	g_be_gentle = 1;
	T(test31,
		int		t = 12;

		printf_compare("o_test31.ref", "%'.12o\n", t);
	)
g_be_gentle = 0;

g_be_gentle = 1;
	T(test32,
		int		t = 12;

		printf_diff("%012o", t);
	)
g_be_gentle = 0;

	return(run_test_arr(all_of, these));
}
