#include "../../includes/ft_printf.h"

static void	display_decimal(f_datum *datum, va_list *ap)
{
	size_t	result;
	int		num;

	num = 0;
	result = 0;
	if ((*datum).type != 'u')
	{
		num = va_arg(*ap, int);
		if (num < 0)
			(*datum).sign = -1;
	}
	else
		num = va_arg(*ap, size_t);
	if (num != INT_MIN)
		result = num * (*datum).sign;
	else
		result = 2147483648;
	ft_print_decimal(datum, result);
}

static void	display_hex(f_datum *datum, va_list *ap)
{
	// Convert number from decimal to hex than put it
	(void)datum;
	(void)ap;
	ft_putstr_fd("hexNumber", 1);
	// ft_printhex(result, case=x/X)
}

void	ft_process_numbers(f_datum *datum, va_list *ap)
{
	if ((*datum).type == 'd' || (*datum).type == 'i' || (*datum).type == 'u')
		display_decimal(datum, ap);
	else
		display_hex(datum, ap);
}
