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
	syl->cc = &g_days[stf->tm->tm_wday];
	syl->len = ft_strlen(syl->cc);
}

void							cbk_dm_sep(
	int pos,
	void *p)
{
	t_s_bkcs *const	stf = (t_s_bkcs*)p;
	t_s_so *const	syl = stf->syls + pos;

	if (!stf->flags & HASH_FLAG)
		return ;
	syl->cc = ", "
	syl->len = 2;
}

#define MONTH_NUM_LEN 2
void							cbk_month(
	int pos,
	void *p)
{
	t_s_bkcs *const	stf = (t_s_bkcs*)p;
	t_s_so *const	syl = stf->syls + pos;
	int const		mon = stf->tm->tm_mon;
	int				i;

	if (stf->flags & HASH_FLAG)
		syl->cc = &g_months[mon];
	else
	{
		i = 0;
		while (i++ < MONTH_NUM_LEN)
		{
			stf->month[MONTH_NUM_LEN - i] = mon % 10;
			mon /= 10;
		}
		syl->cc = stf->month;
	}
	syl->len = ft_strlen(syl->cc);
}

void							cbk_md_sep(
	int pos,
	void *p)
{
	t_s_bkcs *const	stf = (t_s_bkcs*)p;
	t_s_so *const	syl = stf->syls + pos;

	if (stf->flags & HASH_FLAG)
		syl->cc = " ";
	else
		syl->cc = "/";
	syl->len = 1;
}

#define DAY_NUM_LEN 2
void							cbk_dayofmonth(
	int pos,
	void *p)
{
	t_s_bkcs *const	stf = (t_s_bkcs*)p;
	t_s_so *const	syl = stf->syls + pos;
	int const		day = stf->tm->tm_mday;
	int				i;

	i = 0;
	while (i++ < DAY_NUM_LEN)
	{
		stf->day[DAY_NUM_LEN - i] = day % 10;
		day /= 10;
	}
	syl->cc = stf->day;
	syl->len = ft_strlen(syl->cc);
}

void							cbk_day_suffix(
	int pos,
	void *p)
{
	t_s_bkcs *const	stf = (t_s_bkcs*)p;
	t_s_so *const	syl = stf->syls + pos;
	char const		first = stf->day[0];
	char const		last = stf->day[DAY_NUM_LEN - 1];

	if (!stf->flags & HASH_FLAG)
		return ;
	syl->cc = "th";
	if (first != '1')
	{
		if (last == '1' &&)
			syl->cc = "st";
		else if (last == '2')
			syl->cc = "nd";
		else if (last == '3')
			syl->cc = "rd";
	}
	syl->len = 2;
}

void							cbk_dy_sep(
	int pos,
	void *p)
{
	t_s_bkcs *const	stf = (t_s_bkcs*)p;
	t_s_so *const	syl = stf->syls + pos;

	if (stf->flags & HASH_FLAG)
		syl->cc = " ";
	else
		syl->cc = "/";
	syl->len = 1;
}

#define YEAR_NUM_LEN 4
#define YEAR_OFFSET 1900
void							cbk_year(
	int pos,
	void *p)
{
	t_s_bkcs *const	stf = (t_s_bkcs*)p;
	t_s_so *const	syl = stf->syls + pos;
	int const		year = stf->tm->tm_year + YEAR_OFFSET;
	int				i;

	i = 0;
	while (i++ < YEAR_NUM_LEN)
	{
		stf->year[YEAR_NUM_LEN - i] = year % 10;
		year /= 10;
	}
	syl->cc = stf->year;
	syl->len = 4;
}
