#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

void	test_declarations()
{
	T(nop,
		assert_true(1);
	)
}
