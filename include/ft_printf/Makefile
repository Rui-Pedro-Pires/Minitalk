SRC 		= 	ft_printf\
			ft_putstr_fd\
			ft_putnbr_fd\
			ft_putnbr_base_fd\
			ft_putchar_fd\
			ft_put_pointer\
			ft_count_num\

SRCS		= $(addsuffix .c, ${SRC})

HEAD		= ./includes/ 

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= cc
RM			= rm -f
AR			= ar rcs

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		$(NAME) 

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME) 

re:			fclean all

.PHONY:		all clean fclean re