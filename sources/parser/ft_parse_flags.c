#include "../../includes/ft_printf.h"

void	ft_parse_flags(f_datum *datum, char **str)
{
	while (**str == '-' || **str == '0')
	{
		if (**str == '-' && (*datum).minus != 1)
		{
			(*datum).minus = 1;
			(*datum).zero = 0;
		}
		else if (**str == '0' && (*datum).minus != 1)
		{
			(*datum).minus = 0;
			(*datum).zero = 1;
		}
		(*str)++;
	}
}
