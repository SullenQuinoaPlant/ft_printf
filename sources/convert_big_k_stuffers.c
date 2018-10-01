static char						*g_days[7] =
{
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
}

static char						*g_months[12] =
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

void							cbk_dayofweek(
	int pos,
	void *p)
{
	t_s_bkcs *const	stf = (t_s_bkcs*)p;
	t_s_so *const	syl = stf->syls + pos;

	if (!stf->flags & HASH_FLAG)
		return ;
	syl->cc = &g_days[((struct tm*)stf->vaarg->p_val)->tm_wday];
	syl->len = ft_strlen(syl->cc);
}

#define MONTH_NUM 0
void							cbk_month(
	int pos,
	void *p)
{
	t_s_bkcs *const	stf = (t_s_bkcs*)p;
	t_s_so *const	syl = stf->syls + pos;

	if (!stf->flags & HASH_FLAG)
		syl->cc = &g_months[((struct tm*)stf->vaarg->p_val)->tm_mon];
	else
	syl->len = ft_strlen(syl->cc);
}
