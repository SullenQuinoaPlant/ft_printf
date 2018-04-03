#include "h.h"

static void	clean_free_cw(void *ptr, size_t whatever)
{
	(void)whatever;
	t_s_cw * const	p_cw = (t_s_cw*)ptr;
	size_t			sz;
	t_e_cts			*p;

	if (! p_cw)
		return;
	p = &p_cw->type;
	sz = 0;
	if (*p == e_txt_c)
		sz = sizeof(t_s_text);
	else if (*p == e_char_c)
		sz = sizeof(t_s_char);
	else if (*p == e_pct_c)
		sz = sizeof(t_s_pct);
	if (p_cw->chk)
		my_clean_free(p_cw->chk, sz);
	*p_cw = (t_s_cw){0,0};
	free(p_cw);
}

void 	free_parse_state_lists(t_s_ps *to_free)
{
	if (ps->chunks.next)
		ft_lstdel(&ps->chunks.next, clean_free_cw);
	ps->chunks.content = 0;
	if (ps->p_req_args)
		ft_lstdel(&ps->p_req_args, my_clean_free);
	if (ps->p_literal_vals)
		ft_lstdel(&ps->p_literal_vals, my_clean_free);
}
