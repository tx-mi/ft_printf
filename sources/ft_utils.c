#include "../includes/ft_printf.h"

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
	if (item->zero && !item->dot)
		sep = '0';
	while (width-- > 0)
	{
		write(1, &sep, 1);
		item->length++;
	}
}
