#include "h.h"

void	my_clean_free(void *data, size_t sz)
{
	ft_bzero(data, sz);
	free(data);
}
