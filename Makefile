all:
	gcc -Wall -Wextra -Werror libft/libft.a main.c ft_printf.c sources/*.c sources/parser/*.c sources/process/*.c -o libftprintf
	clear;
	./libftprintf
