SRCS = ft_bzero.c	\
	   ft_isprint.c	\
	   ft_strlcpy.c	\
	   ft_isalnum.c	\
	   ft_memcpy.c	\
	   ft_strlen.c	\
	   ft_isalpha.c	\
	   ft_memmove.c	\
	   ft_isascii.c	\
	   ft_memset.c	\
	   ft_isdigit.c	\
	   ft_strlcat.c

NAME = libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -c
	ar -r $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	gcc -o ../libft_test/test ../libft_test/test.c $(NAME)
	../libft_test/test
