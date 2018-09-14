#include "inner.h"

void	ft_cleanfree(void *data, size_t sz)
{
	ft_bzero(data, sz);
	free(data);
}

void	my_super_clean_free(void **data, size_t sz)
{
	ft_cleanfree(*data, sz);
	*data = 0;
}
