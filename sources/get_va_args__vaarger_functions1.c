#include "inner.h"

t_s_vl		vaarg_notype(
	t_s_vl list,
	void **p_ret)
{
	(void)val;
	(void)p_ret;
	return (list);
}

t_s_vl		vaarg_char(
	t_s_vl list,
	void **p_ret)
{
	t_list		*known_val;
	int			val;

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
	
t_s_vl		vaarg_uchar(
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

t_s_vl		vaarg_charptr(
	t_s_vl list,
	void **p_ret)
{
	t_list	*known_val;
	char	*val;

	val = va_arg(list.l, char*);
	if((known_val = ft_lstnew(&val, sizeof(char*))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}

t_s_vl		vaarg_double(
	t_s_vl list,
	void **p_ret)
{
	t_list	*known_val;
	double	val;

	val = va_arg(list.l, double);
	if((known_val = ft_lstnew(&val, sizeof(double))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		*p_ret = known_val->content;
	}
	else
		g_ps.errored++;
	return (list);
}
