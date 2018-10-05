#include "inner.h"
#include "get_va_args__vaargers.h"

void const	*(*f_ar[e_types_sz])(va_list*) = {
			vaarg_notype,
			vaarg_char,
			vaarg_uchar,
			vaarg_charptr,
			vaarg_double,
			vaarg_longdouble,
			vaarg_int,
			vaarg_uint,
			vaarg_intptr,
			vaarg_intmax_t,
			vaarg_uintmax_t,
			vaarg_long,
			vaarg_ulong,
			vaarg_longptr,
			vaarg_longlong,
			vaarg_ulonglong,
			vaarg_longlongptr,
			vaarg_ptrdiff_t,
			vaarg_short,
			vaarg_ushort,
			vaarg_shortptr,
			vaarg_size_t,
			vaarg_ssize_t,
			vaarg_voidptr,
			vaarg_wchar_t,
			vaarg_wchar_tptr,
			vaarg_wint_t
};

static void	init_t_s_arg_array(size_t len, t_s_arg *ar)
{
	size_t	i;

	i = ~0;
	while (++i < len)
		ar[i] = (t_s_arg){e_notype, {0}, (void*)0};
}

static void	fill_vaarg_ar(t_s_arg *ar)
{
	t_list			*parsed;
	t_s_arg			*req_arg;
	unsigned int	pos;

	parsed = g_ps.p_req_args;
	while (parsed)
	{
		req_arg = parsed->content;
		pos = req_arg->position - 1;
		if (ar[pos].type == e_notype)
			ar[pos].type = req_arg->type;
		else if (ar[pos].type != req_arg->type)
			g_ps.errored++;
		parsed = parsed->next;
	}
}

static void resolve_vaargs(
	va_list vaargs,
	t_s_arg *ar,
	size_t len)
{
	size_t	i;
	va_list	next;

	i = ~0;
	next = vaargs;
	while (++i < len)
		next = f_ar[ar[i].type](next, &ar[i].p_val);
}

static void	fulfill_arg_reqs(t_s_arg *resolved)
{
	t_list	*parsed;
	t_s_arg	*required_arg;
	t_s_arg	*val;

	parsed = g_ps.p_req_args;
	while(parsed)
	{
		required_arg = (t_s_arg*)parsed->content;
		val = resolved + required_arg->position - 1;
		val->count_uses++;
		required_arg->p_val = val->p_val;
		parsed = parsed->next;
	}
}

static void	check_arg_use(
	t_s_arg *used_args, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		if (! used_args[i].count_uses)
		{
			g_ps.errored++;
			break;
		}
}

int			get_va_args(
	va_list vaargs)
{
	unsigned int	len;
	size_t			ar_sz;
	t_s_arg			*p_ar;

	len = g_ps.max_arg_pos;
	ar_sz = len * sizeof(t_s_arg);
	if (!(p_ar = malloc(ar_sz)))
		return (0);
	init_t_s_arg_array(len, p_ar);
	fill_vaarg_ar(p_ar);
	resolve_vaargs(vaargs, p_ar, len);
	fulfill_arg_reqs(p_ar);
	check_arg_use(p_ar, len);
	ft_cleanfree(p_ar, ar_sz);
	return (!g_ps.errored);
}
