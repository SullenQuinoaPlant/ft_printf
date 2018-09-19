#include "inner.h"

void
	cb_addrprefix(
		int pos, void *p)
{
	t_s_bcs	* const stf = (t_s_bcs*)p;
	t_s_so	* const syl = stf->syls + pos;
	
	syl->type = e_sot_c;
	syl->len = 0;
	if (!(stf->chk->flags & HASH_FLAG))
		return;
	syl->len = 1;
	syl->c = '@';
}

void
	cb_addr(
		int pos, void *p)
{
	t_s_bcs		* const stf = (t_s_bcs*)p;
	t_s_so		* const syl = stf->syls + pos;
	size_t		addr;
	char const	*base; 

	syl->type = e_sot_cc;
	syl->len = 0;
	if (!(stf->chk->flags & HASH_FLAG))
		return;
	base = VTB_HEX_SYMS;
	if (stf->chk->flags & PLUS_FLAG)
		base = VTB_BHEX_SYMS;
	addr = (size_t)stf->p_mem;
	*syl = syl_uv_tob(addr, base, &stf->addr);
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_cc;
}

void						cb_addrpostfix(
	int pos,
	void *p)
{
	t_s_bcs *const	stf = (t_s_bcs*)p;
	t_s_so *const	syl = stf->syls + pos;
	
	syl->type = e_sot_c;
	syl->len = 0;
	if (!(stf->chk->flags & HASH_FLAG))
		return;
	syl->len = 3;
	syl->c = ' ';
}

void						cb_mem(
	int pos,
	void *p)
{
	t_s_bcs *const	stf = (t_s_bcs*)p;
	t_s_so *const	syl = stf->syls + pos;
	size_t			len;

	len = stf->chk_count * (stf->chk_count < 0 ? -1 : 1);
	len *= CHAR_BIT / my_flog2(ft_strlen(stf->base));
	syl->len = len;
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_f;
	else
		syl->type = e_sot_f;
	syl->arg = p;
	syl->f = tsof_hexmem;
	if (stf->chk->specifier == e_b)
		syl->f = tsof_bitmem;
	stf->val_p = (t_s_vtb_cc){0, 0};
}
