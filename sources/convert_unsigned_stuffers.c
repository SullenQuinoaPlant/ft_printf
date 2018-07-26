#include "ft_printf_inner.h"

void
	cunsigned_prefix(
		int pos, void *p)
{
	t_s_unsignedcs	* const stf = (t_s_unsignedcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_c;
	syl->c = '0';
	if (stf->pre > 0 && stf->p_b.len < (size_t)stf->pre)
		syl->len = stf->pre - stf->p_b.len;
}

#define PREFIX_RELPOS 1
void
	cunsigned_hashfix(
		int pos, void *p)
{
	t_s_unsignedcs	* const stf = (t_s_unsignedcs*)p;
	t_s_so	* const syl = stf->syls + pos;
	t_s_so	* const prefix = syl - PREFIX_RELPOS;
	char	const flags = stf->chk->flags;

	syl->type = e_sot_apstr_c;
	syl->c = '0';
	if (flags & HASH_FLAG &&
		!prefix->len &&
		*stf->p_b.c != syl->c)
		syl->len = 1;
}

void
	cunsigned_digits(
		int pos, void *p)
{
	t_s_unsignedcs	* const stf = (t_s_unsignedcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_cc;
	syl->cc = stf->p_b.c;
	syl->len = stf->p_b.len;
}
