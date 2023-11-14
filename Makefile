SRC_SERVER = ./src/server.c\
	
SRC_CLIENT = ./src/client.c\

SRC_BONUS_SERVER = ./src_bonus/server_bonus.c\

SRC_BONUS_CLIENT = ./src_bonus/client_bonus.c\

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER_BONUS = $(SRC_BONUS_SERVER:.c=.o)

OBJ_CLIENT_BONUS = $(SRC_BONUS_CLIENT:.c=.o)

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

FT_PRINTF = ./include/ft_printf/libftprintf.a

LIBFT = ./include/libft/libft.a

NAME = $(NAME1) $(NAME2)

NAME1 = server

NAME2 = client

all: $(NAME)

$(NAME): $(FT_PRINTF) $(LIBFT) $(OBJ_CLIENT) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME2) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME1) $(FT_PRINTF) $(LIBFT)

$(FT_PRINTF):
	@make -C ./include/ft_printf -s

$(LIBFT):
	@make -C ./include/libft -s

bonus: $(FT_PRINTF) $(LIBFT) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -o client_bonus $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -o server_bonus $(FT_PRINTF) $(LIBFT)

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	@make -C ./include/ft_printf/ clean -s
	@make -C ./include/libft/ clean -s

clean_bonus:
	$(RM) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	@make -C ./include/ft_printf/ clean -s
	@make -C ./include/libft/ clean -s

fclean: clean
	$(RM) $(NAME1) $(NAME2)
	@make -C ./include/ft_printf/ fclean -s
	@make -C ./include/libft/ fclean -s

fclean_bonus: clean_bonus
	$(RM) client_bonus server_bonus
	@make -C ./include/ft_printf/ fclean -s
	@make -C ./include/libft/ fclean -s
	
re: fclean all