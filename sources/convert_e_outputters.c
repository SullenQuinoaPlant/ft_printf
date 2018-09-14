#include "inner.h"

#define PREFIX_GRP_I 0
#define PRE_GRP_COUNT 1
#define BODY_GRP_I 1
#define BOD_GRP_COUNT 3

int
	ce_prefix(
		void *p)
{
	int		r;
	t_s_ecs	* const stf = (t_s_ecs*)p;

	r = out_syl_groups(stf->syl_grps, PRE_GRP_COUNT);
	return (r);
}

int
	ce_body(
		void *p)
{
	t_s_ecs	* const stf = (t_s_ecs*)p;
	t_s_sgd	* const first = stf->syl_grps + BODY_GRP_I;
	int		r;

	r = out_syl_groups(first, BOD_GRP_COUNT);
	return (r);
}
