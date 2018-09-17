#include "inner.h"

static
int
	next_chk(
		t_s_bcs *stf)
{
	int			const nxt = stf->chk_count < 0 ? -1 : 1;
	uintmax_t	val;

	if (!stf->chk_count)
		return (0);
	stf->chk_count -= nxt;
	stf->p_mem += nxt * stf->mem_chk;
	ft_memcpy(&val, stf->p_mem, stf->mem_chk);
	stf->val_p = vtb_uv_tscc(val, stf->base, &stf->val);
	return (1);
}

int
	tsof_hexmem(
		size_t len, void *arg)
{
	t_s_bcs	* const stf = (t_s_bcs*)arg;
	int		r;

	while (len && (stf->val_p.len-- || next_chk(stf)))
		r = output_c(1, *stf->val_p.c++);
	return (r);
}

int
	tsof_bitmem(
		size_t len, void *arg)
{
	t_s_bcs	* const stf = (t_s_bcs*)arg;
	int		r;

	while (len && (stf->val_p.len-- || next_chk(stf)))
		r = output_c(1, *(stf->val_p.c + stf->val_p.len));
	return (r);
}
