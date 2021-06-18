#include "ft_printf.h"

static void	is_stupid(t_item *item)
{
	size_t	num;

	if (ft_isnum(item->type))
	{
		if (item->type == 'd' || item->type == 'i')
			num = item->num;
		else
			num = item->un_num;
		if (item->dot && !item->precision && !num)
			item->stupid = 1;
	}
	else if (item->type == 'p' && item->dot && !item->pointer)
		item->stupid = 1;
}

void	ft_print(t_item *item)
{
	if (item->type == 'c' || item->type == '%')
		ft_print_chr(item);
	else if (item->type == 's')
		ft_print_str(item);
	else
		ft_print_num(item);
}

int	ft_process(t_item *item)
{
	is_stupid(item);
	ft_recount_precision(item);
	ft_recount_width(item);
	if (item->minus)
	{
		ft_print(item);
		ft_print_width(item);
	}
	else
	{
		ft_print_width(item);
		ft_print(item);
	}
	return (item->length);
}
