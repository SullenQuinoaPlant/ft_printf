#include "inner.h"

static char	*g_nan = "nan";
static char	*g_bignan = "NAN";
static char *g_inf = "inf";
static char *g_biginf = "INF";

static int	output_nan(t_s_pct *p)
{
	char	*s;
	size_t	l;
	int		r;

	s = p->flags & BIGCS_FLAG ? g_bignan : g_nan;
	l = ft_strlen(s);
	r = output_padnbuffer(s, (size_t[e_oi_sz]){0, l}, p);
	return (r);
}

static int	output_plusinf(t_s_pct *p)
{
	int		r;
	size_t	l;
	char	*s;

 	s = p->flags & BIGCS_FLAG ? g_biginf : g_inf;
	l = ft_strlen(s);
	l += p->flags & (PLUS_FLAG | SPACE_FLAG) ? 1 : 0;
	r = output_padnbuffer(s, (size_t[e_oi_sz]){0, l}, p);
	return (r);
}

static int	output_minusinf(t_s_pct *p)
{
	char	*s;
	size_t	l;
	int		r;

 	s = p->flags & BIGCS_FLAG ? g_biginf : g_inf;
	l = ft_strlen(s);
	r = output_padnbuffer(s, (size_t[e_oi_sz]){0, l}, p);
	return (r);
}

/*of r: output functions called from output_nan_inf
**	return 1 on success, 0 on failure.
**	output_nan_inf returns different values:
**		1 on success,
**		0 when no output was attempted,
**		-1 on error.
*/
int		output_nan_inf(t_s_dfp *val, t_s_pct *chk)
{
	int		const flg = val->flags;
	int		r;

	r = -1;
	if (flg & NAN_F)
		r += 2 * output_nan(chk);
	else if (flg & SIGN_F && flg & INF_F)
		r += 2 * output_minusinf(chk);
	else if (flg & INF_F)
		r += 2 * output_plusinf(chk);
	else
		r = 0;
	return (r);
}
