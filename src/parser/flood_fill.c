/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:28:58 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:14 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_walls(t_data *data, char *texture, int index)
{
	data->images[index] = malloc(sizeof(t_images));
	if (!data->images[index])
		return (1);
	data->images[index]->img = mlx_xpm_file_to_image(data->mlx_ptr, texture, \
	&data->images[index]->width, &data->images[index]->height);
	free(texture);
	if (!data->images[index]->img)
	{
		return (1);
	}
	data->images[index]->addr = \
	(int *)mlx_get_data_addr(data->images[index]->img, \
	&data->images[index]->bits_per_pixel, &data->images[index]->line_length, \
	&data->images[index]->endian);
	return (0);
}

void	ft_check_flood(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->grid_y)
	{
		j = 0;
		while (j < (int)ft_strlen(data->map->map[i]))
		{
			if (player(data->map->flood_fill[i][j])
			|| data->map->flood_fill[i][j] == FLOOR \
			|| data->map->flood_fill[i][j] == WALL)
				ft_error("Multiple maps", data);
			j++;
		}
		i++;
	}
}

void	flood_fill(t_data *data, int x, int y)
{
	if (y < 0 || x < 0 || y >= data->map->grid_y \
	|| x >= (int)ft_strlen(data->map->map[y]) \
	|| data->map->flood_fill[y][x] == 'F')
		return ;
	if (data->map->flood_fill[y][x] == FLOOR \
	|| data->map->flood_fill[y][x] == NORTH \
	|| data->map->flood_fill[y][x] == SOUTH \
	|| data->map->flood_fill[y][x] == WEST \
	|| data->map->flood_fill[y][x] == EAST \
	|| data->map->flood_fill[y][x] == WALL)
	{
		data->map->flood_fill[y][x] = 'F';
		flood_fill(data, x + 1, y);
		flood_fill(data, x - 1, y);
		flood_fill(data, x, y + 1);
		flood_fill(data, x, y - 1);
	}
}
