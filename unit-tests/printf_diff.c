#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define printf_diff(...) \
{\
	int		save_fd;\
	FILE	*a_fd;\
	int		b_fd;\
	int		diff_fd;\
	int		passed;\
\
	save_fd = 0;\
	passed = 0;\
	if ((save_fd = dup(1)) > 0 &&\
		(a_fd = fopen("a.txt", "w")) &&\
		(b_fd = creat("b.txt", S_IRUSR)) > 0 &&\
		dup2(b_fd, 1) > 0 &&\
		ft_printf(__VA_ARGS__) >= 0 &&\
		fprintf(a_fd, __VA_ARGS__) >= 0)\
	{\
		fclose(a_fd);\//in case we need to flush
		system("diff a.txt b.txt > res.txt");\
		if ((diff_fd = open("res.txt", O_RDONLY)) > 0)\
		{\
			passed = 1;\
			char	dummy[1];\
			int		res;\
			res = read(diff_fd, dummy, 1);\
			close(diff_fd);\
			assert_false(res);\
		}\
	}\
	if (b_fd > 0)\
		close(b_fd);\
	if (!passed)\
	{\
		fprintf(\
			stderr,\
			"file comparison failed for %s\n",\
			#__VA_ARGS__);\
	}\
	if (save_fd)\
		dup2(save_fd, 1);\
}
