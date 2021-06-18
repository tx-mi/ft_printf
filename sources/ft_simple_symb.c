#include "ft_printf.h"

void	ft_simple_symb(char **format_str, int *count_symb)
{
	ft_putchar_fd(**format_str, 1);
	(*count_symb)++;
	(*format_str)++;
}
