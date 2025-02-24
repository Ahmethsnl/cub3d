/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:27:20 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:58 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	map_valid_check(t_data *data)
{
	int	i;

	i = -1;
	data->map->floor = ft_rgb_cleaner(data->map->fstr, 0, data);
	data->map->ceiling = ft_rgb_cleaner(data->map->cstr, 0, data);
	if (ft_tab_len(data->map->floor, 0) != 3 && \
		ft_tab_len(data->map->ceiling, 0) != 3)
		ft_error("invalid", data);
	while (++i < 3 && data->map->floor[i] && data->map->ceiling[i])
		if (ft_atoi(data->map->floor[i]) > 255 || \
			ft_atoi(data->map->ceiling[i]) > 255 || \
			ft_atoi(data->map->floor[i]) < 0 || \
			ft_atoi(data->map->ceiling[i]) < 0)
			ft_error("Invalid Map Information", data);
	if (data->map->floor[0] == NULL || data->map->floor[1] == NULL || \
		data->map->floor[2] == NULL || data->map->ceiling[0] == NULL || \
		data->map->ceiling[1] == NULL || data->map->ceiling[2] == NULL)
		ft_error("Invalid RGB Information", data);
	data->map->fcolor = ft_atoi(data->map->floor[0]) * 65536 + \
	ft_atoi(data->map->floor[1]) * 256 + ft_atoi(data->map->floor[2]);
	data->map->cecolor = ft_atoi(data->map->ceiling[0]) * 65536 + \
	ft_atoi(data->map->ceiling[1]) * 256 + ft_atoi(data->map->ceiling[2]);
	return (0);
}

int	ft_init_image_array(t_data *data, int i)
{
	char	*line;

	if (ft_process_map(data))
		return (1);
	if (map_valid_check(data))
		return (1);
	data->images = ft_calloc((TTEXTURES + 1), sizeof(t_images *));
	if (!data->images)
		return (1);
	data->images[TTEXTURES] = NULL;
	ft_map_and_character(data);
	ft_xpm_files_check(data, data->map->wtexture);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, SWIDTH, SHEIGHT, "cub3D");
	while (++i < 4)
	{
		line = ft_strtrim(data->map->wtexture[i], " ");
		if (!line || ft_check_load_textures(data, line))
		{
			free(line);
			return (1);
		}
		free(line);
	}
	return (0);
}

int	ft_create_main_image(t_data *data)
{
	data->mlx_img = mlx_new_image(data->mlx_ptr, SWIDTH, SHEIGHT);
	data->images[0] = malloc(sizeof(t_images));
	if (!data->images[0])
		return (1);
	data->mlx_o_data = (int *)mlx_get_data_addr(data->mlx_img, \
	&data->images[0]->bits_per_pixel, &data->images[0]->line_length, \
	&data->images[0]->endian);
	return (0);
}

int	ft_init_images(t_data *data)
{
	data->images = NULL;
	if (ft_init_image_array(data, -1))
		return (1);
	if (ft_create_main_image(data))
		return (1);
	return (0);
}

int	ft_init(t_data *data)
{
	data->w_pressed = 0;
	data->a_pressed = 0;
	data->s_pressed = 0;
	data->d_pressed = 0;
	data->left = 0;
	data->right = 0;
	data->ray = malloc(sizeof(t_ray));
	ft_init_ray(data->ray);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (1);
	ft_memset(data->map, 0, sizeof(t_map));
	data->map->map = NULL;
	data->map->floor = NULL;
	data->map->ceiling = NULL;
	data->map->flood_fill = NULL;
	data->map->wtexture = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	if (ft_init_images(data))
		return (1);
	return (0);
}
