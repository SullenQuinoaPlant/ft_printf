#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

/*
#include "libftprintf.h"
int	main()
{
	double	d1;
	d1 = 0.0;
	ft_printf("%a", d1);
	return (0);
}
*/

//*
#include "printf_diff.c"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(test1,
		double	d;

		d = 0.0L;
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
g_be_gentle = 1;
		double	d;

		d = 1.5;
		//printf("d is : %f\n", d);
		printf_diff("%.0a", d);
		d = 1.51;
		//printf("d is : %f\n", d);
		printf_diff("%.0a", d);
		d = 1.6;
		//printf("d is : %f\n", d);
		printf_diff("%.0a", d);
g_be_gentle = 0;
	)

	T(test5_00,
		double	d;

		d = 2.5;
		printf_diff("%.0a", d);
	)

	T(test5_0,
		double	d;

		d = 15;
		printf_diff("%.0a", d);
	)

	T(test5_1,
g_be_gentle = 1;
		double	d;

		for (d = 1.5; d < 120.0; d += 1.0)
		{
			//printf("d is : %f\n", d);
			printf_diff("%.0a", d);
		}
g_be_gentle = 0;
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
g_be_gentle = 1;
		double	d;

		d = 1.53125;
		printf_diff("%.0a", d);
g_be_gentle = 0;
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
g_be_gentle = 1;
		double	d;

		d = 1.5;
		printf_diff("%010,10a", d);
g_be_gentle = 0;
	)

	T(test10_0,
		double	d;

		d = 1.5;
		printf_diff("%010.10a", d);
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

	T(test19_00,
		double	d;

		d = 1.456;
		printf_diff("%2a", d);
	)

	T(test19_0,
g_be_gentle = 1;
		double	d;

		d = 1.456;
		printf_diff("%2.*a", -3, d);
g_be_gentle = 0;
	)

	T(test19_1,
g_be_gentle = 1;
		double	d;

		d = 1.456;
		printf_diff("%2.-3a", d);
g_be_gentle = 0;
	)

	T(test20,
g_be_gentle = 1;
		double	d;

		d = 1234.1234;
		printf_diff("%.*a", -2, d);
g_be_gentle = 0;
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
g_be_gentle = 1;
		double	d;

		d = 2.0;
		printf_diff("%12$.*1$a", 13, d);
		printf_diff("%302$.*1$a", 13, d);
g_be_gentle = 0;
	)

	T(text_double_text,
		double	d;

		d = 2.0;
		printf_diff("text_%2$.*1$a_text", 13, d);
	)

	T(test30,
		double	d;

		d = 0.8;
		printf_diff("%a", d);
	)

	T(test31,
		double	d;

		d = 0.88;
		printf_diff("%a", d);
	)

	T(test32,
		double	d;

		for (d = 1.5; d < 120.0; d += 1.0)
		{
			//printf("d is : %f\n", d);
			printf_diff("%.2a", d);
		}
	)

	T(test32_0,
		double	d;

		d = 1.5;
		//printf("d is : %f\n", d);
		ft_printf("ftprintf gives: %.2a\n", d);
		//printf("printf gives: %.2a\n", d);
		printf_diff("%.2a", d);
	)


	T(test33,
g_be_gentle = 1;
		double	d;

		for (d = 1.5789456; d < 10.0; d += 0.1)
		{
			//printf("d is : %f\t%a\n", d, d);
			printf_diff("%.2a", d);
		}
g_be_gentle = 0;
	)

	T(test33_0,
g_be_gentle = 1;
		double	d;

		d = 2.378946;
		//printf("d is : %f\t%a\n", d, d);
		printf_diff("%.2a", d);
g_be_gentle = 0;
	)

	T(test33_b0,
g_be_gentle = 1;
		double	d;

		d = 2.378946;
		//printf("d is : %f\t%A\n", d, d);
		printf_diff("%.2a", d);
g_be_gentle = 0;
	)

	T(test33_1,
		double	d;

		d = 8.078946;
		//printf("d is : %f\t%a\n", d, d);
		printf_diff("%.2a", d);
	)

	T(test33_b1,
		double	d;

		d = 8.078946;
		//printf("d is : %f\t%A\n", d, d);
		printf_diff("%.2a", d);
	)

	T(test34,
		double	d;

		d = 1.6;
		printf_diff("%.0a", d);
	)

	T(test35,
		double	d;

		for (d = 1.05; d < 3.0; d += 0.1)
		{
			//printf("d is : %f\n", d);
			printf_diff("%.2a", d);
		}
	)

	T(test36,
		double	d;

		for (d = 1.05; d < 3.0; d += 0.1)
		{
			//printf("d is : %.1f\n", d);
			printf_diff("%.2a", d);
		}
	)

	T(test37,
		double	d;

		for (d = 1.05; d < 3.0; d += 0.1)
		{
			//printf("d is : %.2f\n", d);
			printf_diff("%.2a", d);
		}
	)

	T(test38,
		double	d;

		for (d = 0x0.01231p0; d < 10.0; d += 0x0.1p0)
		{
			//printf("d is : %f\t%a\n", d, d);
			printf_diff("%.2a", d);
		}
	)

	T(test39,
g_be_gentle = 1;
		double	d;

		for (d = 0x0.01231p0; d < 100.0; d += 0x0.101p0)
		{
			//printf("d is : %f\t%a\n", d, d);
			printf_diff("%.3a", d);
		}
g_be_gentle = 0;
	)

	T(test39_0,
g_be_gentle = 1;
		double	d;

		d = 0x1.0a188p-3;
		//printf("d is : %f\t%a\n", d, d);
		printf_diff("%.3a", d);
g_be_gentle = 0;
	)

	return(run_test_arr(all_of, these));
}
//*/
/*Skipped tests where printf displays crazy behavior in contradiction with the man page I've read.*/
/*Might even decide to revert the accomodations made forthe default rounding behavior.*/
