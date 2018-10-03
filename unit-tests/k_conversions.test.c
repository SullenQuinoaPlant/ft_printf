#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include <time.h>
#include "printf_diff.c"


int	declare_tests_and_run(int all_of, char *these[])
{
	struct tm	dec_time;

	localtime_r(time(0), &dec_time);

	T(zerozerozero,
		struct tm	dummy;

		dummy = dec_time;
		dummy.tm_sec = 0;
		dummy.tm_min = 0;
		dummy.tm_hour = 0;

		printf_compare("k_zerozerozero.ref",
			"%k\n", 
			&dummy);
	)

	T(zerozerozero_hash,
		struct tm	dummy;

		dummy = dec_time;
		dummy.tm_sec = 0;
		dummy.tm_min = 0;
		dummy.tm_hour = 0;

		printf_compare("k_zerozerozero_hash.ref",
			"%#k\n", 
			&dummy);
	)

	T(onetwothree,
		struct tm	dummy;

		dummy = dec_time;
		dummy.tm_sec = 3;
		dummy.tm_min = 2;
		dummy.tm_hour = 1;

		printf_compare("k_onetwothree.ref",
			"%k\n", 
			&dummy);
	)

	T(onetwothree_hash,
		struct tm	dummy;

		dummy = dec_time;
		dummy.tm_sec = 3;
		dummy.tm_min = 2;
		dummy.tm_hour = 1;

		printf_compare("k_onetwothree_hash.ref",
			"%#k\n", 
			&dummy);
	)

	T(this_is_boring,
		struct tm	dummy;

		dummy = dec_time;
		dummy.tm_sec = 13;
		dummy.tm_min = 24;
		dummy.tm_hour = 11;

		printf_compare("k_this_is_boring.ref",
			"%k\n", 
			&dummy);
	)

	return (run_test_arr(all_of, these));
}
