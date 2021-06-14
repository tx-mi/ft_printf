#include "includes/ft_printf.h"

int	main(int argc, char **argv)
{
	int myout;
	int out;

	(void)argv;
	(void)argc;
	printf("\n===============================================================================\n");
	// 1
	printf("d i\n");
	myout = ft_printf("!%0*d!\n", 5, -123);
	out = printf("!%0*d!\n", 5, -123);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n-------------------------------------------------------------------------------\n");
	// 1
	myout = ft_printf("!%0*.d!\n", 5, -123);
	out = printf("!%0*.d!\n", 5, -123);
	// 2
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n-------------------------------------------------------------------------------\n");
	// 3
	myout = ft_printf("!%-*d!\n", 5, -123);
	out = printf("!%-*d!\n", 5, -123);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n-------------------------------------------------------------------------------\n");
	printf("\n===============================================================================\n");
	printf("u\n");
	// 1
	myout = ft_printf("!%0*u!\n", 5, 123);
	out = printf("!%0*u!\n", 5, 123);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n-------------------------------------------------------------------------------\n");
	// 2
	myout = ft_printf("!%*.u!\n", 0, 123);
	out = printf("!%*.u!\n", 0, 123);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n-------------------------------------------------------------------------------\n");
	printf("\n===============================================================================\n");
	printf("s\n");
	// 1
	myout = ft_printf("!%10s!\n", "HELLO");
	out = printf("!%10s!\n", "HELLO");
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n-------------------------------------------------------------------------------\n");
	// 2
	myout = ft_printf("!%10.4s!\n", "HELLO");
	out = printf("!%10.4s!\n", "HELLO");
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n===============================================================================\n");
}
