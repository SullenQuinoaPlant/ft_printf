#define HOW_MANY_TESTS 10
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "cmocka/my_overlay.h"
#include "libftprintf.h"
#include "libgetnextline.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	char	**files;
	files = ((char*[]){
		"a_conversions.test.c",
		"a_conversions.test.execution.stamp",
		"b_achar.ref",
		"B_achar.ref",
		"b_conversions.test.c",
		"b_conversions.test.execution.stamp",
		"boilerplate.c",
		"b_twochars.ref",
		"B_twochars.ref",
		"c_conversions.test.c",
		"c_conversions.test.execution.stamp",
		"convert_decompose_floating_point.donttest.c",
		"d_conversions.test.c",
		"d_conversions.test.execution.stamp",
		"e_conversions.test.c",
		"e_conversions.test.execution.stamp",
		"f_conversions.test.c",
		"f_conversions.test.execution.stamp",
		"fd_control.test.c",
		"fd_control.test.execution.stamp",
		"g_conversions.test.c",
		"g_conversions.test.execution.stamp",
		"identity.test.c",
		"main.test.c",
		"main.test.execution.stamp",
		"Makefile",
		"n_conversions.test.c",
		"n_conversions.test.execution.stamp",
		"o_conversions.test.c",
		"o_conversions.test.execution.stamp",
		"o_test27.ref",
		"o_test28.ref",
		"o_test29.ref",
		"o_test30.ref",
		"o_test31.ref",
		"p_conversions.test.c",
		"p_conversions.test.execution.stamp",
		"plain_text_output.test.c",
		"plain_text_output.test.execution.stamp",
		"printf_diff.c",
		"res.txt",
		"s_conversions.test.c",
		"s_conversions.test.execution.stamp",
		"s_test_unicode1.ref",
		"s_test_unicode2.ref",
		"test_file",
		"u_conversions.test.c",
		"u_conversions.test.execution.stamp",
		"x_conversions.test.c",
		"x_conversions.test.execution.stamp",
		0
	});

	#define COMMAND_SZ 256
	T(identities,
		char	**file;
		int		in_fd;
		int		out_fd;
		int		res_fd;
		char	*buf;
		int		r;
		char	command[COMMAND_SZ];

		r = 0;
		file = files;
		while (*file && !r)
		{
			if ((in_fd = open(*file, O_RDONLY)) > 0 &&
				(out_fd = open("identity_res",
					O_RDWR | O_CREAT | O_TRUNC,
					S_IRUSR | S_IWUSR)) > 0)
			{
				while ((r = get_next_line(in_fd, &buf)))
				{
					ft_printf("%{>*}%s\n", out_fd, buf);
					free(buf);
				}
				if (!r &&
					(r = snprintf(command,
						COMMAND_SZ,
						"diff %s identity_res > identity_diff",
						*file)) >= 0 &&
					(r = system(command)) >= 0 &&
					(res_fd = open("identity_diff",
						O_RDONLY)) >= 0)
				{
					char	dummy;
					if ((r = read(res_fd, &dummy, 1)) > 0)
					{
						if (snprintf(command,
							COMMAND_SZ,
							"echo \"failed on %s\n\"",
							*file) > 0)
							system(command);
						system("cat identity_diff");
					}
					close(res_fd);
					assert_true(r <= 0);
					r = r < 0 ? r : 0;
				}
				file++;
			}
			if (in_fd >= 0)
				close(in_fd);
			if (out_fd >= 0)
				close(out_fd);
		}
	)
	return(run_test_arr(all_of, these));
}
