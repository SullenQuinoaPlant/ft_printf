/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmyfloatingpoint.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:27:55 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 13:34:16 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMYFLOATINGPOINT_H
# define LIBMYFLOATINGPOINT_H

# include <stdint.h>

/*
**t_s_dfp flags
*/
# define SIGN_F 0x01
# define INF_F 0x02
# define NAN_F 0x04
# define OVER_F 0x08
# define DNORM_F 0x10

typedef struct				s_decomposed_floating_point
{
	uint32_t	flags;
	int32_t		exp;
	uint64_t	mant;
}							t_s_dfp;

typedef struct				s_fp_and_dfp
{
	long double	dbl;
	t_s_dfp		dec;
}							t_s_fpndfp;

# define DB_MANT_BITS 52
# define DB_EXP_BITS 11

# define LDB_MANT_BITS 64
# define LDB_EXP_BITS 15

# define DB_MANT_PRECISION 52
# define LDB_MANT_PRECISION 63

# define DB_E_BIAS 1023
# define LDB_E_BIAS 16383

# define DB_MIN_EXP -1022
# define DB_MIN_POW DB_MIN_EXP - DB_MANT_PRECISION
# define DB_MAX_EXP 1023
# define DB_MAX_POW DB_MAX_EXP - DB_MANT_PRECISION

# define LDB_MIN_EXP -16382
# define LDB_MIN_POW LDB_MIN_EXP - LDB_MANT_PRECISION
# define LDB_MAX_EXP 16383
# define LDB_MAX_POW LDB_MAX_EXP - LDB_MANT_PRECISION

/*
**functions
*/
double						compose_double(
	char		sign,
	uint64_t	mant,
	uint16_t	bias_exp);

double						compose_inf(
	char		sign);

long double					compose_ldouble(
	char		sign,
	uint64_t	times,
	uint16_t	bias_exp);

double						compose_minf(void);

double						compose_nan(void);

double						compose_pinf(void);

void						decompose_ldouble(
	long double const	*p_val,
	t_s_dfp				*p_ret);

void						decompose_double(
	double const	*p_val,
	t_s_dfp			*p_ret);

uint16_t					exp_bias_d(
	int32_t		pow);

uint16_t					exp_bias_ld(
	int32_t		pow);

int32_t						exp_unbias_d(
	uint16_t	pow);

int32_t						exp_unbias_ld(
	uint16_t	pow);

long double					my_floorl(
	long	double d);

int							has_nanf(
	t_s_dfp	*dec);

int							is_dnorm(
	double	dbl);

int							is_finite(
	double	dbl);

int							is_inf(
	double	dbl);

int							is_nan(
	double	dbl);

int							is_overf(
	double	dbl);

double						make_double(
	char		s,
	uint64_t	times,
	int32_t		p);

long double					make_ldouble(
	char		sign,
	uint64_t	times,
	int32_t		pow);

#endif
