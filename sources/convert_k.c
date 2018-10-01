/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_k.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 23:44:32 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/01 22:25:56 by nmauvari         ###   ########.fr       */
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

