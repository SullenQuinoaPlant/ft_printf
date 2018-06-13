#include "ft_printf_inner.h"

static char	*g_nan = "nan";
static char	*g_bignan = "NAN*";
static char *g_inf = "inf";
static char *g_biginf = "INF";

static int	output_nan(t_s_pct *p_chk)
{
	int		str_len;
	int		r;
	char	*str;

	str = p_chk->flags & BIGCS_FLAG ? g_bignan : g_nan;
	str_len = ft_strlen(str);
	r = output_padnbuffer(str, 0, str_len, p_chk);
	return (r);
}

static int	output_plusinf(t_s_pct *p_chk)
{
	char	*str;
	size_t	str_len;
	int		r;

 	str = p_chk->flags & BIGCS_FLAG ? g_biginf : g_inf;
	str_len = ft_strlen(str);
	str_len += p_chk->flags & (PLUS_FLAG | SPACE_FLAG) ? 1 : 0;
	r = output_padnbuffer(str, 0, str_len, p_chk);
	return (r);
}

static int	output_minusinf(t_s_pct *p_chk)
{
	char	*str;
	size_t	str_len;
	int		r;

 	str = p_chk->flags & BIGCS_FLAG ? g_biginf : g_inf;
	str_len = ft_strlen(str);
	r = output_padnbuffer(str, 0, str_len, p_chk);
	return (r);
}

/*of r: output functions called from output_nan_inf
**	return 1 on success, 0 on failure.
**	output_nan_inf returns different values:
**		1 on success,
**		0 when no output was attempted,
**		-1 on error.
*/
int		output_nan_inf(t_s_dfp *val, t_s_pct *p_chk)
{
	int		const flg = val->flags;
	int		r;

	r = -1;
	if (flg & NAN_F)
		r += 2 * output_nan(p_chk);
	else if (flg & SIGN_F && flg & INF_F)
		r += 2 * output_minusinf(p_chk);
	else if (flg & INF_F)
		r += 2 * output_plusinf(p_chk);
	else
		r = 0;
	return (r);
}
