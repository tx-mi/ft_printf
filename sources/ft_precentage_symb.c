#include "../includes/ft_printf.h"

void	ft_precentage_symb(char **format_str, va_list *ap, int *count_symb)
{
	t_item	item;

	(*format_str)++;
	item = ft_parse(format_str, ap);
	*count_symb += ft_process(&item);
	// printf("------------------------------------------------------------------------------\n");
	// printf("zero = %d,\nminus = %d,\nwidth = %d,\ndot = %d,\nprecision = %d,\ntype = %c\n", item.zero, item.minus, item.width, item.dot, item.precision, item.type);
	// printf("-------------------------------------------------------------------------------\n");
}
