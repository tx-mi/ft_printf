#include "../includes/ft_printf.h"

void	ft_put_width(f_datum *datum, char c, size_t num)
{
	(void)num;
	while ((*datum).width)
	{
		(*datum).width--;
		write(1, &c, 1);
	}
}
