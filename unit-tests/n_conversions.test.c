#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"


int	declare_tests_and_run(int all_of, char *these[])
{
	T(test1,
		int nref, ntst;

		#define CMD hello this is a string%n
		printf("CMD", &nref);
		printf("CMD", &ntst);
		#undef CMD 

		assert_int_equal(nref, ntst);
	)

	T(test2,
		int nref1, nref2, ntst1, ntst2;

		#define CMD hello this is a string%n%n
		printf("CMD", &nref1, &nref2);
		printf("CMD", &ntst1, &ntst2);
		#undef CMD 

		assert_int_equal(nref1, ntst1);
		assert_int_equal(nref2, ntst2);
	)

	return(run_test_arr(all_of, these));
}
