#comilation vars-----------------------------------
CC=gcc
CFLAGS=-Wall -Wextra -Werror

#subject declarations------------------------------
FILES=ft_ltoa_base.c ft_printf.c ft_printf_funcs.c
NAME=libftprintf.a
SRCS_DIR=srcs
HEAD=$(SRCS_DIR)/ft_printf.h
SRCS=$(FILES:%.c=$(SRCS_DIR)/%.c)
OBJS=$(SRCS:%.c=%.o)

#libft declarations--------------------------------
LIB_FILES=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
LIB=libft.a
LIB_DIR=libft
LIB_HEAD=$(LIB_DIR)/libft.h
LIB_SRCS=$(LIB_FILES:%.c=$(LIB_DIR)/%.c)
LIB_OBJS=$(LIB_SRCS:%.c=%.o)

#rules---------------------------------------------
$(NAME): $(OBJS) $(LIB)
	
$(OBJS): %.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(SRCS_DIR)

$(LIB): $(LIB_OBJS)
	ar cr $(LIB) $(LIB_OBJS)

$(LIB_OBJS): %.o: %.c $(LIB_HEAD)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIB_DIR)

all: $(NAME)

clean:
	rm $(OBJS) $(LIB_OBJS) -f

fclean: clean
	rm $(NAME) $(LIB) -f

re: fclean
	$(MAKE) all --no-print-directory

test:
	
.PHONY: all clean fclean re test
