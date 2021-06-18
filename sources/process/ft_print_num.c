#include "ft_printf.h"

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

static void	ft_print_hexnum(t_item *item)
{
	size_t	num;
	char	*hexset;

	num = item->pointer;
	hexset = "0123456789abcdef";
	if (item->type != 'p')
		num = item->un_num;
	if (item->type == 'X')
		hexset = "0123456789ABCDEF";
	display_precision(item);
	if (item->type == 'p')
		write(1, "0x", 2);
	if (!item->stupid)
		ft_put_hexnum(num, hexset);
	else if (item->def_w && item->type != 'p')
		write(1, " ", 1);
	else
		item->length--;
}

static void	ft_print_decnum(t_item *item)
{
	size_t	num;

	num = item->num;
	if (item->type == 'u')
		num = item->un_num;
	if (item->sign == -1)
		write(1, "-", 1);
	display_precision(item);
	if (!item->stupid)
		ft_putnbr_recursive(num);
	else if (item->def_w)
		write(1, " ", 1);
	else
		item->length--;
}

void	ft_print_num(t_item *item)
{
	int	type;

	type = item->type;
	if (type == 'd' || type == 'i' || type == 'u')
		ft_print_decnum(item);
	else
		ft_print_hexnum(item);
}
