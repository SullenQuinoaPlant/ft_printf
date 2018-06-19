#ifndef MY_UTF8_H
# define  MY_UTF8_H

int
	as_utf8seq(
		wchar_t val, int char_lim,
		char *put);

int
	true_utf8seq(
		wchar_t val, char *put);

endif
