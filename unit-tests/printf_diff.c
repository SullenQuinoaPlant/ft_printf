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
	int		system_failure = 1;
	ssize_t	res = 0, a_res, b_res;

	va_start(a_l, format);
	va_copy(b_l, a_l);
	if (
		(a_fd = fopen("a.txt", "w")) &&
		(a_res = vfprintf(a_fd, format, a_l)) &&
		!fclose(a_fd) && !(a_fd = 0) &&
		(save_fd = dup(1)) > 0 &&
		(b_fd = creat("b.txt", S_IRUSR | S_IWUSR)) > 0 &&
		dup2(b_fd, 1) > 0)
	{
		b_res = ft_vprintf(format, b_l);
		if (!close(b_fd))
			b_fd = -1;
		save_fd = restore_fd1(save_fd);
		if ((system("diff a.txt b.txt > res.txt") >= 0) &&
		((diff_fd = open("res.txt", O_RDONLY)) > 0))
		{
			char	dummy[1];
			if ((res = read(diff_fd, dummy, 1)) >= 0)
				system_failure = 0;
			close(diff_fd);
			if (res > 0)
			{
				printf("ref file a.txt and test file b.txt have different contents"
					" for : %s\n diff is :\n", format);
				fflush(stdout);
				system("cat res.txt");
//				printf("\n ref file a.txt is :\n");
//				system("cat -e a.txt");
//				printf("\n tst file b.txt is :\n");
//				system("cat -e b.txt");
			}
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
		skip();
	} else {
		assert_false(res);
	}
	return (system_failure);
}

#define COMMAND_BUFFER 256
int
	printf_compare(
		char const * ref_name,
		char const * format, ...) 
{
	va_list	b_l;
	int		save_fd = -1, diff_fd = -1, b_fd = -1;
	int		system_failure = 1;
	ssize_t	res = 0, b_res;

	va_start(b_l, format);
	if ((save_fd = dup(1)) > 0 &&
		(b_fd = creat("b.txt", S_IRUSR | S_IWUSR)) > 0 &&
		dup2(b_fd, 1) > 0)
	{
		b_res = ft_vprintf(format, b_l);
		save_fd = restore_fd1(save_fd);
		char	command_buffer[COMMAND_BUFFER];
		snprintf(command_buffer, COMMAND_BUFFER,
			"diff %s b.txt > res.txt", ref_name);
		if ((system(command_buffer) >= 0) &&
		((diff_fd = open("res.txt", O_RDONLY)) > 0))
		{
			char	dummy[1];
			if ((res = read(diff_fd, dummy, 1)) >= 0)
				system_failure = 0;
			close(diff_fd);
			if (res > 0)
			{
				printf("ref file %s and test file b.txt have different contents for : %s\n diff is :\n", ref_name, format);
				system("cat res.txt");
				fflush(stdout);
//				printf("\n ref file a.txt is :\n");
//				system("cat -e a.txt");
//				printf("\n tst file b.txt is :\n");
//				system("cat -e b.txt");
			}
		}
	}
	if (b_fd >= 0)
		close(b_fd);
	if (save_fd >= 0)
		restore_fd1(save_fd);
	va_end(b_l);
	if (system_failure)
	{
		fprintf(
			stderr,
			"file comparison failed for %s\n",
			format);
		skip();
	} else {
		assert_false(res);
	}
	return (system_failure);
}
