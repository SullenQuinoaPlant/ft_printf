#include "inner.h"

t_s_vl		vaarg_uintmax(
	t_s_vl list,
	void **p_ret)
{
	t_list		*known_val;
	uintmax_t	val;

	val = va_arg(list.l uintmax_t);
	if((known_val = ft_lstnew(&val, sizeof(uintmax_t))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_long(
	t_s_vl list,
	void **p_ret)
{
	t_list	*known_val;
	long	val;

	val = va_arg(list.l long);
	if((known_val = ft_lstnew(&val, sizeof(long))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_ulong(
	t_s_vl list,
	void **p_ret)
{
	t_list			*known_val;
	unsigned long	val;

	val = va_arg(list.l unsigned long);
	if((known_val = ft_lstnew(&val, sizeof(unsigned long))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_longptr(
	t_s_vl list,
	void **p_ret)
{
	t_list	*known_val;
	long	*val;

	val = va_arg(list.l long*);
	if((known_val = ft_lstnew(&val, sizeof(long*))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_longlong(
	t_s_vl list,
	void **p_ret)
{
	t_list		*known_val;
	long long	val;

	val = va_arg(list.l long long);
	if((known_val = ft_lstnew(&val, sizeof(long long))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}
