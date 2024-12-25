/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:20:14 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/12/25 14:20:14 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_ENGINE_H
#define NEW_ENGINE_H

#include <stdio.h>
#include <math.h>

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

typedef struct s_images
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		*addr;
	void	*img;
}				t_images;

typedef struct s_vector2 
{
    double       x;
    double       y;
}              t_vector2;

typedef struct s_transform
{
    t_vector2    position;
    t_vector2    direction;
    t_vector2    rotation;
}              t_transform;

typedef struct s_raycast
{
    double       camera_x;
    t_vector2    step;
    t_vector2    plane;
    t_vector2    origin;
    t_vector2    direction;
    t_vector2    side_distance;
    t_vector2    delta_distance;
    double       perpWallDist;
}              t_raycast;

typedef struct s_physics
{
    t_raycast   *raycast;
    t_transform *transform;
}              t_physics;

typedef struct s_engine
{
    void        *mlx_ptr;
    void        *win_ptr;
    void        *img_ptr;
    char        *map_path;
    int         map_fd;
    t_map       *map;
    t_images    *images;
    t_physics   *physics;
}              t_engine;

typedef struct s_map
{
    int          width;
    int          height;
    char          **map;
}              t_map;

int init_raycast(t_raycast  *raycast);
t_vector2 raycast(t_engine *engine);
int ray_main(t_engine *engine);
void another(t_engine *engine);

#endif