#include "h.h"

static char	*g_nan = "nan";
static char	*g_bignan = "NAN*";
static char *g_inf = "inf";
static char *g_biginf = "INF";

int		output_nan(t_s_pct *p_chk)
{
	int		str_len;
	int		r;
	char	*str;

	str = p_chk->flags & BIGCS_FLAG ? g_bignan : g_nan;
	str_len = ft_strlen(str);
	r = output_padnbuffer(str, 0, str_len, p_chk);
	return (r);
}

int		output_plusinf(t_s_pct *p_chk)
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

int		output_minusinf(t_s_pct *p_chk)
{
	char	*str;
	size_t	str_len;
	int		r;

 	str = p_chk->flags & BIGCS_FLAG ? g_biginf : g_inf;
	str_len = ft_strlen(str);
	r = output_padnbuffer(str, 0, str_len, p_chk);
	return (r);
}

int		output_nan_inf(t_s_dfp *val, t_s_pct *p_chk)
{
	int		const flg = val->flags;
	int		r;

	r = 0;
	if (flg & ~SIGN_F &&
	!((flg & NAN_F && (r = output_nan(p_chk))) ||
	(flg & (SIGN_F | INF_F) && (r = output_minusinf(p_chk))) ||
	(flg & INF_F && (r = output_plusinf(p_chk))))
		r = -1;
	return (r);
}
