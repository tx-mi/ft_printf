#include "../../includes/ft_printf.h"

void	ft_print(t_item *item)
{
	if (item->type == 'c' || item->type == '%')
		ft_print_chr(item);
	else if (item->type == 's')
		ft_print_str(item);
	else if (item->type == 'd' || item->type == 'i' || item->type == 'u')
		ft_print_decnum(item);
	else
		ft_print_hexnum(item);
}

int	ft_process(t_item *item)
{
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
