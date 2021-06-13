NAME = libftprintf.a

# Header files
PATH_INCLUDE = ./includes/
HDRS = libft.h ft_printf.h
HEADERS = $(addprefix $(PATH_INCLUDE), $(HDRS))
HDR_INC = -I./includes/*.h

# Libft
PATH_LIB = ./libft/
LIBA = libft.a
LIBFT = $(addprefix $(PATH_LIB), $(LIBA))

# Paths
PATH_SRC = ./sources/
PATH_PARSER = ./sources/parser/
PATH_PROCESS = ./sources/process/

# C files
SRC = 	ft_precentage_symb.c ft_simple_symb.c ft_utils.c

SRC_PARSER = 	ft_parse.c ft_parse_flags.c ft_parse_width.c \
				ft_parse_precision.c ft_parse_type.c

SRC_PROCESS = 	ft_process.c ft_recount.c ft_print_chars.c \
				ft_print_decnum.c ft_print_hexnum.c

SOURCES =	 $(addprefix $(PATH_SRC), $(SRC)) $(addprefix $(PATH_PARSER), $(SRC_PARSER)) \
			 $(addprefix $(PATH_PROCESS), $(SRC_PROCESS)) ft_printf.c 

# OBJS files
OBJS = $(patsubst %.c, %.o, $(SOURCES))

# Utils
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -c
LIBC = ar rcs
RM = rm -rf

%.o : %.c 
	$(CC) $(C_FLAGS) $(HDR_INC) $< -o $@

all: run_libft $(HEADERS) $(OBJS) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(HEADERS)
	$(LIBC) $(NAME) $(OBJS) $(PATH_LIB)*.o

run_libft:
	@make -C $(PATH_LIB)

clean:
	$(RM) $(OBJS)
	@make -C $(PATH_LIB) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(PATH_LIB) fclean

re: fclean all

run_main:
	make re && make clean && gcc libftprintf.a  main.c && ./a.out
