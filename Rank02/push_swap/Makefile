NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -Iinclude -Ilibft

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES = exceptions.c\
			ksort.c\
			lst_utils.c\
			main.c\
			parse.c\
			sort.c\
			utils.c\
			sort_to_five.c\
			$(addprefix sortopt/, \
				push.c\
				reverse_rotate.c\
				rotate.c\
				swap.c\
			)

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_FILES = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_DIRS = $(OBJ_DIR) $(OBJ_DIR)/sortopt

all: $(NAME)

$(NAME): $(OBJ_DIRS) $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	make -C $(LIBFT_DIR) bonus

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
