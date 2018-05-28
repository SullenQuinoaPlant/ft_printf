#include "h.h"

void	my_clean_free(void *data, size_t sz)
{
	ft_bzero(data, sz);
	free(data);
}

void	my_super_clean_free(void **data, size_t sz)
{
	my_clean_free(*data, sz);
	*data = 0;
}
