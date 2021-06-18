#include "includes/ft_printf.h"

int	main(int argc, char **argv)
{
	int myout;
	int out;
	// 58 62 66 72 75 78

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
	myout = ft_printf("!%*c!\n", -2, '0');
	out = printf("!%*c!\n", -2, '0');
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n===============================================================================\n");
	myout = ft_printf(" --0*%0*.0u*0 0*%0*.10u*0-- \n", -2, 0, 21, 1);
	out = printf(" --0*%0*.0u*0 0*%0*.10u*0-- \n", -2, 0, 21, 1);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n===============================================================================\n");
	myout = ft_printf("!%09.1u!\n", UINT_MAX + 1);
	out = printf("!%09.1u!\n", UINT_MAX + 1);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n===============================================================================\n");
	myout = ft_printf("!%010.1u!\n", UINT_MAX + 1);
	out = printf("!%010.1u!\n", UINT_MAX + 1);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n===============================================================================\n");
	myout = ft_printf("!%011.1u!\n", UINT_MAX + 1);
	out = printf("!%011.1u!\n", UINT_MAX + 1);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n===============================================================================\n");
	myout = ft_printf("!%1.u!\n", 0);
	out = printf("!%1.u!\n", 0);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n===============================================================================\n");
	myout = ft_printf("!%1.1u!\n", 0);
	out = printf("!%1.1u!\n", 0);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n===============================================================================\n");
	myout = ft_printf("!%.u!\n", 0);
	out = printf("!%.u!\n", 0);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n===============================================================================\n");
	myout = ft_printf("!%9.0u!\n", UINT_MAX);
	out = printf("!%9.0u!\n", UINT_MAX);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n===============================================================================\n");
	myout = ft_printf("!%%!\n");
	out = printf("!%%!\n");
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
	printf("\n===============================================================================\n");
	myout = ft_printf("!%1.x!", 0);
	printf("\n===============================================================================\n");
	out = printf("!%1.x!", 0);
	if (out == myout)
		printf("\nOKAY\n");
	else
	{
		printf("\nKO\n");
		printf("myout = %d\nout = %d\n", myout, out);
	}
}
