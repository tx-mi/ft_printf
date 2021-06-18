#include "ft_printf.h"

static void	check_item(t_item *item)
{
	if (item->width < 0)
		item->width = 0;
	if (item->precision < 0)
		item->precision = 0;
}

static void	if_number(t_item *item, int tp)
{
	item->width -= (item->precision + item->size);
	if (item->sign == -1)
		item->width--;
	if (item->zero && item->width && tp != 'p')
	{
		item->precision = item->width;
		item->width = 0;
	}
}

void	ft_recount_width(t_item *item)
{
	int	tp;

	tp = item->type;
	if (item->width)
	{
		if (tp == 'c' || tp == '%')
		{
			if (item->width)
				item->width--;
		}
		else if (tp == 's')
		{
			if (item->dot && (size_t)item->precision < item->size)
				item->width -= item->precision;
			else
				item->width -= item->size;
		}
		else if (ft_isnum(tp) || tp == 'p')
		{
			if_number(item, tp);
			if (tp == 'p' && item->stupid)
				item->width++;
		}
		check_item(item);
	}
}

void	ft_recount_precision(t_item *item)
{
	int	tp;

	tp = item->type;
	if (item->dot && ft_isnum(tp))
	{
		item->precision -= item->size;
		item->zero = 0;
	}
	check_item(item);
}
