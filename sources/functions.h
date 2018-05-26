#ifndef FUNCTIONS_H
# define FUNCTIONS_H

size_t	my_lowvaltobuffer(uintmax_t val, char const * const basestr,
	char *b_end);

# define NEG_SIGNED 0x00
# define ALL_SIGNED 0x01
# define ABS_SIGNED 0x02
size_t	my_signedvaltobuffer(intmax_t val, char const * const basestr,
	char *b_end, unsigned int sign_flag);

size_t	my_valtobuffer(uintmax_t val, char const * const basestr,
	char *b_end);

#endif
