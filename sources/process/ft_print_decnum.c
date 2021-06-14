#include "../../includes/ft_printf.h"

static int	stupid(t_item *item, size_t num)
{
	if (item->dot && !item->precision && !num)
		return (1);
	return (0);
}

static void	display_precision(t_item *item)
{
	int	precision;

	precision = item->precision;
	while (precision-- > 0)
	{
		write(1, "0", 1);
		item->length++;
	}
}

void	ft_print_decnum(t_item *item)
{
	size_t	num;

	num = item->num;
	if (item->type == 'u')
		num = item->un_num;
	if (item->sign == -1)
		write(1, "-", 1);
	display_precision(item);
	if (!stupid(item, num))
		ft_putnbr_recursive(num);
	else if (item->width)
		write(1, " ", 1);
}
