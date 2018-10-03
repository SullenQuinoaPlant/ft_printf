/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_k.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 23:44:32 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/01 23:24:21 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "inner.h"

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
		buf[HM_SEP] = 'h';
		buf[MS_SEP] = 'm';
		buf[S_TRAIL] = 's';
		*len = 9;
	}
	else
	{
		buf[HM_SEP] = ':';
		buf[MS_SEP] = ':';
		buf[S_TRAIL] = '\0';
		*len = 8;
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

	hms[H] = tm->tm_hour;
	hms[M] = tm->tm_min;
	hms[S] = tm->tm_sec;
	i = -1;
	while (++i < 3)
	{
		k = (1 + i) * 3 - 1;
		j = 0;
		while (j++ < TM_DIGITS)
		{
			buf[k - j] = '0' + hms[i] % 10;
			hms[i] /= 10;
		}
	}
}

/*
**3 * 2 digits + 3 characters:
*/
#define K_BUFF_SIZE 9

void							convert_k(
	t_s_pct *chk)
{
	char	buf[K_BUFF_SIZE];
	size_t	lens[e_oi_sz];

	lens[e_prefix] = 0;
	set_separators(chk, buf, &lens[e_root]);
	write_time(*(struct tm**)chk->vaarg->p_val, buf);
	output_padnbuffer(buf, lens, chk);
}
