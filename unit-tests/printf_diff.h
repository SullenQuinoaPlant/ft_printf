#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "libftprintf.h"

#define printf_diff(...) \
{\
	int		save_fd;\
	FILE	*a_fd;\
	int		b_fd;\
	int		diff_fd;\
	int		system_failure;\
	ssize_t	a_res, b_res;\
\
	save_fd = 0;\
	system_failure = 1;\
	if ((save_fd = dup(1)) > 0 &&\
		(a_fd = fopen("a.txt", "w")) &&\
		(b_fd = creat("b.txt", S_IRUSR)) > 0 &&\
		dup2(b_fd, 1) > 0 &&\
		(a_res = fprintf(a_fd, __VA_ARGS__)) &&\
		!fclose(a_fd))\
	{\
		b_res = ft_printf(__VA_ARGS__);\
		dup2(save_fd, 1);\
		close(save_fd);\
		save_fd = 0;\
		assert_true(a_res == b_res);\
		if ((system("diff a.txt b.txt > res.txt") > 0) &&\
		((diff_fd = open("res.txt", O_RDONLY)) > 0))\
		{\
			char	dummy[1];\
			int		res;\
			if ((res = read(diff_fd, dummy, 1)) >= 0)\
			{\
				assert_false(res);\
				system_failure = 0;\
			}\
			close(diff_fd);\
		}\
	}\
	if (b_fd > 0)\
		close(b_fd);\
	if (system_failure)\
	{\
		fprintf(\
			stderr,\
			"file comparison failed for %s\n",\
			#__VA_ARGS__);\
	}\
	if (save_fd)\
		dup2(save_fd, 1);\
}
