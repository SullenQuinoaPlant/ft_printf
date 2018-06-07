#define ARCH_A
#include "convert_decompose_floating_point.c"

int		main()
{
	{
		double	*ds;
		t_s_dfp	*ref;
		size_t	const len = 5;
		t_s_dfp	dds[len];
		size_t	i;

		(ds = (double[]){0.0, 1.0, 2.0, 1.5, 3.0});
		(ref = (t_s_dfp[]){
			{0, 0, 0, 0},
			{0, 0x3ff, 1ull << 52, 0},
			{0, 0x400, 1ull << 52, 0},
			{0, 0x3ff, 1ull << 51 | 1ull << 52, 0x1ull << 63},
			{0, 0x400, 1ull << 51 | 1ull << 52, 0x1ull << 63}
		});

		for (i = 0; i < len; i++)
		{
			decompose_double(ds + i, &dds[i]);
		}
	}
	{
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
		}
	}
	return (0);
}
