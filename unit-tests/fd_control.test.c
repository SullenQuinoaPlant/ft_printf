#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

#include "libftprintf.h"

static
int
	assert_file_is_empty(
		char const *filename)
{
	int	sys_fail;
	int	fd;
	int	res;

	sys_fail = 1;
	if ((fd = open(filename, O_RDONLY)) > 0)
	{
		char	dummy[1];
		if ((res = read(fd, dummy, 1)) >= 0)
		{
			assert_false(res);
			sys_fail = 0;
		}
		close(fd);
		if (res > 0)
			printf("ref file %s and test file"
				" have different contents",
				filename);
	}
	return (sys_fail);
}

int	declare_tests_and_run(int all_of, char *these[])
{
	T(test1,
		int	fd[4];
		int	sys_fail;
		int	i;

		sys_fail = 1;
		if ((fd[0] = creat("a.txt", O_WRONLY)) != -1 &&
			(fd[1] = dup(fd[0])) != -1 &&
			(fd[2] = dup(fd[0])) != -1 &&
			(fd[3] = dup(fd[0])) != -1)
		{
			ft_printf(
				"%{>*}bla""%{>*}bla""%{>*}bla"
				"%{>*}bla",
				fd[0], fd[1], fd[2], fd[3]);
			if (
				system(
					"diff fd_control_test1.ref a.txt"
					" >res.txt"
				) >= 0)
				sys_fail = assert_file_is_empty(
							"res.txt");
		}
		for (i = 0; i < sizeof(fd)/sizeof(fd[0]); i++)
			if (fd[i] != -1)
				close(fd[i]);
	)

	T(test2,
		int	sys_fail;
		int	fd;

		sys_fail = 1;
		if ((fd = creat("a.txt", O_WRONLY)) != -1)
		{
			ft_printf("%{>*}bla", fd);
			if (
				system(
					"diff fd_control_test2.ref a.txt"
					" >res.txt"
				) >= 0)
				sys_fail = assert_file_is_empty(
							"res.txt");
		}
		if (fd != -1)
			close(fd);
	)

#define strstr(token) #token
#define str(token) strstr(token)
#define FIXED_FD 5
	T(test3,
		int	sys_fail;
		int fixed_fd;
		int	fd;

		sys_fail = 1;
		fixed_fd = -1;
		if ((fd = creat("a.txt", O_WRONLY)) != -1 &&
			(fixed_fd = dup2(fd, FIXED_FD)) != -1)
		{
			ft_printf("%{>" str(FIXED_FD) "}bla", fd);
			if (
				system(
					"diff fd_control_test3.ref a.txt"
					" >res.txt"
				) >= 0)
				sys_fail = assert_file_is_empty(
							"res.txt");
		}
		if (fd != -1)
			close(fd);
		if (fixed_fd != -1)
			close(fixed_fd);
	)
#undef FIXED_FD

	return(run_test_arr(all_of, these));
}
