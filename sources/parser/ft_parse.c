#include "ft_printf.h"

static t_item	create_struct(void)
{
	t_item	item;

	item.zero = 0;
	item.minus = 0;
	item.def_w = 0;
	item.width = 0;
	item.dot = 0;
	item.precision = 0;
	item.type = 0;
	item.sign = 0;
	item.length = 0;
	item.chr = 0;
	item.num = 0;
	item.un_num = 0;
	item.pointer = 0;
	item.string = NULL;
	item.size = 0;
	item.stupid = 0;
	return (item);
}

t_item	ft_parse(char **format_str, va_list *ap)
{
	t_item	item;

	item = create_struct();
	ft_parse_flags(&item, format_str);
	ft_parse_width(&item, format_str, ap);
	ft_parse_precision(&item, format_str, ap);
	ft_parse_type(&item, format_str, ap);
	return (item);
}
