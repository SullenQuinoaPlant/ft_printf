#include "ft_printf_inner.h"

void const	*vaarg_notype(va_list *p_va_l)
{
	(void)p_va_l;
	return (0);
}

void const	*vaarg_char(va_list *p_va_l)
{
	t_list		*known_val;
	int			val;

	val = va_arg(*p_va_l, int);
	if((known_val = ft_lstnew(&val, sizeof(int))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}
	
void const	*vaarg_uchar(va_list *p_va_l)
{
	t_list	*known_val;
	int		val;

	val = va_arg(*p_va_l, int);
	if((known_val = ft_lstnew(&val, sizeof(int))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_charptr(va_list *p_va_l)
{
	t_list	*known_val;
	char	*val;

	val = va_arg(*p_va_l, char*);
	if((known_val = ft_lstnew(&val, sizeof(char*))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_double(va_list *p_va_l)
{
	t_list	*known_val;
	double	val;

	val = va_arg(*p_va_l, double);
	if((known_val = ft_lstnew(&val, sizeof(double))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}
