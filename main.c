#include "includes/ft_printf.h"

int	main(int argc, char **argv)
{
	int myout;
	int out;

	(void)argv;
	(void)argc;
	// 1
	printf("\n===============================================================================\n");
	myout = ft_printf("!%0*d!\n", 5, -123);
	out = printf("!%0*d!\n", 5, -123);
	printf("\n===============================================================================\n");
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	// 2
	printf("\n===============================================================================\n");
	myout = ft_printf("!%0*.d!\n", 5, -123);
	out = printf("!%0*.d!\n", 5, -123);
	printf("\n===============================================================================\n");
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	// 3
	printf("\n===============================================================================\n");
	myout = ft_printf("!%-*d!\n", 5, -123);
	out = printf("!%-*d!\n", 5, -123);
	printf("\n===============================================================================\n");
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
}
