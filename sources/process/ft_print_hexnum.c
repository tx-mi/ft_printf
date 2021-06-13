#include "../../includes/ft_printf.h"

static void	print_num(size_t num)
{
	(void)num;
}

static void	display_width(t_item *item)
{
	(void)item;
}

void	ft_print_hexnum(t_item *item)
{
	int	tp;
	size_t	num;

	num = item->un_num;
	tp = item->type;
	if (item->type != 'p' && !item->minus)
		display_width(item);
	if (tp == 'p')
	{
		ft_putstr_fd("0x", 1);
		num = item->pointer;
	}
	print_num(num);
	if (item->type != 'p')
		display_width(item);
}
