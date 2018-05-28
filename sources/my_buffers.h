#ifndef MY_BUFFERS_H
# define MY_BUFFERS_H

# define BIGGEST_BASE2 (sizeof(uintmax_t) * 8)
# define BIGGEST_SIGNED BIGGEST_BASE2 + 1
# define BIGGEST_SIGNED_STRING BIGGEST_SIGNED + 1

typedef struct	s_indexed_buffer {
	size_t  len;
	char	b[BIGGEST_SIGNED_STRING];
}				t_s_ib;

#endif
