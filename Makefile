NAME = libftprintf.a

# Header files
PATH_INCLUDE = ./includes/
HEADERS = $(PATH_INCLUDE)ft_printf.h $(PATH_INCLUDE)libft.h
HDR_INC = -I./includes/

# Libft
PATH_LIB = ./libft/
LIBA = libft.a
LIBFT = $(addprefix $(PATH_LIB), $(LIBA))
LIB_OBJ = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o \
		ft_memmove.o ft_memchr.o ft_memcmp.o \
		ft_strlen.o ft_strlcpy.o  ft_strlcat.o ft_strchr.o \
		ft_strrchr.o ft_strnstr.o ft_strncmp.o \
		ft_atoi.o \
		ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o \
		ft_isprint.o \
		ft_toupper.o ft_tolower.o \
		ft_calloc.o ft_strdup.o \
		ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o \
		ft_itoa.o ft_strmapi.o \
		ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
		ft_pow_recursive_bonus.o ft_count_numsize_bonus.o ft_putnbr_recursive_bonus.o

LIB_OBJS = $(addprefix $(PATH_LIB), $(LIB_OBJ))

# Paths
PATH_SRC = ./sources/
PATH_PARSER = ./sources/parser/
PATH_PROCESS = ./sources/process/

# C files
SRC = 	ft_precentage_symb.c ft_simple_symb.c ft_utils.c

SRC_PARSER = 	ft_parse.c ft_parse_flags.c ft_parse_width.c \
				ft_parse_precision.c ft_parse_type.c

SRC_PROCESS = 	ft_process.c ft_recount.c ft_print_chars.c ft_print_num.c

SOURCES =	 $(addprefix $(PATH_SRC), $(SRC)) $(addprefix $(PATH_PARSER), $(SRC_PARSER)) \
			 $(addprefix $(PATH_PROCESS), $(SRC_PROCESS)) ft_printf.c 

# OBJS files
OBJS = $(patsubst %.c, %.o, $(SOURCES)) $(LIB_OBJS)

# Utils
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -c
LIBC = ar rcs
RM = rm -rf

%.o : %.c $(HEADERS)
	$(CC) $(C_FLAGS) $(HDR_INC) $< -o $@

all: run_libft $(HEADERS) $(OBJS) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(HEADERS)
	$(LIBC) $(NAME) $? 

run_libft:
	@make -C $(PATH_LIB)

clean:
	$(RM) $(OBJS)
	@make -C $(PATH_LIB) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(PATH_LIB) fclean

re: fclean all

main:
	make re && make clean && gcc libftprintf.a  main.c && ./a.out

.PHONY: all clean fclean
