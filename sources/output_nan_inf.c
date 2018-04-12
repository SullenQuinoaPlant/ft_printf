#include "h.h"

static char	*g_nan = "nan";
static char	*g_bignan = "NAN*";
static char *g_inf = "inf";
static char *g_biginf = "INF";

int		output_nan(t_s_pct *p_chk)
{
	ssize_t	writ;
	int		str_len;
	int		r;
	int		pad;
	char	*str;

	str = wants_big(p_chk) ? g_bignan : g_nan;
	str_len = ft_strlen(str);
	r = 1;
	if ((pad = **p_chk->width - str_len) > 0 &&
		p_chk->flags & MINUS_FLAG &&
		(r = output_padding(pad, ' ') > 0))
		pad = 0;
	writ = 0;
	if (r &&
		(r = (writ = write(g_os.out_stream, str, str_len)) > 0))
		g_os.output_len += writ;
	else
		g_os.errored += writ ? 1 : 0;
	if (pad > 0 && r && output_padding(pad, ' ') < 0)
		r = 0;
	return (r ? r : -1);
}

int		output_plusinf(t_s_pct *p_chk)
{
	char	*s;
	size_t	len;
	ssize_t	writ;
	ssize_t	r;
	int		pad;

	len = ft_strlen((s = wants_big(p_chk) ? g_biginf : g_inf;
	len += p_chk->flags & (PLUS_FLAG | SPACE_FLAG) ? 1 : 0;
	r = 1;
	if ((pad = **p_chk->width - str_len) > 0 &&
		p_chk->flags & MINUS_FLAG &&
		(r = output_padding(pad, ' ') > 0))
		pad = 0;
	r = r ? (output_sign(1, p_chk) >= 0) : r;
	writ = 0;
	if (r &&
		(r = (writ = write(g_os.out_stream, str, str_len)) > 0))
		g_os.output_len += writ;
	else
		g_os.errored += writ ? 1 : 0;
	r = pad > 0 ? (r && output_padding(pad, ' ') > 0) : r;
	return (r ? r : -1);
}

int		output_minusinf(t_s_pct *p_chk)
{
	char	*s;
	size_t	len;
	ssize_t	writ;
	ssize_t	r;
	int		pad;

	len = 1 + ft_strlen((s = wants_big(p_chk) ? g_biginf : g_inf;
	r = 1;
	if ((pad = **p_chk->width - str_len) > 0 &&
		p_chk->flags & MINUS_FLAG &&
		(r = output_padding(pad, ' ') > 0))
		pad = 0;
	r = r ? (output_sign(-1, p_chk) >= 0) : r;
	writ = 0;
	if (r &&
		(r = (writ = write(g_os.out_stream, str, str_len)) > 0))
		g_os.output_len += writ;
	else
		g_os.errored += writ ? 1 : 0;
	r = pad > 0 ? (r && output_padding(pad, ' ') > 0) : r;
	return (r ? r : -1);
}

int		output_nan_inf(t_s_dfp *val, t_s_pct *p_chk)
{
	int		const flg = val->flags;
	int		r;

	r = 0;
	if (flg & (~SIGN_F) &&
	!((flg & NAN_F && (r = output_nan(p_chk))) ||
	(flg & INF_F &&
	((flg & SIGN_F && (r = output_minusinf(p_chk))) ||
	(r = output_plusinf(p_chk))))))
		r = -1;
	return (r);
}
