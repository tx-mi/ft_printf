#include "ft_printf.h"

static void	check_for_negative(t_item *item)
{
	if (item->precision >= 0)
		item->dot = 1;
	else
		item->precision = 0;
}

void	ft_parse_precision(t_item *item, char **format_str, va_list *ap)
{
	int	precision;

	precision = 0;
	if (**format_str == '.')
	{
		(*format_str)++;
		if (**format_str == '*')
		{
			item->precision = va_arg(*ap, int);
			(*format_str)++;
		}
		while (ft_isdigit(**format_str))
		{
			item->precision *= 10;
			item->precision += (**format_str - '0');
			(*format_str)++;
		}
		check_for_negative(item);
		while (precision)
		{
			(*format_str)++;
			precision /= 10;
		}
	}
}
