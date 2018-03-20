#ifndef H_H
# define H_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>


/*input string parsing:*/
enum			e_chunk_types {
	e_tsTxt,
	e_tsChar,
	e_tsPct
}				t_eChunkT;

typedef struct	s_wrap_format_chunks {
	t_eChunkT	type;
	void		*data;
}				t_sWFC;

typedef struct	s_text_chunk {
	char	*strt;
	size_t	len;
}				t_sTxt;

typedef struct	s_character {
	char	c;
}				t_sChar;

typedef struct	s_percent {
	unsigned char	flags;
	int				*width;
	int				*precision;
	size_t			arg_index;
}				t_sPct;

/*convesion arguments:*/
enum			e_types {
	e_char, e_uchar,
	e_short, e_ushort,
	e_int,	e_uint,
	e_long, e_ulong,
	e_longlong, e_ulonglong,
	e_float,
	e_double,
	e_size_t, e_ssize_t
}				t_eTypes;

typedef struct	s_va_arg {
	t_eTypes	type;
	int			count_uses;
	void const	*arg;
}				t_sArg;

typedef struct	s_va_arg_array_info {
	size_t			length;
	t_sArg const	*array;
}				t_sArgs;

#endif
