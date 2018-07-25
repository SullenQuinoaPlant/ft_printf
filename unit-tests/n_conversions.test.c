#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"


int	declare_tests_and_run(int all_of, char *these[])
{
	T(test1,
		int nref;
		int ntst;

		#define CMD "hello this is a string%n"
		printf(CMD, &nref);
		printf(CMD, &ntst);
		#undef CMD 

		assert_int_equal(nref, ntst);
	)

	T(test2,
		int	nref[2];
		int	ntst[2];

		#define CMD "hello this is a string%n%n"
		printf(CMD, &nref[0], &nref[1]);
		printf(CMD, &ntst[0], &ntst[1]);
		#undef CMD 

		assert_memory_equal(nref, ntst, sizeof(nref));
	)

	return(run_test_arr(all_of, these));
}
