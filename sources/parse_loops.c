#include "ft_printf_inner.h"

char const	*while_progress(
			char const *in,
			char const * (*const *f_str)(char const *))
{
	int			i;
	char const	*prev;

	prev = 0;
	while (prev != in)
	{
		i = -1;
		prev = in;
		while (f_str[++i] && prev == in)
			in = f_str[i](prev);
	}
	return (in);
}

char const	*attempt_while_progress(
			char const *in,
			char const * (*const *f_str)(char const *))
{
	int			i;
	char const 	*prev;

	i = -1;
	prev = 0;
	while (f_str[++i] && prev != in)
	{
		prev = in;
		in = f_str[i](prev);
	}
	return (in);
}

char const	*attempt_all(
	char const *in,
	char const * (*const *f_str)(char const *))
{
	int		i;

	i = -1;
	while (f_str[++i])
	{
		in = f_str[i](in);
	}
	return (in);
}

char const	*until_progress(
	char const *in,
	char const * (*const *f_str)(char const *))
{
	int			i;
	char const	*prev;

	prev = in;
	i = -1;
	while (f_str[++i] && prev == in)
		in = f_str[i](in);
	return (in);
}
