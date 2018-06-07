//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"


int		main(void)
{
	T(a_few_doubles,
		double	*ds;
		t_s_dfp	*ref;
		size_t	const len = 5;
		t_s_dfp	dds[len];
		size_t	i;

		(ds = (double[]){0.0, 1.0, 2.0, 1.5, 3.0});
		(ref = (t_s_dfp[]){
			{0, 0, 0},
			{0, 0x3ff, 0},
			{0, 0x400, 0},
			{0, 0x3ff, 0x1ull << 51},
			{0, 0x400, 0x1ull << 51}
		});

		for (i = 0; i < len; i++)
		{
			decompose_double(ds + i, &dds[i]);
			assert_memory_equal(&dds[i], ref + i, sizeof(t_s_dfp));
		}
	)

	T(a_few_ldoubles,
		long double	*ds;
		t_s_dfp		*ref;
		size_t		const len = 5;
		t_s_dfp		dds[len];
		size_t		i;

		(ds = (long double[]){0.0L, 1.0L, 2.0L, 1.5L, 3.0L});
		(ref = (t_s_dfp[]){
			{0, 0, 0},
			{0, 0x3fff, 0x1ull << 63},
			{0, 0x4000, 0x1ull << 63},
			{0, 0x3fff, 0x3ull << 62},
			{0, 0x4000, 0x3ull << 62}
		});

		for (i = 0; i < len; i++)
		{
			decompose_ldouble(ds + i, &dds[i]);
			assert_memory_equal(&dds[i], ref + i, sizeof(t_s_dfp));
		}
	)

    return (\
		_cmocka_run_group_tests("TEST_ARR", TEST_ARR,\
					test_index, 0, 0)\
	);
}
