#include "inner.h"

static char	*g_nan = "(nan)";
static char	*g_bignan = "(NAN)";
static char *g_inf = "(inf)";
static char *g_biginf = "(INF)";
static char *g_pinf = "(+inf)";
static char *g_bigpinf = "(+INF)";
static char *g_minf = "(-inf)";
static char *g_bigminf = "(-INF)";

static int	output_nan(
	t_s_pct *p)
{
	char	*s;

	s = p->flags & BIGCS_FLAG ? g_bignan : g_nan;
	return (output_string(s, p));
}

static int	output_plusinf(t_s_pct *p)
{
	char const	flags = p->flags;
	char		*s;

	s = g_inf;
	if (flags & PLUS_FLAG)
	{
		s = g_pinf;
		if (flags & BIGCS_FLAG)
			s = g_bigpinf;
	}
	else if (flags & BIGCS_FLAG)
		s = g_biginf;
	return (output_string(s, p));
}

static int	output_minusinf(t_s_pct *p)
{
	char const	flags = p->flags;
	char		*s;

	s = g_minf;
	if (flags & BIGCS_FLAG)
		s = g_bigminf;
	return (output_string(s, p));
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
