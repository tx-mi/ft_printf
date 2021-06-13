#include "../../includes/ft_printf.h"

void	ft_print_chr(t_item *item)
{
	int	c;

	c = item->chr;
	if (!c && item->type == '%')
		c = '%';
	write(1, &c, 1);
}

void	ft_print_str(t_item *item)
{
	if (item->dot)
	{
		while (item->dot && item->precision-- && *item->string)
		{
			write(1, &(*item->string), 1);
			item->string++;
			item->length++;
		}
	}
	else
	{
		ft_putstr_fd(item->string, 1);
		item->length += ft_strlen(item->string);
	}
}
