#include "ft_printf.h"

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

static void	init_t_s_arg_array(unsigned int len, t_s_arg *ar)
{
	size_t			i;

	i = ~0;
	while (++i < len)
		p_ar[i] = (t_s_arg){e_notype, 0, (void*)0};
}

static void	fill_vaarg_ar(t_s_ps *parsed, t_s_arg *ar)
{
	t_list			*p1;
	t_s_arg			*p_req_arg;
	unsigned int	pos;

	p1 = parsed->p_req_args;
	while (p1)
	{
		p_req_arg = p1->content;
		pos = p_req_arg->position;
		if (ar[pos] == e_notype)
			ar[pos].type = p_req_arg->type;
		else if (ar[pos]->type != p_req_arg->type)
			parsed->errored++;
		p1 = p1->next;
	}
}

static void resolve_vaargs(va_list *vaargs, t_s_arg *ar, unsigned int len)
{
	size_t	i;

	i = ~0;
	while (++i < len)
		ar[i].p_val = f_ar[ar[i].type](vaargs);
}

static void	fulfill_arg_reqs(t_s_arg *resolved, t_s_ps *parsed)
{
	t_list	*p_list;
	t_s_arg	*p_ar_arg;
	t_s_arg	*p_out_arg;

	p_list = parsed->p_req_args;
	while(p_list)
	{
		p_out_arg = (t_s_arg*)p_list->content;
		p_ar_arg = resolved + p_out_arg->position;
		p_ar_arg->count_uses++;
		p_out_arg->p_val = p_ar_arg->p_val;
		p_list = p_list->next;
	}
}

static void	check_arg_use(t_s_arg *used_args, unsigned int len, t_s_ps *parsed)
{
	size_t	i;

	i = -1;
	while (++i < len)
		if (! used_args[i].count_uses)
		{
			parsed->errored++;
			break;
		}
}

int		get_va_args(va_list *vaargs, t_s_ps *parsed)
{
	size_t			const ar_sz = len * sizeof(t_s_arg);
	unsigned int	len;
	t_s_arg			*p_ar;

	len = parsed->max_arg_pos;
	if (!(p_ar = malloc(ar_sz)))
		return (0);
	init_t_s_arg_array(len, p_ar);
	fill_vaarg_ar(parsed, p_ar);
	resolve_vaargs(vaargs, p_ar);
	fulfill_arg_reqs(p_ar, parsed);
	check_arg_use(p_ar, len, parsed);
	my_super_clean_free(*p_ar, ar_sz);
	return (1);
}
