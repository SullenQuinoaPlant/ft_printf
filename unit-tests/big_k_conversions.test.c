#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include <time.h>
#include "printf_diff.c"


int	declare_tests_and_run(int all_of, char *these[])
{
	time_t		time;
	struct tm	dec_time;

	time = time(0);
	localtime_r(time, &dec_time);

	T(date0,
		struct tm	dummy;

		dummy = dec_time;
		dummy.tm_mday = 12;
		dummy.tm_month = 6;
		dummy.tm_year = 100;
		dummy.tm_wday = 5;

		printf_compare("bk_date0.ref",
			"%K\n", 
			&dummy);
	)

	T(date0_hash,
		struct tm	dummy;

		dummy = dec_time;
		dummy.tm_mday = 12;
		dummy.tm_month = 6;
		dummy.tm_year = 100;
		dummy.tm_wday = 5;

		printf_compare("bk_date0_hash.ref",
			"%#K\n", 
			&dummy);
	)

	return (run_test_arr(all_of, these));
}
