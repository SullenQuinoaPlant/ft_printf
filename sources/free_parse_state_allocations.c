#include "ft_printf_inner.h"

static void	clean_free_cw(void *ptr, size_t whatever)
{
	t_s_cw	* const p_cw = (t_s_cw*)ptr;
	size_t	sz;
	t_e_cts	p;

	(void)whatever;
	p = p_cw->type;
	if (p_cw->chk)
	{
		if (p == e_txt_c)
			sz = sizeof(t_s_txt);
		else if (p == e_char_c)
			sz = sizeof(t_s_char);
		else
			sz = sizeof(t_s_pct);
		my_clean_free(p_cw->chk, sz);
	}
	*p_cw = (t_s_cw){0,0};
	free(p_cw);
}

void 		free_parse_state_lists(t_s_ps *ps)
{
	if (ps->chunks.head.next)
		ft_lstdel(&ps->chunks.head.next, clean_free_cw);
	if (ps->p_req_args)
		ft_lstdel(&ps->p_req_args, my_clean_free);
	if (ps->p_known_vals)
		ft_lstdel(&ps->p_known_vals, my_clean_free);
	ft_bzero((void*)ps, sizeof(t_s_ps));
}
