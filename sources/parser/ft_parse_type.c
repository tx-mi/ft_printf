#include "../../includes/ft_printf.h"

void	ft_parse_type(f_datum *datum, char **str)
{
	if (**str == 'u')
		(*datum).type = 'u';
	else if (**str == 'd')
		(*datum).type = 'd';
	else if (**str == 'i')
		(*datum).type = 'i';
	else if (**str == 'x')
		(*datum).type = 'x';
	else if (**str == 'X')
		(*datum).type = 'X';
	else if (**str == 'c')
		(*datum).type = 'c';
	else if (**str == 's')
		(*datum).type = 's';
	else if (**str == '%')
		(*datum).type = '%';
	(*str)++;
}
