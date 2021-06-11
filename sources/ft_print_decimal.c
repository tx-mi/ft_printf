#include "../includes/ft_printf.h"

static void	count_length(f_datum *datum, size_t number)
{
	size_t	len;

	len = ft_count_numsize(number);
	(*datum).length += len;
	if ((*datum).percision)
		(*datum).percision -= len;
	(*datum).length += (*datum).percision;
	if ((*datum).sign == -1)
		(*datum).length++;
	if ((*datum).length <= (*datum).width)
		(*datum).width -= (*datum).length;
	else
		(*datum).width = 0;
	(*datum).length += (*datum).width;
}

static void	put_minus(f_datum *datum)
{
	if ((*datum).sign == -1)
		write(1, "-", 1);
}

static void	print_number(f_datum *datum, size_t number)
{
	put_minus(datum);
	ft_put_precision(datum, number);
	ft_putnbr_recursive(number);
}

static void print_in_order(f_datum *datum, size_t number)
{
	int	c;

	c = ' ';
	if ((*datum).zero && !(*datum).dot)
	{
		c = '0';
		put_minus(datum);
		ft_put_precision(datum, number);
		ft_put_width(datum, c, number);
		ft_putnbr_recursive(number);
	}
	else if (!(*datum).minus)
	{
		ft_put_width(datum, c, number);
		print_number(datum, number);
	}
	else
	{
		print_number(datum, number);
		ft_put_width(datum, c, number);
	}
}

void	ft_print_decimal(f_datum *datum, size_t number)
{
	count_length(datum, number);
	print_in_order(datum, number);
}
