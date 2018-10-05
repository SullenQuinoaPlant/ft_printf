/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 20:39:16 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/06 00:44:36 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

/*
**input string parsing:
*/
typedef char const					*(*t_parser)(
	char const *);

/*
** inpt string parsing controls:
*/
typedef char const					*(*t_pctl)(
	char const *,
	const t_parser[]);

typedef enum						e_chunk_types
{
	e_no_chk,
	e_txt_c,
	e_char_c,
	e_pct_c,
	e_ctl_chk
}									t_e_cts;

typedef struct						s_chunk_wrapper
{
	t_e_cts	type;
	void	*chk;
}									t_s_cw;

typedef struct						s_text_chunk
{
	char const	*strt;
	size_t		len;
}									t_s_txt;

typedef struct						s_character
{
	char	c;
}									t_s_char;

/*
** length of enumeration is relied upon for array declarations
*/
typedef enum						e_length_modifiers
{
	e_no_len,
	e_hh, e_h, e_l, e_ll,
	e_bigl,
	e_j, e_z, e_t,
	e_lm_sz
}									t_e_lm;

typedef struct						s_length_mod_and_pattern
{
	t_e_lm		mod;
	char		*s;
}									t_s_lmp;

/*
**length of enumeration is relied upon for array declarations
*/
typedef enum	convert_e_specifiers {
	e_no_specifier,
	e_a, e_biga,
	e_b, e_bigb,
	e_c, e_bigc,
	e_d, e_bigd,
	e_e, e_bige,
	e_f, e_bigf,
	e_g, e_bigg,
	e_i,
	e_k, e_bigk,
	e_n, e_bign,
	e_o, e_bigo,
	e_p, e_bigp,
	e_r, e_bigr,
	e_s, e_bigs,
	e_u, e_bigu,
	e_x, e_bigx,
	e_pct,
	e_cs_sz
}				t_e_cs;

/*
**length of enumeration is relied upon for array declarations
*/
typedef enum	e_types {
	e_notype,
	e_char, e_uchar, e_charptr,
	e_double, e_longdouble,
	e_int, e_uint, e_intptr,
	e_intmax_t, e_uintmax_t,
	e_long, e_ulong, e_longptr,
	e_longlong, e_ulonglong, e_longlongptr,
	e_ptrdiff_t,
	e_short, e_ushort, e_shortptr,
	e_size_t, e_ssize_t,
	e_voidptr,
	e_wchar_t, e_wchar_tptr,
	e_wint_t,
	e_types_sz
}				t_e_t;

extern size_t
	g_et_sz[];

typedef struct	s_va_arg {
	t_e_t		type;
	union		{
		int			position;
		int			count_uses;
				};
	void const	*p_val;
}				t_s_arg;

# define NO_FLAGS 0X00
# define HASH_FLAG 0X01
# define ZERO_FLAG 0X02
# define MINUS_FLAG 0X04
# define SPACE_FLAG 0X08
# define PLUS_FLAG 0X10
# define APSTR_FLAG 0X20
# define BIGCS_FLAG 0X40

typedef struct	s_percent {
	char		flags;
	int			**width;
	int			**precision;
	t_e_lm		len_mod;
	t_e_cs		specifier;
	t_s_arg		*vaarg;
}				t_s_pct;

/*output control function*/
typedef
int
	(*t_octlf)(
		void* args);

typedef struct	s_control_chunk {
	t_octlf	foo;
	void	*p_args;
}				t_s_ctl;

/*
**t_applist is a union with t_list
**	where the t_list.content is used to store the list's last element's address
*/
typedef struct	s_appendable_list {
	t_list	head;
	t_list	*tail;
}				t_s_applist;

/*parse state
**	chunks starts a list of string-building chunks
**		chunk types are listed in enum e_chunk_types
**	p_req_args points to a list of arguments to retrieve from the va_list
**	p_known_vals is a list that stores conversion information retrieved from the formatting string
*/
typedef struct	s_parse_state {
	t_s_applist		chunks;
	t_list			*p_req_args;
	t_list			*p_known_vals;
	unsigned int	free_arg_count;
	unsigned int	dollar_count;
	unsigned int	max_arg_pos;
	int				errored;
}				t_s_ps;

typedef enum	e_dollar_convention {
	e_no_dollar_convention,
	e_no_dollar,
	e_mix_dollar,
	e_all_dollar
}				t_e_dc;

/*output state
**	output_len holds number of chars written since last reset.
*/
typedef struct	s_output_state {
	size_t		output_len;
	int			fd;
	size_t		apstr_grp;
	int			apstr_pos;
	char		apstr_c;
	int			errored;
}				t_s_os;

/*enum length is relied upon to declare arrays*/
enum			e_output_index {
	e_prefix,
	e_root,
	e_oi_sz
};

/*enum is relied upon for array declaration*/
enum			e_pad_pos {
	e_pp_left,
	e_pp_middle,
	e_pp_right,
	e_pp_sz
};

typedef int	(*t_outputter)(void *stuff);

/*t_outputter_array*/
typedef t_outputter const	(t_oa)[e_oi_sz];

/*t_syllable_group_boundaries*/
typedef int const	(t_sgb)[e_oi_sz];

/*e_syllable_output_type 
**	contiguous characters (cc)
**	character (c)
**	functions (f)
**	their apstrophe-flag variants (_apstr_)
*/
typedef enum	e_sot {
	e_sot_cc,
	e_sot_c,
	e_sot_apstr_cc,
	e_sot_apstr_c,
	e_sot_f,
	e_sot_apstr_f
}				t_e_sot;

/*syllable output function*/
typedef int		(*t_sof)(size_t len, void *arg);

typedef struct	s_syllable_output {
	size_t		len;
	enum e_sot	type;
	union 		{
		char		*cc;
		char		c;
		struct		{
			t_sof		f;
			void		*arg;
					};
				};
}				t_s_so;

/*
**number of digits to group by for APSTR_FLAG
*/
# define APSTR_FLAG_DECIMAL_GROUP 3
# define AF_DG APSTR_FLAG_DECIMAL_GROUP
# define APSTR_FLAG_DECIMAL_SEPARATOR '\''
# define AF_DS APSTR_FLAG_DECIMAL_SEPARATOR
# define APSTR_FLAG_GROUP_BYTWO 2
# define AF_2G APSTR_FLAG_GROUP_BYTWO  
# define APSTR_FLAG_GROUP_BYFOUR 4
# define AF_4G APSTR_FLAG_GROUP_BYFOUR
# define APSTR_FLAG_BYTE_SEPARATOR '_'
# define AF_BS APSTR_FLAG_BYTE_SEPARATOR 

typedef struct	s_syllable_group_descriptor {
	t_s_so		*first;
	size_t		sz;
	size_t		apstr_grp;
	int			apstr_pos;
	char		apstr_c;
}				t_s_sgd;

typedef void	(*t_stuffer)(int index, void *stf);

typedef struct	s_va_list
{
	va_list		l;
}				t_s_vl;
#endif
