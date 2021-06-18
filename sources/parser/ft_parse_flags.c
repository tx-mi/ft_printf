#include "ft_printf.h"

void	ft_parse_flags(t_item *item, char **format_str)
{
	while (**format_str == '-' || **format_str == '0')
	{
		if (**format_str == '-' && !item->minus)
		{
			item->minus = 1;
			item->zero = 0;
		}
		else if (**format_str == '0' && !item->minus && !item->zero)
			item->zero = 1;
		(*format_str)++;
	}
}
