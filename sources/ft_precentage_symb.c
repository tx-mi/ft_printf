#include "ft_printf.h"

void	ft_precentage_symb(char **format_str, va_list *ap, int *count_symb)
{
	t_item	item;

	(*format_str)++;
	item = ft_parse(format_str, ap);
	*count_symb += ft_process(&item);
}
