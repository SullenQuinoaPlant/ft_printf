#define HOW_MANY_TESTS 100
#include "cmocka/my_macro_overlay.h"

#include "printf_diff.c"

int		main(void)
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
		printf_diff("%a", d);
	)

	T(test13,
		double	d;

		d = 1.0;
		printf_diff("%a", d);
	)

	T(test14,
		double	d;

		d = 1.0;
		printf_diff("%a", d);
	)

    return (
		_cmocka_run_group_tests(
			"TEST_ARR", TEST_ARR,
			test_index, 0, 0)
	);
}
