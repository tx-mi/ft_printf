#include "../includes/ft_printf.h"

int	ft_isnum(int type)
{
	if (type == 'd' || type == 'i' || type == 'u'
		|| type == 'x' || type == 'X')
		return (1);
	return (0);
}
