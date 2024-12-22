/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:40:04 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/11/10 15:40:04 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "colors.h"
# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define LEFT_CLICK 	1
# define RIGHT_CLICK 	2
# define MIDDLE_CLICK	3
# define SCROLL_UP		4
# define SCROLL_DOWN	5

# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_I			34
# define KEY_O			31
# define KEY_P			35
# define KEY_J			38
# define KEY_K			40
# define KEY_L			37
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_FORWARD 	126
# define KEY_BACKWARD	125

# define KEY_TAB	48
# define KEY_MAJ	257
# define KEY_ESC	53
# define KEY_TAB	48

# define ERR_USAGE "usage: ./cub3d <path/to/map.cub>"

# define ERR_FILE_NOT_CUB "Not a .cub file"
# define ERR_FILE_NOT_XPM "Not an .xpm file"
# define ERR_FILE_IS_DIR "Is a directory"
# define ERR_FLOOR_CEILING "Invalid floor/ceiling RGB color(s)"
# define ERR_COLOR_FLOOR "Invalid floor RGB color"
# define ERR_COLOR_CEILING "Invalid ceiling RGB color"
# define ERR_INVALID_MAP "Map description is either wrong or incomplete"
# define ERR_INV_LETTER "Invalid character in map"
# define ERR_NUM_PLAYER "Map has more than one player"
# define ERR_TEX_RGB_VAL "Invalid RGB value (min: 0, max: 255)"
# define ERR_TEX_MISSING "Missing texture(s)"
# define ERR_TEX_INVALID "Invalid texture(s)"
# define ERR_COLOR_MISSING "Missing color(s)"
# define ERR_MAP_MISSING "Missing map"
# define ERR_MAP_TOO_SMALL "Map is not at least 3 lines high"
# define ERR_MAP_NO_WALLS "Map is not surrounded by walls"
# define ERR_MAP_LAST "Map is not the last element in file"
# define ERR_PLAYER_POS "Invalid player position"
# define ERR_PLAYER_DIR "Map has no player position (expected N, S, E or W)"
# define ERR_MALLOC "Could not allocate memory"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"

typedef	struct	s_game
{
    void        *mlx;
    void        *win;
    void        *img;
}               t_game;

typedef struct s_vector2
{
    size_t      x;
    size_t      y;
}               t_vector2;

typedef struct s_player
{
    t_vector2   pos;
    t_vector2   dir;
    t_vector2   plane;
    int         move_speed;
    int         rot_speed;
}               t_player;

typedef struct s_map
{
    char        **map;
    size_t      width;
    size_t      height;
}               t_map;

typedef struct s_texture
{
    char        *path;
    int         *data;
    int         width;
    int         height;
}               t_texture;

typedef struct s_color
{
    int         r;
    int         g;
    int         b;
}               t_color;

typedef struct s_cub
{
    t_map       map;
    t_player    player;
    t_texture   tex[5];
    t_color     floor;
    t_color     ceiling;
}               t_cub;

typedef struct s_ray
{
    t_vector2   pos;
    t_vector2   dir;
    t_vector2   plane;
    t_vector2   map;
    t_vector2   side_dist;
    t_vector2   delta_dist;
    t_vector2   step;
    size_t      perp_wall_dist;
    size_t      wall_x;
    size_t      step;
    size_t      tex_pos;
    int         side;
    int         hit;
    int         line_height;
    int         draw_start;
    int         draw_end;
    int         tex_num;
    int         tex_x;
    int         tex_y;
    int         color;
    int         *texture;
}               t_ray;

int exit_error(t_game *game, char const *str);

#endif