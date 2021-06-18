#include "ft_printf.h"

int	ft_isnum(int type)
{
	if (type == 'd' || type == 'i' || type == 'u'
		|| type == 'x' || type == 'X')
		return (1);
	return (0);
}

void	ft_print_width(t_item *item)
{
	int	sep;
	int	width;

	sep = ' ';
	width = item->width;
	if (item->zero)
	{
		if (!ft_isnum(item->type))
			sep = '0';
		else if (!item->dot)
			sep = '0';
	}
	while (width-- > 0)
	{
		write(1, &sep, 1);
		item->length++;
	}
}

int	in_specifier(char c)
{
	if (c == 'c' || c == '%' || c == 's'
		|| c == 'x' || c == 'X' || c == 'u'
		|| c == 'p' || c == 'd' || c == 'i')
		return (1);
	return (0);
}

void	ft_put_hexnum(size_t num, char *hexset)
{
	if (num / 16 == 0)
		write(1, &hexset[num % 16], 1);
	else
	{
		ft_put_hexnum(num / 16, hexset);
		ft_put_hexnum(num % 16, hexset);
	}
}
