#include "ft_printf_inner.h"

void const	*vaarg_wchar_tptr(va_list *p_va_l)
{
	t_list		*known_val;
	wchar_t		*val;

	val = va_arg(*p_va_l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_wint_t(va_list *p_va_l)
{
	t_list		*known_val;
	wint_t		val;

	val = va_arg(*p_va_l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}
