#include "../includes/ft_printf.h"

void	ft_precentage_symb(char **format_str, va_list *ap, int *count_symb)
{
	f_datum		curr_elem;

	(*format_str)++;
	curr_elem = ft_parse(format_str, ap);
	ft_process(&curr_elem, ap);
	*count_symb += curr_elem.length;

	// printf("zero = %d,\nminus = %d,\nwidth = %d,\ndot = %d,\npercision = %d,\ntype = %c\n", curr_elem.zero, curr_elem.minus, curr_elem.width, curr_elem.dot, curr_elem.percision, curr_elem.type);
}
