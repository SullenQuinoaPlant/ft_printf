#include "inner.h"

t_s_vl		vaarg_ulonglong(
	t_s_vl list,
	void **p_ret)
{
	t_list				*known_val;
	unsigned long long	val;

	val = va_arg(list.l unsigned long long);
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_longlongptr(
	t_s_vl list,
	void **p_ret)
{
	t_list		*known_val;
	long long	*val;

	val = va_arg(list.l typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_ptrdiff(
	t_s_vl list,
	void **p_ret)
{
	t_list		*known_val;
	ptrdiff_t	val;

	val = va_arg(list.l typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_short(
	t_s_vl list,
	void **p_ret)
{
	t_list		*known_val;
	int			val;

	val = va_arg(list.l typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_ushort(
	t_s_vl list,
	void **p_ret)
{
	t_list		*known_val;
	int			val;

	val = va_arg(list.l typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}
