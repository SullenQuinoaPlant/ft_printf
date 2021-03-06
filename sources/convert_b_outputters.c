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
	val = 0;
	ft_memcpy(&val, stf->p_mem, stf->mem_chk);
	ft_memset(stf->val, stf->base[0], VTB_MIB_OFFSET);
	vtb_uv_tscc(val, stf->base, &stf->val);
	stf->val_p.len = stf->mem_chk_len;
	stf->val_p.c = stf->val + VTB_MIB_OFFSET - stf->val_p.len;
	stf->p_mem += nxt * stf->mem_chk;
	return (1);
}

int								tsof_bmem(
	size_t len,
	void *arg)
{
	t_s_bcs	*const	stf = (t_s_bcs*)arg;
	int const		nxt = stf->chk_count < 0 ? -1 : 1;
	int				r;

	r = 1;
	while (r && len-- && (stf->val_p.len || next_chk(stf)))
	{
		stf->val_p.len--;
		if (nxt == 1 && !(stf->chk->flags & APSTR_FLAG))
			r = output_c(1, *(stf->val_p.c + stf->val_p.len));
		else
			r = output_c(1, *stf->val_p.c++);
	}
	return (r && !++len);
}
