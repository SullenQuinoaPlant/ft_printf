#ifndef H_H
# define H_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>


/*input string parsing:*/
typedef enum	e_chunk_types {
	e_ts_txt,
	e_ts_char,
	e_ts_pct
}				t_e_cts;

typedef struct	s_wrap_format_chunks {
	t_e_cts	type;
	void	*data;
}				t_s_wfc;

typedef struct	s_text_chunk {
	char	*strt;
	size_t	len;
}				t_s_txt;

typedef struct	s_character {
	char	c;
}				t_s_char;

typedef struct	s_percent {
	unsigned char	flags;
	int				*width;
	int				*precision;
	t_s_arg			*convertee;
}				t_s_pct;

typedef enum	e_dollar_convention {
	e_no_status,
	e_no_dollar,
	e_mix_dollar,
	e_all_dollar
}				t_e_dc;

/*parse status
**	out_bits_anchor starts a list of string-building chunks
**		chunk types are listed in enum e_chunk_types
**		the t_list.content is used to store the list's last element's address
**	p_req_args points to a list of arguments to retrieve from the va_list
**	p_literal_vals is a list that stores conversion information retrieved from
**	 the formatting string, values are allocated on the heap
**	enum e_dollar_convention	dollar, indicates use of dollar sign
*/
typedef struct	s_parse_state {
	t_list			out_bits_anchor;
	t_list			*p_req_args;
	t_list			*p_literal_vals;
	unsigned int	arg_count;
	unsigned int	dollar_count;
}				t_s_ps;

extern t_s_ps g_ps;

/*parse function constants:*/
enum			e_string_traversal {
	e_prev,
	e_last
};

/*conversion arguments:*/
typedef enum	e_types {
	e_char, e_uchar,
	e_short, e_ushort,
	e_int,	e_uint,
	e_long, e_ulong,
	e_longlong, e_ulonglong,
	e_float,
	e_double,
	e_size_t, e_ssize_t
}				t_e_t;

typedef struct	s_va_arg {
	t_e_t		type;
	union		{
		int			position;
		int			count_uses;
				};
	void const	*arg;
}				t_s_arg;

typedef struct	s_va_arg_array_info {
	size_t			length;
	t_s_arg const	*array;
}				t_s_args;

#endif
