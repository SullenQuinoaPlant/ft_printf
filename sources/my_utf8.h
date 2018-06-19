#ifndef MY_UTF8_H
# define  MY_UTF8_H


int
	as_utf8seq(
		wchar_t val, int char_lim,
		char *put);

size_t
	str_to_utf8(
		wchar_t * const	*str,
		char 			*put,
		size_t 			len);

int
	true_utf8seq(
		wchar_t val, char *put);

endif
