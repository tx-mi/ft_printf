#include "../../includes/ft_printf.h"

static void	display_char(f_datum *datum, char var)
{
	(*datum).length = 1;
	write(1, &var, 1);
}

static void	display_str(f_datum *datum, char *var)
{
	(*datum).length = ft_strlen(var);
	ft_putstr_fd(var, 1);
}

void	ft_process_strings(f_datum *datum, va_list *ap)
{
	if ((*datum).type == '%')
		display_char(datum, '%');
	else if ((*datum).type == 'c')
		display_char(datum, va_arg(*ap, int));
	else if ((*datum).type == 's')
		display_str(datum, va_arg(*ap, char *));
}
