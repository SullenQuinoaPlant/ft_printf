#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "libftprintf.h"

static int	restore_fd1(int save_fd)
{
	if (dup2(save_fd, 1) == -1)
		return (save_fd);
	close(save_fd);
	return (-1);
}

int	printf_diff(char const * format, ...) 
{
	va_list	a_l, b_l;
	int		save_fd = -1, diff_fd = -1, b_fd = -1;
	FILE	*a_fd;
	int		system_failure;
	ssize_t	a_res, b_res;

	system_failure = 1;
	va_start(a_l, format);
	va_copy(b_l, a_l);
	if ((save_fd = dup(1)) > 0 &&
		(a_fd = fopen("a.txt", "w")) &&
		(b_fd = creat("b.txt", S_IRUSR)) > 0 &&
		dup2(b_fd, 1) > 0 &&
		(a_res = vfprintf(a_fd, format, a_l)))
	{
		b_res = ft_vprintf(format, b_l);
		save_fd = restore_fd1(save_fd);
		assert_true(a_res == b_res);
		if ((system("diff a.txt b.txt > res.txt") > 0) &&
		((diff_fd = open("res.txt", O_RDONLY)) > 0))
		{
			char	dummy[1];
			int		res;
			if ((res = read(diff_fd, dummy, 1)) >= 0)
			{
				assert_false(res);
				system_failure = 0;
			}
			close(diff_fd);
		}
	}
	if (b_fd >= 0)
		close(b_fd);
	if (save_fd >= 0)
		restore_fd1(save_fd);
	if (a_fd)
		fclose(a_fd);
	va_end(a_l); va_end(b_l);
	if (system_failure)
	{
		fprintf(
			stderr,
			"file comparison failed for %s\n",
			format);
	}
	return (system_failure);
}
