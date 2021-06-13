#include "../../includes/ft_printf.h"

void	ft_parse_width(t_item *item, char **format_str, va_list *ap)
{
	int	width;

	width = 0;
	if (**format_str == '*')
	{
		item->width = va_arg(*ap, int);
		(*format_str)++;
	}
	while (ft_isdigit(**format_str))
	{
		item->width *= 10;
		item->width += (**format_str - '0');
		(*format_str)++;
	}	
	while (width)
	{
		(*format_str)++;
		width /= 10;
	}
}
