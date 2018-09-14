#include "inner.h"

void
	init_parse_state()
{
	g_ps.chunks.head.next = 0;
	g_ps.chunks.tail = &g_ps.chunks.head;
	g_ps.p_req_args = 0;
	g_ps.p_known_vals = 0;
	g_ps.free_arg_count = 0;
	g_ps.dollar_count = 0;
	g_ps.max_arg_pos = 0;
	g_ps.errored = 0;
}

t_s_arg *
	req_arg_init()
{
	t_list	*p_arg;
	t_s_arg	init;

	init = (t_s_arg){e_notype, {0}, 0};
	if ((p_arg = ft_lstnew(&init, sizeof(init))))
		ft_lstadd(&g_ps.p_req_args, p_arg);
	return ((t_s_arg*)p_arg->content);
}

static void
	clean_free_cw(
		void *ptr, size_t whatever)
{
	t_s_cw	* const p_cw = (t_s_cw*)ptr;
	size_t	sz;
	t_e_cts	t;

	(void)whatever;
	if (p_cw->chk)
	{
		sz = 0;
		if ((t = p_cw->type) == e_txt_c)
			sz = sizeof(t_s_txt);
		else if (t == e_char_c)
			sz = sizeof(t_s_char);
		else if (t == e_pct_c)
			sz = sizeof(t_s_pct);
		else if (t == e_ctl_chk)
			sz = sizeof(t_s_ctl);
		ft_cleanfree(p_cw->chk, sz);
	}
	*p_cw = (t_s_cw){0,0};
	free(p_cw);
}

void
	free_parse_state_lists(
		t_s_ps *ps)
{
	if (ps->chunks.head.next)
		ft_lstdel(&ps->chunks.head.next, clean_free_cw);
	if (ps->p_req_args)
		ft_lstdel(&ps->p_req_args, ft_cleanfree);
	if (ps->p_known_vals)
		ft_lstdel(&ps->p_known_vals, ft_cleanfree);
	ft_bzero((void*)ps, sizeof(t_s_ps));
}
