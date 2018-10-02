/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_stuffs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:10:59 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/02 00:14:17 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_OUTPUTTERS_STUFFS_H
# define  CONVERT_OUTPUTTERS_STUFFS_H

# include "inner.h"

# define A_SYLLABLES 10
# define A_SYLGRPS 7
typedef struct	s_convert_a_stuff {
	t_s_pct		*chk;
	t_s_so 		syllables[A_SYLLABLES];
	t_s_sgd		syl_groups[A_SYLGRPS];
	t_s_dfp		fpd;
	uint64_t	aligned_mant;
	char		prefix[3];
	char		zero;
	t_vtb_mib	m;
	int			excess;
	t_vtb_mib	e;
}				t_s_acs;

void	ca_prefix(int, void*);
void	ca_power0(int, void*);
void	ca_separator(int, void*);
void	ca_mantissa(int, void*);
void	ca_excess_precision(int, void*);
void	ca_to_the_power(int, void*);
void	ca_exponent(int, void*);

# define B_SYLS 7
# define B_SYLGRPS 2
typedef struct	s_convert_b_stuff {
	t_s_pct		*chk;
	t_s_so		syls[B_SYLS];
	t_s_sgd		syl_grps[B_SYLGRPS];
	void		*p_mem;
	size_t		mem_chk;
	size_t		mem_chk_len;
	ssize_t		chk_count;
	t_vtb_mib	addr;
	char const	*base;
	t_vtb_mib	val;
	t_s_vtb_cc	val_p;
}				t_s_bcs;

void	cb_addrprefix(int, void*);
void	cb_addr(int, void*);
void	cb_addrpostfix(int, void*);
void	cb_mem(int, void*);

int		tsof_bmem(size_t len, void *arg);

#define D_SYLS 6
typedef struct	s_convert_d_stuff {
	t_s_pct	*chk;
	t_s_so	syls[D_SYLS];
	t_vtb_mib	b;
	t_s_vtb_cc	p_b;
	int		pre;
	t_s_sgd	group;
}				t_s_dcs;

void	cd_sign(int, void*);
void	cd_prefix(int, void*);
void	cd_digits(int, void*);

# define E_SYLLABLES 8
# define E_SYLGRPS 4
typedef struct	s_convert_e_stuff {
	t_s_pct		*chk;
	t_s_pot		number;
	t_s_so		syls[E_SYLLABLES];
	t_s_sgd		syl_grps[E_SYLGRPS];
	int			pre;
	t_vtb_mib		exp;
	t_s_vtb_cc		p_exp;
}				t_s_ecs;

void	ce_sign(int, void*);
void	ce_zero(int, void*);
void	ce_separator(int, void*);
void	ce_lowdigits(int, void*);
void	ce_to_the_power(int, void*);
void	ce_exponent_sign(int, void*);
void	ce_exponent_pad(int, void*);
void	ce_exponent(int, void*);

int		ce_prefix(void *stf);
int		ce_body(void *stf);

# define F_SYLLABLES 9
# define F_SYLGRPS 3

typedef struct	s_convert_f_stuff {
	t_s_pct		*chk;
	t_s_pot		number;
	t_s_so		syls[F_SYLLABLES];
	t_s_sgd		syl_grps[F_SYLGRPS];
	int			pre;
}				t_s_fcs;

void	cf_sign(int, void*);
void	cf_highdigits(int, void*);
void	cf_powerzero(int, void*);
void	cf_separator(int, void*);
void	cf_zeros(int, void*);
void	cf_lowdigits(int, void*);

# define G_SYLLABLES 11
# define G_SYLGRPS 4
# define G_ESYLS 11
# define G_EGRPS 4
# define G_FSYLS 9
# define G_FGRPS 4

typedef struct	s_convert_g_stuff {
	t_s_pct		*chk;
	t_s_pot		number;
	t_s_so		syls[G_SYLLABLES];
	t_s_sgd		syl_grps[G_SYLGRPS];
	int			pre;
	t_vtb_mib		exp;
	t_s_vtb_cc		p_exp;
}				t_s_gcs;

void	cg_esign(int, void*);
void	cg_ezero(int, void*);
void	cg_eseparator(int, void*);
void	cg_elowdigits(int, void*);
void	cg_eto_the_power(int, void*);
void	cg_eexponent_sign(int, void*);
void	cg_eexponent_pad(int, void*);
void	cg_eexponent(int, void*);
void	cg_esetgroups(int, void*);

void	cg_fsign(int, void*);
void	cg_fhighdigits(int, void*);
void	cg_fpowerzero(int, void*);
void	cg_fseparator(int, void*);
void	cg_fzeros(int, void*);
void	cg_flowdigits(int, void*);
void	cg_fsetgroups(int, void*);

#define BK_SYLS 9
#define BK_STR_SYLS 6
typedef struct	s_convert_big_k_stuff {
	t_s_pct		*chk;
	t_s_so		syls[BK_SYLS];
	struct tm	*tm
	char		year[4];
	char		month[2];
	char		day[2];
}				t_s_bkcs;

# define O_SYLS 6
typedef struct	s_convert_o_stuff {
	t_s_pct		*chk;
	t_s_so		syls[O_SYLS];
	t_vtb_mib	b;
	t_s_vtb_cc	p_b;
	int			pre;
	t_s_sgd		group;
}				t_s_ocs;

void	co_prefix(int, void*);
void	co_hashfix(int, void*);
void	co_digits(int, void*);

#define P_SYLS 6
typedef struct	s_convert_p_stuff {
	t_s_pct	*chk;
	t_s_so	syls[P_SYLS];
	t_vtb_mib	b;
	t_s_vtb_cc	p_b;
	int		pre;
	t_s_sgd	group;
}				t_s_pcs;

void	cp_sign(int, void*);
void	cp_hashfix(int, void*);
void	cp_prefix(int, void*);
void	cp_digits(int, void*);

# define S_SYLLABLES 4
typedef struct	s_convert_s_stuff {
	t_s_pct		*chk;
	t_s_so		syls[S_SYLLABLES];
	int			pre;
}				t_s_scs;

int		tsof_hash_charstr(size_t len, void *str)
int		tsof_hash_wcharstr(size_t len, void *str);
int		tsof_wcharstr(size_t len, void *str);

#define U_SYLS 5
typedef struct	s_convert_unsigned_stuff {
	t_s_pct	*chk;
	t_s_so	syls[U_SYLS];
	t_vtb_mib	b;
	t_s_vtb_cc	p_b;
	int		pre;
	t_s_sgd	group;
}				t_s_ucs;

void	cu_prefix(int, void*);
void	cu_digits(int, void*);

#define X_SYLS 6
typedef struct	s_convert_x_stuff {
	t_s_pct		*chk;
	t_s_so		syls[X_SYLS];
	char		hashfix[2];
	t_vtb_mib	b;
	t_s_vtb_cc	p_b;
	int			pre;
	t_s_sgd		group;
}				t_s_xcs;

void	cx_hashfix(int, void*);
void	cx_prefix(int, void*);
void	cx_digits(int, void*);

#endif
