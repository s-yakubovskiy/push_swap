NAME = push_swap
SRC =	main.c
SRCDIR = src/
H = push_swap.h
HDIR = hdir/
OBJ = $(SRC:.c=.o)
SRCF = ${addprefix $(SRCDIR), $(SRC)}
LIB = ft
LIBD = lib/

all: prog

prog: $(NAME) clean

$(NAME):
#	# @make $(LIBD)lib$(LIB)
#	# @make $(LIBD)printf/
#	# @cp $(LIBD)libft/libft.h ./libft.h
#	# @cp $(LIBD)libft/libft.a ./libft.a
#	# @cp $(LIBD)printf/ft_printf.h ./printf.h
#	# @cp $(LIBD)printf/libftprintf.a ./printf.a
	gcc *.c printf.a
#	# @gcc -Wall -Werror -Wextra -c $(SRCF)
#	# @gcc libft.a $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all