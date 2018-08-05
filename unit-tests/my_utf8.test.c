#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "libmystupidmath.h"

#define AR_SZ 100
int	declare_tests_and_run(int all_of, char *these[])
{
	T(constants,
		if (CHAR_BIT == 8)
		{
			printf("UTF8_MAJ_TTL_BITS is : %d\n", UTF8_MAJ_TTL_BITS);
			printf("UTF8_BIT_GRPS is : %d\n", UTF8_BIT_GRPS);
			printf("UTF8_LST_GRP is : %d\n", UTF8_LST_GRP);
			printf("UTF8_LEAD_PRFX is : %d\n", UTF8_LEAD_PRFX);
			printf("UTF8_LEAD_BITS is : %d\n", UTF8_LEAD_BITS);
			printf("UTF8_LEAD is : %d\n", UTF8_LEAD);
			printf("UTF8_MAX_CHARS is : %d\n", UTF8_MAX_CHARS);
			assert_true(UTF8_MAX_CHARS == 4);
		}
		else
			skip();//which shouldn't happen
	)

	T(t0,
		char	*ref;
		ref = ((char[AR_SZ]){0x0});
		char	*tst;
		tst = ((char[AR_SZ]){0});
		wchar_t	in = 0x0;

		true_utf8seq(in, tst);
		assert_memory_equal(ref, tst, AR_SZ);
	)

	T(t4D,
		char	*ref;
		ref = ((char[AR_SZ]){0x4D});
		char	*tst;
		tst = ((char[AR_SZ]){0});
		wchar_t	in = 0x004D;

		true_utf8seq(in, tst);
		assert_memory_equal(ref, tst, AR_SZ);
	)

	T(t0430,
		char	*ref;
		ref = ((char[AR_SZ]){0xD0, 0XB0});
		char	*tst;
		tst = ((char[AR_SZ]){0});
		wchar_t	in = 0x0430;

		true_utf8seq(in, tst);
		assert_memory_equal(ref, tst, AR_SZ);
	)

	T(t4E8C,
		char	*ref;
		ref = ((char[AR_SZ]){0xE4, 0XBA, 0X8C});
		char	*tst;
		tst = ((char[AR_SZ]){0});
		wchar_t	in = 0x4E8C;

		true_utf8seq(in, tst);
		assert_memory_equal(ref, tst, AR_SZ);
	)

	T(t10302,
		char	*ref;
		ref = ((char[AR_SZ]){0XF0, 0X90, 0X8C, 0X82});
		char	*tst;
		tst = ((char[AR_SZ]){0});
		wchar_t	in = 0x10302;

		true_utf8seq(in, tst);
		assert_memory_equal(ref, tst, AR_SZ);
	)

	T(t10ffff,
		char	*ref;
		ref = ((char[AR_SZ]){0xF4, 0X8F, 0XBF, 0XBF});
		char	*tst;
		tst = ((char[AR_SZ]){0});
		wchar_t	in = 0x10FFFF;

		true_utf8seq(in, tst);
		assert_memory_equal(ref, tst, AR_SZ);
	)
	return(run_test_arr(all_of, these));
}
