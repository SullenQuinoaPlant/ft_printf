#ifndef CONVERT_OUTPUTTERS_STUFFS_H
# define  CONVERT_OUTPUTTERS_STUFFS_H

# include "ft_printf_inner.h"

# define A_SYLLABLES 10
# define A_SYLGRPS 7
typedef struct	s_convert_a_stuff {
	t_s_pct		*chk;
	t_s_so 		syllables[A_SYLLABLES];
	t_s_sgd		syl_groups[A_SYLGRPS];
	t_s_dfp		fpd;
	char		prefix[3];
	char		zero;
	t_mib		m;
	int			excess;
	t_mib		e;
}				t_s_acs;

void	ca_prefix(int, void*);
void	ca_power0(int, void*);
void	ca_separator(int, void*);
void	ca_mantissa(int, void*);
void	ca_excess_precision(int, void*);
void	ca_to_the_power(int, void*);
void	ca_exponent(int, void*);

#define D_SYLS 3
typedef struct	s_convert_d_stuff {
	t_s_so	syls[D_SYLS];
	t_mib	b;
}				t_s_dcs;

# define E_SYLLABLES 8
# define E_SYLGRPS 4
typedef struct	s_convert_e_stuff {
	t_s_pct		*chk;
	t_s_pot		number;
	t_s_so		syls[E_SYLLABLES];
	t_s_sgd		syl_grps[E_SYLGRPS];
	int			pre;
	t_mib		exp;
	t_s_cc		p_exp;
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

# define F_SYLLABLES 7
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
void	cf_separator(int, void*);
void	cf_lowdigits(int, void*);

#endif
