#include "inner.h"

t_s_vl		vaarg_longdouble(
	t_s_vl list,
	void **p_ret)
{
	t_list		*known_val;
	long double	val;

	val = va_arg(list.l, long double);
	if((known_val = ft_lstnew(&val, sizeof(long double))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_int(
	t_s_vl list,
	void **p_ret)
{
	t_list	*known_val;
	int		val;

	val = va_arg(list.l, int);
	if((known_val = ft_lstnew(&val, sizeof(int))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_uint(
	t_s_vl list,
	void **p_ret)
{
	t_list			*known_val;
	unsigned int	val;

	val = va_arg(list.l, unsigned int);
	if((known_val = ft_lstnew(&val, sizeof(unsigned int))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_intptr(
	t_s_vl list,
	void **p_ret)
{
	t_list	*known_val;
	int		*val;

	val = va_arg(list.l, int*);
	if((known_val = ft_lstnew(&val, sizeof(int*))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_intmax_t(
	t_s_vl list,
	void **p_ret)
{
	t_list		*known_val;
	intmax_t	val;

	val = va_arg(list.l, intmax_t);
	if((known_val = ft_lstnew(&val, sizeof(intmax_t))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}
