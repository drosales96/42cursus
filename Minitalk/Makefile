CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c

LIBFT_PATH = libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a
FT_PRINTF_PATH = ft_printf
FT_PRINTF_ARCHIVE = $(FT_PRINTF_PATH)/libftprintf.a

CLIENT_NAME = client
SERVER_NAME = server
CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus

all: $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) -L$(LIBFT_PATH) -lft -L$(FT_PRINTF_PATH) -lftprintf

$(SERVER_NAME): $(SERVER_SRCS)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) -L$(LIBFT_PATH) -lft -L$(FT_PRINTF_PATH) -lftprintf

$(SERVER_BONUS_NAME): $(SERVER_BONUS_SRCS)
	$(CC) $(CFLAGS) -o $@ $(SERVER_BONUS_SRCS) -L$(LIBFT_PATH) -lft -L$(FT_PRINTF_PATH) -lftprintf

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_SRCS)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_BONUS_SRCS) -L$(LIBFT_PATH) -lft -L$(FT_PRINTF_PATH) -lftprintf

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF_ARCHIVE):
	$(MAKE) -C $(FT_PRINTF_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

re: fclean all

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

.PHONY: all clean fclean re bonus
