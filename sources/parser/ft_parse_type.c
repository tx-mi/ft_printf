#include "../../includes/ft_printf.h"

static int	in_specifier(char c)
{
	if (c == 'c' || c == '%' || c == 's'
		|| c == 'x' || c == 'X' || c == 'u'
		|| c == 'p' || c == 'd' || c == 'i')
		return (1);
	return (0);
}

static void	add_string(t_item *item, va_list *ap)
{
	char	*string;

	string = va_arg(*ap, char *);
	if (!string)
		string = "(null)";
	item->string = string;
	item->size = ft_strlen(string);
}

static void	add_decimalnum(t_item *item, va_list *ap)
{
	long long int	num;

	num = va_arg(*ap, int);
	if (num < 0)
	{
		item->sign = -1;
		item->length++;
		num = -num;
	}
	else
		item->sign = 1;
	item->num = num;
	item->size = ft_count_numsize(num, 10);
	item->length += item->size;
}

static void	add_un_num(t_item *item, va_list *ap, char c)
{
	item->un_num = va_arg(*ap, unsigned int);
	if (c == 'u')
		item->size = ft_count_numsize(item->un_num, 10);
	else
		item->size = ft_count_numsize(item->un_num, 16);
	item->length = item->size;
}

void	ft_parse_type(t_item *item, char **format_str, va_list *ap)
{
	int	c;

	c = **format_str;
	if (in_specifier(c))
	{
		if (c == 'c')
		{
			item->chr = va_arg(*ap, int);
			item->size++;
		}
		else if (c == 's')
			add_string(item, ap);
		else if (c == 'd' || c == 'i')
			add_decimalnum(item, ap);
		else if (c == 'x' || c == 'X' || c == 'u')
			add_un_num(item, ap, c);
		else if (c == 'p')
		{
			item->pointer = va_arg(*ap, unsigned long int);
			item->size = ft_count_numsize(item->un_num, 16) + 2;
			item->length = item->size;
		}
		item->type = c;
		(*format_str)++;
	}
}
