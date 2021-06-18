#include "ft_printf.h"

static void	check_for_negative(t_item *item)
{
	if (item->width < 0)
	{
		item->minus = 1;
		item->zero = 0;
		item->width *= -1;
	}
}

void	ft_parse_width(t_item *item, char **format_str, va_list *ap)
{
	int	width;

	width = 0;
	if (**format_str == '*')
	{
		item->width = va_arg(*ap, int);
		(*format_str)++;
		check_for_negative(item);
	}
	while (ft_isdigit(**format_str))
	{
		item->width *= 10;
		item->width += (**format_str - '0');
		(*format_str)++;
	}	
	if (item->width)
		item->def_w = 1;
	while (width)
	{
		(*format_str)++;
		width /= 10;
	}
}
