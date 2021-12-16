SRCS = ft_atoi.c\
	   ft_bzero.c\
	   ft_calloc.c\
	   ft_isalnum.c\
	   ft_isalpha.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_itoa.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_memset.c\
	   ft_putchar_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_putstr_fd.c\
	   ft_simple_math.c\
	   ft_split.c\
	   ft_strchr.c\
	   ft_strdup.c\
	   ft_striteri.c\
	   ft_strjoin.c\
	   ft_strlcat.c\
	   ft_strlcpy.c\
	   ft_strlen.c\
	   ft_strmapi.c\
	   ft_strmod.c\
	   ft_strncmp.c\
	   ft_strnstr.c\
	   ft_strrchr.c\
	   ft_strtrim.c\
	   ft_substr.c\
	   ft_tolower.c\
	   ft_toupper.c

SRCS_B = ft_lstadd_back.c\
		 ft_lstadd_front.c\
		 ft_lstclear.c\
		 ft_lstdelone.c\
		 ft_lstiter.c\
		 ft_lstlast.c\
		 ft_lstmap.c\
		 ft_lstnew.c\
		 ft_lstsize.c\
		 $(SRCS)

NAME = libft.a
OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
OBJS_B = $(SRCS_B:.c=.o)
OBJS_B_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS_B))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS_PREFIXED)
	@ar -cr $(NAME) $(OBJS_PREFIXED)
	@echo "Done creating archive $(CURDIR)/$(NAME)"

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Done cleaning $(CURDIR)/$(OBJSDIR)"

fclean: clean
	@rm -f $(NAME)
	@echo "Done cleaning archive $(CURDIR)/$(NAME)"

re: fclean all

bonus: $(OBJS_B_PREFIXED)
	@ar -cr $(NAME) $(OBJS_B_PREFIXED)
	@echo "Done adding bonus objects to archive"
