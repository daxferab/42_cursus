NAME = so_long.out
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
INCLUDES = -Iinclude -Ilib/libft -Ilib/mlx/include -Ilib/mlx/include/MLX42

SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
LIBFT_DIR = $(LIB_DIR)/libft
LIBMLX_DIR = $(LIB_DIR)/mlx

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(LIBMLX_DIR)/build/libmlx42.a
MLXFLAGS = -L $(LIBMLX_DIR)/build -l mlx42 -l glfw -l dl -l m -pthread

SRC_FILES = hook.c\
			errors.c\
			free.c\
			main.c\
			initialize/draw_map.c\
			initialize/draw_tools.c\
			initialize/init_map.c\
			parse/arg_validation.c\
			parse/map_utils.c\
			parse/map_utils2.c\
			parse/map_is_player_exit.c\
			parse/map_validation.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_FILES = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_DIRS = $(OBJ_DIR) $(OBJ_DIR)/initialize $(OBJ_DIR)/parse

all: $(NAME)

$(NAME): $(OBJ_DIRS) $(LIBFT) $(MLX) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(MLXFLAGS) $(LIBFT) $(MLX) -o $(NAME)

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build
	make -C $(LIBMLX_DIR)/build -j4

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	rm -rf $(LIBMLX_DIR)/build

re: fclean all

run: all
	./$(NAME) maps/maptry.ber

.PHONY: all clean fclean re
