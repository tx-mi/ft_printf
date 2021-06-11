#include "../includes/libft.h"

size_t	ft_count_numsize(size_t num)
{
	size_t	res;

	res = 0;
	while (num)
	{
		res++;
		num /= 10;
	}
	return (res);
}
