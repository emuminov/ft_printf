#comilation vars-----------------------------------
CC=gcc
CFLAGS=-Wall -Wextra -Werror

#subject declarations------------------------------
FILES=ft_ltoa_base.c ft_printf.c ft_printf_funcs.c
NAME=libftprintf.a
SRCS_DIR=srcs
OBJS_DIR=objs
HEAD_DIR=includes
HEAD=$(HEAD_DIR)/ft_printf.h
SRCS=$(FILES:%.c=$(SRCS_DIR)/%.c)
OBJS=$(FILES:%.c=$(OBJS_DIR)/%.o)

#libft declarations--------------------------------
LIB=libft.a
LIB_DIR=libft

#rules---------------------------------------------
$(NAME): $(LIB) $(OBJS) 
	cp $(LIB) $(NAME)
	ar rcsv $(NAME) $(OBJS)

$(OBJS): %.o: $(SRCS) $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD_DIR)

$(LIB): $(LIB_DIR)/$(LIB)
	cp $(LIB_DIR)/$(LIB) .

$(LIB_DIR)/$(LIB):
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
	
.PHONY: all clean fclean re test
