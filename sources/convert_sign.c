#include "inner.h"

t_s_vtb_cc	sign_to_b(int sign, t_s_pct *p_chk, char *b)
{
	t_s_vtb_cc	ret;

	ret = (t_s_vtb_cc){b, 1};
	if (p_chk->flags & PLUS_FLAG)
		*b = sign < 0 ? '-' : '+';
	else if (p_chk->flags & SPACE_FLAG)
		*b = sign < 0 ? '-' : ' ';
	else if (sign < 0)
		*b = '-';
	else
		ret.len = 0;
	return (ret);
}

/*unused
int		output_sign(int sign, t_s_pct *p_chk)
{
	int		r;
	char	c;

	if (p_chk->flags & PLUS_FLAG)
		c = sign < 0 ? '-' : '+';
	else if (p_chk->flags & SPACE_FLAG)
		c = sign < 0 ? '-' : ' ';
	else
		c =  sign < 0 ? '-' : 0;
	r = 0;
	if (c && (r = write(g_os.fd, &c, 1)) > 0)
		g_os.output_len++;
	else
		g_os.errored += c ? 1 : 0;
	return (r);
}
*/
