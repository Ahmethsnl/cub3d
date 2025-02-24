CC          = cc
CFLAGS		= -Wall -Wextra -Werror -g 
SRC_DIR     = src
NAME        = cub3D
SRCS        = src/parser/ft_free_arrys.c src/exec/draw.c src/exec/draw_helper.c src/parser/init.c src/parser/init_helper.c src/parser/init_helper2.c src/parser/ft_split_new_lines.c src/main.c src/exec/mlx_funcs.c src/exec/move.c \
			src/exec/move_helper.c src/exec/texture.c src/parser/utils.c src/parser/check_map.c src/parser/check_map_helper.c src/parser/flood_fill.c src/parser/free.c src/parser/init_helper3.c src/parser/map_helper.c src/parser/map_helper2.c
OBJS        = $(SRCS:.c=.o) 
RM          = rm -rf
MLX_DIR     = lib/libmlx
MLX         = $(MLX_DIR)/libmlx.a

LIBFT_DIR   = lib/libft
LIBFT       = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -L/usr/X11R6/lib 

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX) inc/cub3d.h
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) $(LIBFT_FLAGS) #-fsanitize=address

$(MLX):
	@curl -O https://cdn.intra.42.fr/document/document/28880/minilibx-linux.tgz
	@tar -xvf minilibx-linux.tgz
	@mkdir -p $(MLX_DIR)
	@mv minilibx-linux/* $(MLX_DIR)
	@$(RM) minilibx-linux
	@$(RM) minilibx-linux.tgz
	make -s -C $(MLX_DIR)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(LIBFT) & wait
	@make -C $(LIBFT_DIR) fclean

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
