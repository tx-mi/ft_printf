#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_item
{
	int					zero;
	int					minus;
	int					width;
	int					dot;
	int					precision;
	int					type;
	int					sign;
	int					length;

	int					chr;
	long long int		num;
	unsigned int		un_num;
	unsigned long int	pointer;
	char				*string;

	size_t				size;
}						t_item;

int		ft_printf(const char *format, ...);
void	ft_simple_symb(char **format_str, int *count_symb);
void	ft_precentage_symb(char **format_str, va_list *ap, int *count_symb);

// Parsing
t_item	ft_parse(char **format_str, va_list *ap);
void	ft_parse_flags(t_item *item, char **format_str);
void	ft_parse_width(t_item *item, char **format_str, va_list *ap);
void	ft_parse_precision(t_item *item, char **format_str,	va_list *ap);
void	ft_parse_type(t_item *item, char **format_str, va_list *ap);

// Process and print
int		ft_process(t_item *item);
void	ft_recount_precision(t_item *item);
void	ft_recount_width(t_item *item);
void	ft_print(t_item *item);

void	ft_print_chr(t_item *item);
void	ft_print_str(t_item *item);
void	ft_print_decnum(t_item *item);
void	ft_print_hexnum(t_item *item);

// Utils
int		ft_isnum(int type);
void	ft_print_width(t_item *item);
#endif
