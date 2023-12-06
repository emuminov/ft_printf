#comilation vars-----------------------------------
CC=cc
CFLAGS=-Wall -Wextra -Werror

#subject declarations------------------------------
NAME=libftprintf.a
HEAD=ft_printf.h
SRCS=ft_printf.c ft_printf_funcs.c ft_ltoa_base.c
OBJS=$(SRCS:%.c=%.o)

#libft declarations--------------------------------
LIB=libft.a
LIB_DIR=libft
LIB_PATH=$(LIB_DIR)/$(LIB)

#rules---------------------------------------------
$(NAME): $(LIB) $(HEAD) $(OBJS)
	cp $(LIB) $(NAME)
	ar crv $(NAME) $(OBJS)

%.o: %.c $(SRCS) $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@ -I .

$(LIB): $(LIB_PATH)
	cp $(LIB_PATH) .

$(LIB_PATH):
	$(MAKE) -C $(LIB_DIR)

all: $(NAME)

clean:
	rm $(OBJS) -f

fclean: clean
	$(MAKE) -C $(LIB_DIR) $@
	rm $(NAME) $(LIB) -f

re: fclean
	$(MAKE) all --no-print-directory

test: $(NAME)
	$(CC) tests/ft_printf.c $(NAME) -o test.out
	./test.out
	valgrind ./test.out --check-leaks=full -s
	
.PHONY: all clean fclean re test
