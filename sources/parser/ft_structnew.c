#include "../../includes/ft_printf.h"

f_datum	ft_structnew()
{
	f_datum result;

	result.zero = 0;
	result.minus = 0;
	result.width = 0;
	result.dot = 0;
	result.percision = 0;
	result.type = '\0';
	result.sign = 1;
	result.length = 0;

	return (result);
}
