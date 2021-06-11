#include "../../includes/ft_printf.h"

void	ft_parse_percision(f_datum *datum, char **str, va_list *ap)
{
	int	percision;

	percision = 0;
	if (**str == '.')
	{
		(*str)++;
		(*datum).dot = 1;
		if (**str == '*')
		{
			(*datum).percision = va_arg(*ap, int);
			(*str)++;
		}
		else if (ft_isdigit(**str))
		{
			percision = ft_atoi(*str);
			(*datum).percision = percision;
		}
		while (percision)
		{
			(*str)++;
			percision /= 10;
		}
	}
}
