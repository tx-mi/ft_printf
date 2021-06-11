#include "../includes/ft_printf.h"

void	ft_put_precision(f_datum *datum, size_t num)
{
	(void)num;
	while ((*datum).percision)
	{
		(*datum).percision--;
		write(1, "0", 1);
	}
}
