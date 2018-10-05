#include "inner.h"

t_s_vl		vaarg_wchar_tptr(
	t_s_vl list,
	void **p_ret)
{
	t_list		*known_val;
	wchar_t		*val;

	val = va_arg(list.l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_wint_t(
	t_s_vl list,
	void **p_ret)
{
	t_list		*known_val;
	wint_t		val;

	val = va_arg(list.l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}
