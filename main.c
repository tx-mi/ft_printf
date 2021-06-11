#include "includes/ft_printf.h"

int	main(int argc, char **argv)
{
	int myout;
	int out;

	(void)argv;
	(void)argc;
	myout = ft_printf("%% |%-11i| %s%c%%\n", -123, "How are you", '?');
	printf("===================================================\n");
	out = printf("%% |%-11i| %s%c%%\n", -123, "How are you", '?');
	if (out == myout)
		printf("\nOKAY\n");
	else
		printf("\nKO\n");
	// printf("myout = %d\nout = %d", myout, out);
}
