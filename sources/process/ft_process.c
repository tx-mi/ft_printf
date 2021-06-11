#include "../../includes/ft_printf.h"

void	ft_process(f_datum *datum, va_list *ap)
{
	if ((*datum).type == '%' || (*datum).type == 'c' || (*datum).type == 's')
		ft_process_strings(datum, ap);
	else if ((*datum).type == 'u'
		|| (*datum).type == 'd' || (*datum).type == 'i'
		|| (*datum).type == 'x' || (*datum).type == 'X' || (*datum).type == 'p')
		ft_process_numbers(datum, ap);
}
