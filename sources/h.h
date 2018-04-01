#ifndef H_H
# define H_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>


/*input string parsing:*/
typedef char	*(t_parser)(char const *);

typedef enum	e_chunk_types {
	e_no_c_type,
	e_txt_c,
	e_char_c,
	e_pct_c
}				t_e_cts;

typedef struct	s_chunk_wrapper {
	t_e_cts	type;
	void	*data;
}				t_s_cw;

typedef struct	s_text_chunk {
	char	*strt;
	size_t	len;
}				t_s_txt;

typedef struct	s_character {
	char	c;
}				t_s_char;

/*length of enumeration is relied upon for array declarations
**	change with care
*/
typedef enum	e_length_modifiers {
	e_no_len,
	e_hh, e_h, e_l, e_ll,
	e_bigl,
	e_j, e_z, e_t,
	e_lm_sz
}				t_e_lm;

typedef struct	s_length_mod_and_pattern {
	t_e_lm	mod;
	char	*str;
}				t_s_lmp;

/*order of the enumeration is relied upon in percent_conversion_specifier()
**length of enumeration is relied upon for array declarations
**	change with care
*/
typedef enum	e_conversion_specifiers {
	e_no_specifier,
	e_a, e_A,
	e_c,
	e_d,
	e_e, e_E,
	e_f, e_F,
	e_g, e_G,
	e_i,
	e_n,
	e_o,
	e_u,
	e_p,
	e_s,
	e_x, e_X,
	e_cs_sz
}				t_e_cs;

typedef enum	e_types {
	e_notype,
	e_char, e_uchar,
	e_double, e_longdouble,
	e_float,
	e_int,	e_uint,
	e_intmax_t, e_uintmax_t,
	e_long, e_ulong,
	e_longlong, e_ulonglong,
	e_ptrdiff_t,
	e_short, e_ushort,
	e_size_t, e_ssize_t,
	e_voidptr,
	e_wchar_t, e_wint_t,
	e_types_sz
}				t_e_t;

typedef struct	s_va_arg {
	t_e_t		type;
	union		{
		int			position;
		int			count_uses;
				};
	void const	*p_arg;
}				t_s_arg;

# define NO_FLAGS 0X00
# define #_FLAG 0X01
# define 0_FLAG 0X02
# define -_FLAG 0X04
# define sp_FLAG 0X08
# define +_FLAG 0X10
# define '_FLAG 0X20

typedef struct	s_percent {
	char		flags;
	int			**width;
	int			**precision;
	t_e_lm		len_mod;
	t_e_cs		specifier;
	t_s_arg		*convertee;
	char const	*str_result;
}				t_s_pct;



/*parse status
 **	chunks starts a list of string-building chunks
**		chunk types are listed in enum e_chunk_types
**		the t_list.content is used to store the list's last element's address
**	p_req_args points to a list of arguments to retrieve from the va_list
**	p_literal_vals is a list that stores conversion information retrieved from
**	 the formatting string, values are allocated on the heap
**	enum e_dollar_convention	dollar, indicates use of dollar sign
*/
typedef struct	s_parse_state {
	t_list			chunks;
	t_list			*p_req_args;
	t_list			*p_literal_vals;
	unsigned int	free_arg_count;
	unsigned int	dollar_count;
	unsigned int	max_arg_pos;
	size_t			out_str_len;
	int				errored;
}				t_s_ps;

extern t_s_ps g_ps;

typedef enum	e_dollar_convention {
	e_no_dollar_convention,
	e_no_dollar,
	e_mix_dollar,
	e_all_dollar
}				t_e_dc;

typedef struct	s_va_arg_array_info {
	size_t			length;
	t_s_arg const	*array;
}				t_s_args;

#endif
