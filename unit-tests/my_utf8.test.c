//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 100
#include "cmocka/my_macro_overlay.h"


int		main(int ac, char ** av)
{
#define AR_SZ 100

	T(t4D,
		char	*ref;
		ref = (&(char[AR_SZ]){0x4D});
		char	*tst;
		tst = (&(char[AR_SZ]){0});
		wchar_t	in = 0x004D;

		true_utf8seq(in, tst);
		assert_mem_equal(ref, tst, AR_SZ);
	)

	T(t0430,
		char	*ref;
		ref = (&(char[AR_SZ]){0xD0, 0XB0});
		char	*tst;
		tst = (&(char[AR_SZ]){0});
		wchar_t	in = 0x0430;

		true_utf8seq(in, tst);
		assert_mem_equal(ref, tst, AR_SZ);
	)

	T(t4E8C,
		char	*ref
		ref = (&(char[AR_SZ]){0xE4, 0XBA, 0X8C});
		char	*tst;
		tst = (&(char[AR_SZ]){0});
		wchar_t	in = 0x4E8C;

		true_utf8seq(in, tst);
		assert_mem_equal(ref, tst, AR_SZ);
	)

	T(t10302,
		char	*ref
		ref = (&(char[AR_SZ]){0XF0, 0X90, 0X8C, 0X82});
		char	*tst;
		tst = (&(char[AR_SZ]){0});
		wchar_t	in = 0x10302;

		true_utf8seq(in, tst);
		assert_mem_equal(ref, tst, AR_SZ);
	)

#undef AR_SZ
	return (run_test_arr(ac, av));
}
