#include "../../includes/ft_printf.h"

static void print_width(t_item *item)
{
	char	space;
	int		width;

	space = ' ';
	width = item->width;
	if (!ft_isnum(item->type))
	{
		if (item->zero && item->type != 'p')
			space = '0';
		while (item->width-- > 0)
		{
			write(1, &space, 1);
			item->length++;
		}
	}
}

void	ft_print(t_item *item)
{
	if (item->type == 'c' || item->type == '%')
		ft_print_chr(item);
	else if (item->type == 's')
		ft_print_str(item);
	else if (item->type == 'd' || item->type == 'i' || item->type == 'u')
		ft_print_decnum(item);
	// else if (item->type == 'x' || item->type == "X" || item->type == "p")
	// 	ft_print_hexnum(item);
}

int	ft_process(t_item *item)
{
	ft_recount_precision(item);
	ft_recount_width(item);
	if (item->minus)
	{
		ft_print(item);
		print_width(item);
	}
	else
	{
		print_width(item);
		ft_print(item);
	}
	return (item->length);
}
