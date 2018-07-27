#include "ft_printf_inner.h"

char const *
	percent_control_fd(
		char const *in)
{
	char const	* const save = in;
	t_s_ctl		* const chk = get_tsctl();
	int **		* const p_res = (int***)&chk->p_args;
	
	if (*in++ != '>')
		return (save);
	if ((in = percent_convert_star(in, p_res)) == save)
		in = parse_store_int_literal(in, p_res);
	return (in);
}
