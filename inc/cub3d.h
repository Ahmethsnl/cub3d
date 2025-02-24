/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:02:28 by migenc            #+#    #+#             */
/*   Updated: 2025/02/17 17:19:38 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WALL '1'
# define EAST 'E'
# define WEST 'W'
# define NORTH 'N'
# define SOUTH 'S'
# define FLOOR '0'
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define SWIDTH 1280
# define SHEIGHT 512
# define ESC_KEY 65307
# define TTEXTURES 5
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363  

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../lib/libmlx/mlx.h"
# include "../lib/libft/libft.h"

typedef int	t_bool;

typedef struct s_map
{
	int		grid_x;
	int		grid_y;
	char	**floor;
	char	**ceiling;
	int		fcolor;
	int		cecolor;
	char	**map;
	char	**flood_fill;
	char	**wtexture;
	char	*fstr;
	char	*cstr;
	char	*mstr;
}				t_map;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		plane_x;
	double		plane_y;
	double		camera;
	double		raydirx;
	double		raydiry;
	double		deltadistx;
	double		deltadisty;
	int			grid_x;
	int			grid_y;
	int			stepx;
	int			stepy;
	double		sidedistx;
	double		sidedisty;
	int			wall;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			textr_x;
	double		textr_step;
	double		textr_pos;
}	t_ray;

typedef struct s_images
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_images;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	int			*mlx_o_data;
	char		*map_path;
	int			map_fd;
	t_bool		w_pressed;
	t_bool		a_pressed;
	t_bool		s_pressed;
	t_bool		d_pressed;
	t_bool		left;
	t_bool		right;
	t_map		*map;
	t_ray		*ray;
	t_images	**images;
}				t_data;

int		map_setter_util2(char **map, char *str, int *i, int j);
void	ft_xpm_files_check(t_data *data, char **line);
void	ft_free_arrys(char **tmp, char **map);
char	*rgb_setter(char *str, int i, int k);
char	*dir_setter(char *str, int i, int k);
int		dir_setter_helper(char *str, int i);
int		rgb_setter_helper(char *str, int i);
int		compare_strings(const char *str1, const char *str2);
void	map_trim(char **map);
int		line_len(char *str);
int		map_setter_helper(char *str, int i);
void	ft_rgb_cleaner_helper(t_data *data, char *tmp, char *tmp2);
char	**ft_rgb_cleaner(char *rgb_str, int i, t_data *data);
void	ft_free_tmps(char *tmp, char *tmp2);
int		ft_texture_counter(char **wtext, int i, int j, int k);
void	ft_free_mlx_ptrs(t_data *data);
void	ft_map_and_character(t_data *data);
void	ft_mlx_hook(t_data *data);
void	ft_check_stars(t_data *data, int i, int j);
void	ft_check_stars_helper(t_data *data, int i, int j, char *line);
void	ft_check_border(t_data *data, int i, int j);
void	ft_get_new_map(t_data *data);
char	**get_len_and_alloc(void);
void	double_array_printer(char **array);
void	ft_split_helper(int *k, int *i, char *str);
void	key_w(t_data *data);
void	key_a(t_data *data);
void	key_s(t_data *data);
void	key_d(t_data *data);
int		player(char c);
int		ft_exit(void *param);
void	ft_move(t_data *data);
int		ft_init(t_data *data);
void	key_left(t_data *data);
int		key_hook(void *param);
void	ft_error(char *str, t_data *data);
void	key_right(t_data *data);
void	ft_raydistance(t_data *data);
void	ft_dda(t_data *data);
int		ft_tab_len(char **tab, int i);
void	flood_fill(t_data *data, int y, int x);
int		ft_key_press(int key, void *param);
void	ft_send_ray(t_data *data, int x);
void	ft_free_map(t_map *map);
void	ft_check_flood(t_data *data);
void	ft_init_ray(t_ray *ray);
int		ft_is_map_char(char c);
int		ft_key_released(int keycode, void *param);
void	ft_check_map(t_data *data);
void	ft_direction(t_data *data);
void	ft_free_data(t_data *data, int i);
void	ft_planes(t_data *data, char c);
void	ft_free_array(char **array);
int		ft_walls(t_data *data, char *texture, int index);
void	ft_create_map(t_data *data);
int		ft_init_images(t_data *data);
void	ft_ray_cast(t_data *data, int x);
int		ft_process_map_data(t_data *data, char *map_data, int i);
void	ft_set_direction(t_data *data, char c);
void	ft_get_direction(t_data *data, char c);
void	ft_side_walls(t_data *data, int x);
void	ft_help_texture(t_data *data);
int		ft_multiple_map_check(char *str, int i);
int		ft_map_extension_check(char *file, int i);
void	ft_check_player_amount(t_data *data);
int		ft_init_image_array(t_data *data, int i);
int		ft_split_lines(char *str, char ***t, t_data *data);
void	ft_check_characters(t_data *data);
int		ft_max_index(char **map);
int		ft_create_main_image(t_data *data);
void	ft_draw_walls(t_data *data, int x, int tex_index);
void	ft_player_location(t_data *data);
int		ft_process_map(t_data *data);
int		ft_join_read_map(int fd, char **result);
void	ft_place_floor_ceiling(t_data *data);
int		ft_check_load_textures(t_data *data, char *line);

#endif