/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_k.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 23:44:32 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/01 23:15:41 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static t_stuffer				g_fstr[K_SYLS + 1] =
{
	dummy_stuffer,
	dummy_stuffer,
	ck_hour,
	ck_hour_char,
	ck_minutes,
	ck_minutes_char,
	ck_seconds_char,
	dummy_stuffer,
	0
}

#define HM_SEP 2
#define MS_SEP 5
#define S_TRAIL 8

void							set_separators(
	t_s_pct *chk,
	char *buf,
	size_t *len)
{
	if (chk->flags & HASH_FLAG)
	{
		buf[HM_SEP] = ':';
		buf[MS_SEP] = ':';
		buf[S_TRAIL] = '\0';
		*len = 8;
	}
	else
	{
		buf[HM_SEP] = 'h';
		buf[MS_SEP] = 'm';
		buf[S_TRAIL] = 's';
		*len = 9;
	}
}

#define H 0
#define M 1
#define S 2
#define TM_DIGITS 2

void							write_time(
	struct tm const *tm,
	char *buf)
{
	int		hms[3];
	int		i;
	int		j;
	int		k;

	hms = (int[3]){tm->tm_hour, tm->tm_min, tm->tm_sec};
	i = -1;
	while (++i < 3)
	{
		k = i * 3 - 1;
		j = 0;
		while (j++ < TM_DIGITS)
		{
			buf[k - j] = '0' + hms[i] % 10;
			hms[i] /= 10;
		}
	}
}

void							convert_k(
	t_s_pct *chk)
{
	char	buf[9];
	size_t	lens[e_oi_sz];

	lens[e_prefix] = 0;
	set_separators(chk, buf, lens);
	write_time(chk->vaarg->p_val, buf);
	output_padnbuffer(buf, lens, chk);
}
