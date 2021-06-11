#include "../../includes/ft_printf.h"

void	ft_parse_width(f_datum *datum, char **str, va_list *ap)
{
	int	width;

	width = 0;
	if (**str == '*')
	{
		(*datum).width = va_arg(*ap, int);
		(*str)++;
	}
	else if (ft_isdigit(**str))
	{
		width = ft_atoi(*str);
		if (width > 0)
			(*datum).width = width;
	}
	while (width)
	{
		(*str)++;
		width /= 10;
	}
}
