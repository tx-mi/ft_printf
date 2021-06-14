#include "../../includes/ft_printf.h"

static void	print_num(size_t num)
{
	// convert to 16base num
	ft_putnbr_recursive(num);
}

void	ft_print_hexnum(t_item *item)
{
	int	tp;
	size_t	num;

	num = item->un_num;
	tp = item->type;
	if (tp == 'p')
	{
		ft_putstr_fd("0x", 1);
		num = item->pointer;
	}
	print_num(num);
}
