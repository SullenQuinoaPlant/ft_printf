void						convert_r(
	t_s_pct *chk)
{
	char *const	p = *(char**)chk->vaarg->p_val;
	int			pre;

	if (!p)
	{
		output_null(chk);
		return ;
	}
	pre = 0;
	if (chk->precision)
		pre = **chk->precision;
	output_padnbuffer(p, (size_t[e_oi_sz]){0, (size_t)pre}, chk);
}

#define BUFF_SZ 256
void						convert_big_r(
	t_s_pct *chk)
{
	int const	fd = *(int*)chk->vaarg->p_val;
	int			pre;
	size_t		b_sz;
	ssize_t		r;
	char		b[BUFF_SZ];

	if (fd < 0)
		return ;
	r = 1;
	while (r > 0)
	{
		b_sz = pre > BUFF_SZ ? BUFF_SZ : pre;
		r = read(fd, b, b_sz);
		output_padnbuffer(b, (size_t[e_oi_sz]){0, b_sz}, chk);
		pre -= BUFF_SZ;
	}
	if (r < 0)
		g_os.errored++;
}
