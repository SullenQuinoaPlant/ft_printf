#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(test1,
		double	d;

		d = 0.0;
		printf_diff("%g", d);
	)

	T(test2,
		double	d;

		d = 1.0;
		printf_diff("%g", d);
	)

	T(test3,
		double	d;

		d = 1.0;
		printf_diff("%#g", d);
	)

	T(test4,
		double	d;

		d = 1.0;
		printf_diff("%.0g", d);
	)

	T(test5,
		double	d;

		d = 0.5;
		printf_diff("%.0g", d);
	)

	T(test5_0,
		double	d;

		d = 15;
		printf_diff("%.0g", d);
	)

	T(test5_1,
g_be_gentle = 1;
//gnu rounds both 1.5 and 2.5 to 2.0 I don't get it, I don't like it.
		double	d;

		for (d = 0.5; d < 120.0; d += 1.0)
		{
			printf("d is : %f\n", d);
			printf_diff("%.0g", d);
		}
g_be_gentle = 0;
	)

	T(test5_1_0,
g_be_gentle = 1;
		double	d;

		d = 16.5;
		printf_diff("%.0g", d);
g_be_gentle = 0;
	)

	T(test5_1_1,
g_be_gentle = 1;
		double	d;

		d = 97.5;
		printf_diff("%.0g", d);
g_be_gentle = 0;
	)

	T(test5_2,
		double	d;

		d = 0.53125;
		printf_diff("%.0g", d);
	)

	T(test5_3,
		double	d;

		d = 1.53125;
		printf_diff("%.0g", d);
	)

	T(test5_3_0,
		double	d;

		d = 95.5;
		printf_diff("%.0g", d);
	)

	T(test5_4,
		double	d;

		d = 15.53125;
		printf_diff("%.0g", d);
	)

	T(test5_5,
		double	d;

		d = 0.53125;
		printf_diff("%.1g", d);
	)

	T(test5_6,
		double	d;

		d = 1.53125;
		printf_diff("%.1g", d);
	)

	T(test5_7,
		double	d;
		int		i;

		d = 1.4;
		i = -1;
		while (++i < 20)
		{
			printf_diff("%.0g", d);
			d += 1.0;
		}
	)

	T(test5_8,
g_be_gentle = 1;
		double	d;
		int		i;

		d = 0;
		i = -1;
		while (++i < 50)
		{
			printf("d is : %f, %%g is : %.0g\n", d, d);
			printf_diff("%.0g", d);
			d += 0.1;
		}
g_be_gentle = 0;
	)

	T(test5_9,
g_be_gentle = 1;
		double	d;
		int		i;

		d = 0;
		i = -1;
		while (++i < 50)
		{
			printf("d is : %f, %%g is : %.0g\n", d, d);
			printf_diff("%.0g", d);
			d += 0.5;
		}
g_be_gentle = 0;
	)

	T(test6,
		double	d;

		d = 1.5;
		printf_diff("%g", d);
	)

	T(test7,
		double	d;

		d = 1.5;
		printf_diff("% g", d);
	)

	T(test8,
		double	d;

		d = 1.5;
		printf_diff("%+g", d);
	)

	T(test9,
		double	d;

		d = 1.5;
		printf_diff("%010g", d);
	)

	T(test10,
		double	d;

		d = 1.5;
		printf_diff("%010.10g", d);
	)

	T(test10_0,
g_be_gentle = 1;
		double	d;

		d = 1.5;
		printf_diff("%010,10g", d);
g_be_gentle = 0;
	)

	T(test11,
		double	d;

		d = 1.0;
		printf_diff("%g", d);
	)

	T(test12,
		double	d;

		d = 1.0;
		printf_diff("%010.10g", d);
	)

	T(test13,
		double	d;

		d = 13.13;
		printf_diff("%g", d);
	)

	T(test14,
		double	d;

		d = 13.13;
		printf_diff("%2.2g", d);
	)

	T(test15,
		double	d;

		d = 13.13;
		printf_diff("%-2.2g", d);
	)

	T(test16,
		double	d;

		d = 13.13;
		printf_diff("%*.2g", -2, d);
	)

	T(test17,
		double	d;

		d = 0.0;
		printf_diff("%-2.2g", d);
	)

	T(test18,
		double	d;

		d = 0.0;
		printf_diff("%*.2g", -2, d);
	)

	T(test19,
g_be_gentle = 1;
		double	d;

		d = 0.0;
		printf_diff("%2.*g", -3, d);
g_be_gentle = 0;
	)

	T(test19_0,
g_be_gentle = 1;
		double	d;

		d = 1.456;
		printf_diff("%2.*g", -3, d);
g_be_gentle = 0;
	)

	T(test19_1,
g_be_gentle = 1;
		double	d;

		d = 1.456;
		printf_diff("%2.-3g", d);
g_be_gentle = 0;
	)

	T(test20,
g_be_gentle = 1;
		double	d;

		d = 1234.1234;
		printf_diff("%.*g", -2, d);
g_be_gentle = 0;
	)

	T(test21,
		double	d;

		d = 1234.1234;
		printf_diff("%.*g", 3, d);
	)

	T(test22,
g_be_gentle = 1;
		double	d;

		d = 1234.1234;
		printf_diff("%.*g", 13, d);
g_be_gentle = 0;
	)

	T(test23,
		double	d;

		d = 2.0;
		printf_diff("%g", d);
		printf_diff("%0g", d);
		printf_diff("%1g", d);
		printf_diff("%30g", d);
	)

	T(test24,
		double	d;

		d = 2.0;
		printf_diff("%.g", d);
		printf_diff("%0.g", d);
		printf_diff("%1.g", d);
		printf_diff("%30.g", d);
	)

	T(test25,
		double	d;

		d = 2.0;
		printf_diff("%.0g", d);
		printf_diff("%0.0g", d);
		printf_diff("%1.0g", d);
		printf_diff("%30.0g", d);
	)

	T(test26,
		double	d;

		d = 2.0;
		printf_diff("%.6g", d);
		printf_diff("%0.6g", d);
		printf_diff("%1.6g", d);
		printf_diff("%30.6g", d);
	)

	T(test27,
		double	d;

		d = 2.0;
		printf_diff("%.*g", 0, d);
		printf_diff("%0.*g", 0, d);
		printf_diff("%1.*g", 0, d);
		printf_diff("%30.*g", 0, d);
	)

	T(test28,
		double	d;

		d = 2.0;
		printf_diff("%.*g", 13, d);
		printf_diff("%0.*g", 13, d);
		printf_diff("%1.*g", 13, d);
		printf_diff("%30.*g", 13, d);
	)

	T(test29,
		double	d;

		d = 2.0;
		printf_diff("%2$.*1$g", 13, d);
		printf_diff("%02$.*1$g", 13, d);
	)

	T(test29_0,
g_be_gentle = 1;
		double	d;

		d = 2.0;
		printf_diff("%12$.*1$g", 13, d);
		printf_diff("%302$.*1$g", 13, d);
g_be_gentle = 0;
	)

	T(test30,
		double	d;

		d = 0.000001234;
		printf_diff("%g", d);
	)

	T(text_double_text,
		double	d;

		d = 2.0;
		printf_diff("text_%2$.*1$g_text", 13, d);
	)

	return(run_test_arr(all_of, these));
}
