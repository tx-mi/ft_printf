#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct flags_datum
{
	int			zero;
	int			minus;
	size_t		width;
	int			dot;
	size_t		percision;
	int			type;
	int			sign;
	size_t		length;
}				f_datum;

int				ft_printf(const char *format, ...);
void			ft_precentage_symb(char **format_str, va_list *ap, int *count_symb);
void			ft_simple_symb(char **format_str, int *count_symb);

f_datum			ft_structnew(void);
f_datum			ft_parse(char **str, va_list *ap);
void			ft_parse_flags(f_datum *datum, char **str);
void			ft_parse_width(f_datum *datum, char **str, va_list *ap);
void			ft_parse_percision(f_datum *datum, char **str, va_list *ap);
void			ft_parse_type(f_datum *datum, char **str);

void			ft_process(f_datum *element, va_list *ap);
void			ft_process_strings(f_datum *datum, va_list *ap);
void			ft_process_numbers(f_datum *datum, va_list *ap);

void			ft_print_decimal(f_datum *datum, size_t number);

void			ft_put_width(f_datum *datum, char c, size_t num);
void			ft_put_precision(f_datum *datum, size_t num);
#endif
