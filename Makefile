NAME=libftprintf.a

SRCS=*.c

OBJS=*.o

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c $(SRCS)
		ar -rc $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all
