#include "../../includes/ft_printf.h"

static void check_item(t_item *item)
{
	if (item->width < 0)
		item->width = 0;
	if (item->precision < 0)
		item->precision = 0;
}

void	ft_recount_width(t_item *item)
{
	int	tp;

	tp = item->type;
	if (item->width)
	{
		if (tp == 'c' || tp == '%')
		{
			item->length++;
			if (item->width)
				item->width--;
		}
		else if (tp == 's')
		{
			if (item->dot && (size_t)item->precision < ft_strlen(item->string))
				item->width -= item->precision;
			else
				item->width -= ft_strlen(item->string);
		}
		else if (ft_isnum(tp))
		{
			item->width -= (item->precision + item->numsize);
			if (item->sign == -1)
				item->width--;
		}
		else if (tp == 'p')
		{
			item->width -= (item->precision + item->numsize + 2);
			item->length += 2; // 0x
		}
		check_item(item);
	}
}

void	ft_recount_precision(t_item *item)
{
	int	tp;

	tp = item->type;
	if (tp == 's')
	{
		if (!item->string)
			item->string = "(null)";
	}
	else if (item->dot && ft_isnum(tp))
	{
		item->precision -= item->numsize;
		item->zero = 0;
	}
	check_item(item);
}
