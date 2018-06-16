#define HOW_MANY_TESTS 100
#include "cmocka/my_macro_overlay.h"

#include "printf_diff.c"

int		main(int ac, char** av)
{
	T(test1,
		double	d;

		d = 0.0;
		printf_diff("%a", d);
	)

	T(test2,
		double	d;

		d = 1.0;
		printf_diff("%a", d);
	)

	T(test3,
		double	d;

		d = 1.0;
		printf_diff("%#a", d);
	)

	T(test4,
		double	d;

		d = 1.0;
		printf_diff("%.0a", d);
	)

	T(test5,
		double	d;

		d = 1.5;
		printf_diff("%.0a", d);
	)

	T(test6,
		double	d;

		d = 1.5;
		printf_diff("%a", d);
	)

	T(test7,
		double	d;

		d = 1.5;
		printf_diff("% a", d);
	)

	T(test8,
		double	d;

		d = 1.5;
		printf_diff("%+a", d);
	)

	T(test9,
		double	d;

		d = 1.5;
		printf_diff("%010a", d);
	)

	T(test10,
		double	d;

		d = 1.5;
		printf_diff("%010,10a", d);
	)

	T(test11,
		double	d;

		d = 1.0;
		printf_diff("%a", d);
	)

	T(test12,
		double	d;

		d = 1.0;
		printf_diff("%010.10a", d);
	)

	T(test13,
		double	d;

		d = 13.13;
		printf_diff("%a", d);
	)

	T(test14,
		double	d;

		d = 13.13;
		printf_diff("%2.2a", d);
	)

	T(test15,
		double	d;

		d = 13.13;
		printf_diff("%-2.2a", d);
	)

	T(test16,
		double	d;

		d = 13.13;
		printf_diff("%*.2a", -2, d);
	)

	T(test17,
		double	d;

		d = 0.0;
		printf_diff("%-2.2a", d);
	)

	T(test18,
		double	d;

		d = 0.0;
		printf_diff("%*.2a", -2, d);
	)

	T(test19,
		double	d;

		d = 0.0;
		printf_diff("%2.*a", -3, d);
	)

	T(test20,
		double	d;

		d = 1234.1234;
		printf_diff("%.*a", -2, d);
	)

	T(test21,
		double	d;

		d = 1234.1234;
		printf_diff("%.*a", 3, d);
	)

	T(test22,
		double	d;

		d = 1234.1234;
		printf_diff("%.*a", 13, d);
	)

	return (run_test_arr(ac, av));
}
