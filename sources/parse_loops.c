#include "h.h"

char	*while_progress(char const *in, char* (*f_str[])(char const *))
{
	int		i;
	char	*prev;

	prev = 0;
	while (prev != in)
	{
		i = -1;
		while (f_str[++i] && prev != in)
		{
			prev = in;
			in = f_str[i](prev);
		}
	}
	return (in);
}

char	*attempt_while_progess(char const *in, char* (*f_str[])(char const *))
{
	int		i;
	char	*prev;

	i = -1;
	prev = 0;
	while (f_str[++i] && prev != in)
	{
		prev = in;
		in = f_str[i](prev);
	}
	return (in);
}

char	*attempt_all(char const *in, char* (*f_str[])(char const *))
{
	int		i;

	i = -1;
	while (f_str[++i])
	{
		in = f_str[i](in);
	}
	return (in);
}

char	*until_progess(char const *in, char* (*f_str[])(char const *))
{
	int		i;
	char	*prev;

	prev = in;
	i = -1;
	while (f_str[++i] && prev == in)
		in = f_str[i](in);
	return (in);
}