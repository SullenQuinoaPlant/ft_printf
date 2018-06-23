#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "printf_diff.c"

void	test_declarations()
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

	T(test5_0,
		double	d;

		d = 15;
		printf_diff("%.0a", d);
	)

	T(test5_1,
		double	d;

		for (d = 1.5; d < 120.0; d += 1.0)
		{
			printf("d is : %f\n", d);
			printf_diff("%.0a", d);
		}
	)

	T(test5_1_0,
		double	d;

		d = 16.5;
		printf_diff("%.0a", d);
	)

	T(test5_2,
		double	d;

		d = 0.53125;
		printf_diff("%.0a", d);
	)

	T(test5_3,
		double	d;

		d = 1.53125;
		printf_diff("%.0a", d);
	)

	T(test5_4,
		double	d;

		d = 15.53125;
		printf_diff("%.0a", d);
	)

	T(test5_5,
		double	d;

		d = 0.53125;
		printf_diff("%.1a", d);
	)

	T(test5_6,
		double	d;

		d = 1.53125;
		printf_diff("%.1a", d);
	)

	T(test5_7,
		double	d;

		d = 1.4;
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

	T(test19_0,
skip();
		double	d;

		d = 1.456;
		printf_diff("%2.*a", -3, d);
	)

	T(test19_1,
skip();
		double	d;

		d = 1.456;
		printf_diff("%2.-3a", d);
	)

	T(test20,
skip();
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

	T(test23,
		double	d;

		d = 2.0;
		printf_diff("%a", d);
		printf_diff("%0a", d);
		printf_diff("%1a", d);
		printf_diff("%30a", d);
	)

	T(test24,
		double	d;

		d = 2.0;
		printf_diff("%.a", d);
		printf_diff("%0.a", d);
		printf_diff("%1.a", d);
		printf_diff("%30.a", d);
	)

	T(test25,
		double	d;

		d = 2.0;
		printf_diff("%.0a", d);
		printf_diff("%0.0a", d);
		printf_diff("%1.0a", d);
		printf_diff("%30.0a", d);
	)

	T(test26,
		double	d;

		d = 2.0;
		printf_diff("%.6a", d);
		printf_diff("%0.6a", d);
		printf_diff("%1.6a", d);
		printf_diff("%30.6a", d);
	)

	T(test27,
		double	d;

		d = 2.0;
		printf_diff("%.*a", 0, d);
		printf_diff("%0.*a", 0, d);
		printf_diff("%1.*a", 0, d);
		printf_diff("%30.*a", 0, d);
	)

	T(test28,
		double	d;

		d = 2.0;
		printf_diff("%.*a", 13, d);
		printf_diff("%0.*a", 13, d);
		printf_diff("%1.*a", 13, d);
		printf_diff("%30.*a", 13, d);
	)

	T(test29,
		double	d;

		d = 2.0;
		printf_diff("%2$.*1$a", 13, d);
		printf_diff("%02$.*1$a", 13, d);
	)

	T(test29_0,
skip();
		double	d;

		d = 2.0;
		printf_diff("%12$.*1$a", 13, d);
		printf_diff("%302$.*1$a", 13, d);
	)

	T(text_double_text,
		double	d;

		d = 2.0;
		printf_diff("text_%2$.*1$a_text", 13, d);
	)

/*Skipped tests where printf displays crazy behavior in contradiction with the man page I've read.*/
/*Might even decide to revert the accomodations made forthe default rounding behavior.*/
}
