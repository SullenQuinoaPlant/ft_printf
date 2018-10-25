/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmyutf8.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:59:40 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 10:00:12 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMYUTF8_H
# define LIBMYUTF8_H

# define UTF8_MAX_CHARS 4

/*
** DO NOT USE IF WCHAR_T WIDER THAN 32 BITS
*/

int				utf8_seq(
	wchar_t	val,
	int		char_lim,
	char	*put);

size_t			utf8_strtoseq(
	wchar_t	*str,
	char	*put,
	size_t	len);

int				utf8_trueseq(
	wchar_t	val,
	char	*put);

#endif
