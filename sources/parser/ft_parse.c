#include "../../includes/ft_printf.h"

f_datum ft_parse(char **str, va_list *ap)
{
	f_datum result;

	result = ft_structnew();
	ft_parse_flags(&result, str);
	ft_parse_width(&result, str, ap);
	ft_parse_percision(&result, str, ap);
	ft_parse_type(&result, str);
	return (result);
}
