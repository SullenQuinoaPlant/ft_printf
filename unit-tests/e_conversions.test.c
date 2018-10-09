#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(test1,
		double	d;

		d = 0.0;
		printf_diff("%e", d);
	)

	T(test2,
		double	d;

		d = 1.0;
		printf_diff("%e", d);
	)

	T(test3,
		double	d;

		d = 1.0;
		printf_diff("%#e", d);
	)

	T(test4,
		double	d;

		d = 1.0;
		printf_diff("%.0e", d);
	)

	T(test5,
		double	d;

		d = 1.5;
		printf_diff("%.0e", d);
	)

	T(test5_0,
		double	d;

		d = 15;
		printf_diff("%.0e", d);
	)

	T(test5_1,
		double	d;

		for (d = 1.5; d < 120.0; d += 1.0)
		{
			printf("d is : %f\n", d);
			printf_diff("%.0e", d);
		}
	)

	T(test5_1_0,
		double	d;

		d = 16.5;
		printf_diff("%.0e", d);
	)

	T(test5_1_1,
		double	d;

		d = 97.5;
		printf_diff("%.0e", d);
	)

	T(test5_2,
		double	d;

		d = 0.53125;
		printf_diff("%.0e", d);
	)

	T(test5_3,
		double	d;

		d = 1.53125;
		printf_diff("%.0e", d);
	)

	T(test5_4,
		double	d;

		d = 15.53125;
		printf_diff("%.0e", d);
	)

	T(test5_5,
		double	d;

		d = 0.53125;
		printf_diff("%.1e", d);
	)

	T(test5_6,
		double	d;

		d = 1.53125;
		printf_diff("%.1e", d);
	)

	T(test5_7,
		double	d;

		d = 1.4;
		printf_diff("%.0e", d);
	)

	T(test6,
		double	d;

		d = 1.5;
		printf_diff("%e", d);
	)

	T(test7,
		double	d;

		d = 1.5;
		printf_diff("% e", d);
	)

	T(test8,
		double	d;

		d = 1.5;
		printf_diff("%+e", d);
	)

	T(test9,
		double	d;

		d = 1.5;
		printf_diff("%010e", d);
	)

	T(test10,
		double	d;

		d = 1.5;
		printf_diff("%010.10e", d);
	)

	T(test10_0,
g_be_gentle = 1;
		double	d;

		d = 1.5;
		printf_diff("%010,10e", d);
g_be_gentle = 0;
	)

	T(test11,
		double	d;

		d = 1.0;
		printf_diff("%e", d);
	)

	T(test12,
		double	d;

		d = 1.0;
		printf_diff("%010.10e", d);
	)

	T(test13,
		double	d;

		d = 13.13;
		printf_diff("%e", d);
	)

	T(test14,
		double	d;

		d = 13.13;
		printf_diff("%2.2e", d);
	)

	T(test15,
		double	d;

		d = 13.13;
		printf_diff("%-2.2e", d);
	)

	T(test16,
		double	d;

		d = 13.13;
		printf_diff("%*.2e", -2, d);
	)

	T(test17,
		double	d;

		d = 0.0;
		printf_diff("%-2.2e", d);
	)

	T(test18,
		double	d;

		d = 0.0;
		printf_diff("%*.2e", -2, d);
	)

	T(test19,
g_be_gentle = 1;
		double	d;

		d = 0.0;
		printf_diff("%2.*e", -3, d);
g_be_gentle = 0;
	)

	T(test19_0,
g_be_gentle = 1;
		double	d;

		d = 1.456;
		printf_diff("%2.*e", -3, d);
g_be_gentle = 0;
	)

	T(test19_1,
g_be_gentle = 1;
		double	d;

		d = 1.456;
		printf_diff("%2.-3e", d);
g_be_gentle = 0;
	)

	T(test20,
g_be_gentle = 1;
		double	d;

		d = 1234.1234;
		printf_diff("%.*e", -2, d);
g_be_gentle = 0;
	)

	T(test21,
		double	d;

		d = 1234.1234;
		printf_diff("%.*e", 3, d);
	)

	T(test22,
		double	d;

		d = 1234.1234;
		printf_diff("%.*e", 13, d);
	)

	T(test23,
		double	d;

		d = 2.0;
		printf_diff("%e", d);
		printf_diff("%0e", d);
		printf_diff("%1e", d);
		printf_diff("%30e", d);
	)

	T(test24,
		double	d;

		d = 2.0;
		printf_diff("%.e", d);
		printf_diff("%0.e", d);
		printf_diff("%1.e", d);
		printf_diff("%30.e", d);
	)

	T(test25,
		double	d;

		d = 2.0;
		printf_diff("%.0e", d);
		printf_diff("%0.0e", d);
		printf_diff("%1.0e", d);
		printf_diff("%30.0e", d);
	)

	T(test26,
		double	d;

		d = 2.0;
		printf_diff("%.6e", d);
		printf_diff("%0.6e", d);
		printf_diff("%1.6e", d);
		printf_diff("%30.6e", d);
	)

	T(test27,
		double	d;

		d = 2.0;
		printf_diff("%.*e", 0, d);
		printf_diff("%0.*e", 0, d);
		printf_diff("%1.*e", 0, d);
		printf_diff("%30.*e", 0, d);
	)

	T(test28,
		double	d;

		d = 2.0;
		printf_diff("%.*e", 13, d);
		printf_diff("%0.*e", 13, d);
		printf_diff("%1.*e", 13, d);
		printf_diff("%30.*e", 13, d);
	)

	T(test29,
		double	d;

		d = 2.0;
		printf_diff("%2$.*1$e", 13, d);
		printf_diff("%02$.*1$e", 13, d);
	)

	T(test29_0,
g_be_gentle = 1;
		double	d;

		d = 2.0;
		printf_diff("%12$.*1$e", 13, d);
		printf_diff("%302$.*1$e", 13, d);
g_be_gentle = 0;
	)

	T(text_double_text,
		double	d;

		d = 2.0;
		printf_diff("text_%2$.*1$e_text", 13, d);
	)

	return(run_test_arr(all_of, these));
}
