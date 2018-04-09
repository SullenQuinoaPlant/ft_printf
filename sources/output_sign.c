#include "h.h"

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
	if (c && (r = write(g_os.out_stream, &c, 1)) > 0)
		g_os.output_len++;
	else
		g_os.errored += c ? 1 : 0;
	return (r);
}
