#include "ft_printf_inner.h"

#define PREFIX_GRP_I 0
#define PRE_GRP_COUNT 1
#define BODY_GRP_I 1
#define BOD_GRP_COUNT 3

int
	ce_prefix(
		void *stf)
{
	int	r;

	r = out_syl_groups(stf->syl_grps, PRE_GRP_COUNT);
	return (r);
}

int
	ce_body(
		void *stf)
{
	t_s_sgd	* const first = stf->syl_grps + BODY_GRP_I;
	int		r;

	r = out_syl_groups(first, PRE_GRP_COUNT);
	return (r);
}