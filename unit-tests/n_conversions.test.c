#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"
#include "libftprintf.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	#define CMD "hello this is a string%n"
	T(test1,
		int nref;
		int ntst;

		printf(CMD, &nref);
		ntst = 42;
		ft_printf(CMD, &ntst);

		assert_int_equal(nref, ntst);
	)
	#undef CMD 

	#define CMD "hello this is a string%n%n"
	T(test2,
		int	nref[2];
		int	ntst[2];

		printf(CMD, &nref[0], &nref[1]);
		ft_printf(CMD, &ntst[0], &ntst[1]);

		assert_memory_equal(nref, ntst, sizeof(nref));
	)
	#undef CMD 

	return(run_test_arr(all_of, these));
}
