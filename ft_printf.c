#include "includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			count_symb;
	char		*format_str;
	va_list		ap;

	va_start(ap, format);
	count_symb = 0;
	format_str = (char *)format;
	while (*format_str)
	{
		if (*format_str == '%')
			ft_precentage_symb(&format_str, &ap, &count_symb);
		else
			ft_simple_symb(&format_str, &count_symb);
	}
	va_end(ap);
	return (count_symb);
}
