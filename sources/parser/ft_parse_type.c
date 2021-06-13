#include "../../includes/ft_printf.h"

static int	in_specifier(char c)
{
	if (c == 'c' || c == '%' || c == 's'
		|| c == 'x' || c == 'X' || c == 'u'
		|| c == 'p' || c == 'd' || c == 'i')
		return (1);
	return (0);
}

static void	add_decimal_num(t_item *item, va_list *ap)
{
	long long int	num;

	num = va_arg(*ap, int);
	if (num < 0)
	{
		item->sign = -1;
		num = -num;
	}
	else
		item->sign = 1;
	item->num = num;
	item->numsize = ft_count_numsize(num, 10);
}

void	ft_parse_type(t_item *item, char **format_str, va_list *ap)
{
	int	c;

	c = **format_str;
	if (in_specifier(c))
	{
		if (c == 'c')
			item->chr = va_arg(*ap, int);
		else if (c == 's')
			item->string = va_arg(*ap, char *);
		else if (c == 'd' || c == 'i')
			add_decimal_num(item, ap);
		else if (c == 'x' || c == 'X')
		{
			item->un_num = va_arg(*ap, unsigned int);
			item->numsize = ft_count_numsize(item->un_num, 16);
		}
		else if (c == 'u')
		{
			item->un_num = va_arg(*ap, unsigned int);
			item->numsize = ft_count_numsize(item->un_num, 10);
		}
		else if (c == 'p')
		{
			item->pointer = va_arg(*ap, unsigned long int);
			item->numsize = ft_count_numsize(item->un_num, 16);
		}
		item->type = c;
		(*format_str)++;
	}
}
