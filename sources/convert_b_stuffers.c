#include "ft_printf_inner.h"

void
	cd_addrprefix(
		int pos, void *p)
{
	t_s_bcs	* const stf = (t_s_bcs*)p;
	t_s_so	* const syl = stf->syls + pos;
	
	syl->type = e_sot_c;
	syl->len = 0;
	if (!(stf->chk->flags & HASH_FLAG))
		return ();
	syl->len = 1
	syl->c = '@';
}

void
	cd_addrprefix(
		int pos, void *p)
{
	t_s_bcs		* const stf = (t_s_bcs*)p;
	t_s_so		* const syl = stf->syls + pos;
	char const	*base; 

	syl->len = 0;
	if (!(stf->chk->flags & HASH_FLAG))
		return ();
	base = g_hex_syms;
	if (stf->chk->flags & PLUS_FLAG)
		base = g_bhex_syms;
	*syl = syl_uv_tob(stf->p_mem, base, &stf->addr);
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_cc;
}

void
	cd_addrpostfix(
		int pos, void *p)
{
	t_s_bcs	* const stf = (t_s_bcs*)p;
	t_s_so	* const syl = stf->syls + pos;
	
	syl->type = e_sot_c;
	syl->len = 0;
	if (!(stf->chk->flags & HASH_FLAG))
		return ();
	syl->len = 3
	syl->c = ' ';
}

void
	cd_mem(
		int pos, void *p)
{
	t_s_bcs	* const stf = (t_s_bcs*)p;
	t_s_so	* const syl = stf->syls + pos;
	size_t	len;

	len = stf->chk_count * (stf->chk_count < 0 ? -1 : 1);
	len *= CHAR_BIT / my_flog2(ft_strlen(stf->base));
	syl->len = len;
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_f;
	else
		syl->type = e_sot_f;
	syl->arg = p;
	if (stf->chk->specifier == e_B)
		syl->f = tsof_hexmem;
	else
		syl->f = tsof_bitmem;
}
