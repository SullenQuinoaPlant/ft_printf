#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(test1,
		double	d;

		d = 0.0;
		printf_diff("%f", d);
	)

	T(test2,
		double	d;

		d = 1.0;
		printf_diff("%f", d);
	)

	T(test3,
		double	d;

		d = 1.0;
		printf_diff("%#f", d);
	)

	T(test4,
		double	d;

		d = 1.0;
		printf_diff("%.0f", d);
	)

	T(test5,
		double	d;

		d = 1.5;
		printf_diff("%.0f", d);
	)

	T(test5_0,
		double	d;

		d = 15;
		printf_diff("%.0f", d);
	)

g_be_gentle = 1;
	T(test5_1,
//they round both 1.5 and 2.5 to 2.0 I don't get it, I don't like it.
		double	d;

		for (d = 1.5; d < 120.0; d += 1.0)
		{
			printf("d is : %f\n", d);
			printf_diff("%.0f", d);
		}
	)
g_be_gentle = 0;

g_be_gentle = 1;
	T(test5_1_0,
		double	d;

		d = 16.5;
		printf_diff("%.0f", d);
	)
g_be_gentle = 0;

	T(test5_2,
		double	d;

		d = 0.53125;
		printf_diff("%.0f", d);
	)

	T(test5_3,
		double	d;

		d = 1.53125;
		printf_diff("%.0f", d);
	)

	T(test5_4,
		double	d;

		d = 15.53125;
		printf_diff("%.0f", d);
	)

	T(test5_5,
		double	d;

		d = 0.53125;
		printf_diff("%.1f", d);
	)

	T(test5_6,
		double	d;

		d = 1.53125;
		printf_diff("%.1f", d);
	)

	T(test5_7,
		double	d;

		d = 1.4;
		printf_diff("%.0f", d);
	)

	T(test6,
		double	d;

		d = 1.5;
		printf_diff("%f", d);
	)

	T(test7,
		double	d;

		d = 1.5;
		printf_diff("% f", d);
	)

	T(test8,
		double	d;

		d = 1.5;
		printf_diff("%+f", d);
	)

	T(test9,
		double	d;

		d = 1.5;
		printf_diff("%010f", d);
	)

	T(test10,
		double	d;

		d = 1.5;
		printf_diff("%010.10f", d);
	)

g_be_gentle = 1;
	T(test10_0,
		double	d;

		d = 1.5;
		printf_diff("%010,10f", d);
	)
g_be_gentle = 0;

	T(test11,
		double	d;

		d = 1.0;
		printf_diff("%f", d);
	)

	T(test12,
		double	d;

		d = 1.0;
		printf_diff("%010.10f", d);
	)

	T(test13,
		double	d;

		d = 13.13;
		printf_diff("%f", d);
	)

	T(test14,
		double	d;

		d = 13.13;
		printf_diff("%2.2f", d);
	)

	T(test15,
		double	d;

		d = 13.13;
		printf_diff("%-2.2f", d);
	)

	T(test16,
		double	d;

		d = 13.13;
		printf_diff("%*.2f", -2, d);
	)

	T(test17,
		double	d;

		d = 0.0;
		printf_diff("%-2.2f", d);
	)

	T(test18,
		double	d;

		d = 0.0;
		printf_diff("%*.2f", -2, d);
	)

g_be_gentle = 1;
	T(test19,
		double	d;

		d = 0.0;
		printf_diff("%2.*f", -3, d);
	)
g_be_gentle = 0;

g_be_gentle = 1;
	T(test19_0,
		double	d;

		d = 1.456;
		printf_diff("%2.*f", -3, d);
	)
g_be_gentle = 0;

g_be_gentle = 1;
	T(test19_1,
		double	d;

		d = 1.456;
		printf_diff("%2.-3f", d);
	)
g_be_gentle = 0;

g_be_gentle = 1;
	T(test20,
		double	d;

		d = 1234.1234;
		printf_diff("%.*f", -2, d);
	)
g_be_gentle = 0;

	T(test21,
		double	d;

		d = 1234.1234;
		printf_diff("%.*f", 3, d);
	)

	g_be_gentle = 1;
	T(test22,
		double	d;

		d = 1234.1234;
		printf_diff("%.*f", 13, d);
	)
g_be_gentle = 0;

	T(test23,
		double	d;

		d = 2.0;
		printf_diff("%f", d);
		printf_diff("%0f", d);
		printf_diff("%1f", d);
		printf_diff("%30f", d);
	)

	T(test24,
		double	d;

		d = 2.0;
		printf_diff("%.f", d);
		printf_diff("%0.f", d);
		printf_diff("%1.f", d);
		printf_diff("%30.f", d);
	)

	T(test25,
		double	d;

		d = 2.0;
		printf_diff("%.0f", d);
		printf_diff("%0.0f", d);
		printf_diff("%1.0f", d);
		printf_diff("%30.0f", d);
	)

	T(test26,
		double	d;

		d = 2.0;
		printf_diff("%.6f", d);
		printf_diff("%0.6f", d);
		printf_diff("%1.6f", d);
		printf_diff("%30.6f", d);
	)

	T(test27,
		double	d;

		d = 2.0;
		printf_diff("%.*f", 0, d);
		printf_diff("%0.*f", 0, d);
		printf_diff("%1.*f", 0, d);
		printf_diff("%30.*f", 0, d);
	)

	T(test28,
		double	d;

		d = 2.0;
		printf_diff("%.*f", 13, d);
		printf_diff("%0.*f", 13, d);
		printf_diff("%1.*f", 13, d);
		printf_diff("%30.*f", 13, d);
	)

	T(test29,
		double	d;

		d = 2.0;
		printf_diff("%2$.*1$f", 13, d);
		printf_diff("%02$.*1$f", 13, d);
	)

g_be_gentle = 1;
	T(test29_0,
		double	d;

		d = 2.0;
		printf_diff("%12$.*1$f", 13, d);
		printf_diff("%302$.*1$f", 13, d);
	)
g_be_gentle = 0;

	T(test30,
		double	d;

		d = 0.000001234;
		printf_diff("%f", d);
	)

	T(text_double_text,
		double	d;

		d = 2.0;
		printf_diff("text_%2$.*1$f_text", 13, d);
	)

	return(run_test_arr(all_of, these));
}
