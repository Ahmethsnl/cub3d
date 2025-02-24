/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:28:01 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:38 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_map(t_map *map)
{
	if (map->floor)
		ft_free_array(map->floor);
	if (map->ceiling)
		ft_free_array(map->ceiling);
	if (map->map)
		ft_free_array(map->map);
	if (map->flood_fill)
		ft_free_array(map->flood_fill);
	if (map->cstr)
		free(map->cstr);
	if (map->fstr)
		free(map->fstr);
	if (map->mstr)
		free(map->mstr);
	if (map->wtexture)
		ft_free_array(map->wtexture);
	free(map);
}

void	ft_free_data(t_data *data, int i)
{
	if (data->map)
		ft_free_map(data->map);
	if (data->ray)
		free(data->ray);
	if (data->images)
	{
		while (i < TTEXTURES)
		{
			if (data->images[i])
			{
				if (data->images[i]->img)
					mlx_destroy_image(data->mlx_ptr, data->images[i]->img);
				free(data->images[i]);
			}
			i++;
		}
		free(data->images[0]);
		free(data->images);
	}
	ft_free_mlx_ptrs(data);
	free(data);
}

void	ft_free_mlx_ptrs(t_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	ft_error(char *str, t_data *data)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	if (data)
		ft_free_data(data, 1);
	data = NULL;
	exit(1);
}
