NAME := libftprintf.a

CC := gcc

CFLAGS := -Wall -Wextra -Werror

RM := rm -f

SRCS := ft_atoi.c\
ft_char_write.c\
ft_flag_init.c\
ft_hex_write.c\
ft_int_write.c\
ft_judgment.c\
ft_percent_write.c\
ft_printf.c\
ft_ptr_write.c\
ft_put_chstr.c\
ft_putnbr_fd.c\
ft_putspace.c\
ft_str_write.c\
ft_strlen.c\
ft_substr.c\
ft_uns_write.c\
nbr_base.c\
put_sharp.c\
put_sign.c\
put_zeros.c

OBJS :=$(SRCS:.c=.o)

$(NAME):$(OBJS)
	ar rcs $@ $^

all: $(NAME)

bonus:		all

clean:
	${RM} ${OBJS}

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

test:
	cc test2.c -L. libftprintf.a
	./a.out

.PHONY:		all bonus clean fclean re 