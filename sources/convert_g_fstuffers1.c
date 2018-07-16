#include "ft_printf_inner.h"

#define HIGH_DIG 3
#define HIGH_GRP 1
static void	set_syl_grps(t_s_fcs *stf)
{
	t_s_so	* const	syls = stf->syls;
	t_s_sgd	ar[F_SYLGRPS] = {
		{&syls[0], 2, 0, 0, 0},
		{&syls[2], 3, 3, -1, '\''},
		{&syls[5], 4, 3, 0, '\''}};
	int		i;

	i = apstr_offset(syls[HIGH_DIG].len, ar[HIGH_GRP].apstr_grp);
	ar[HIGH_GRP].apstr_pos = i;
	ft_memcpy(stf->syl_grps, ar, sizeof(ar));
}
