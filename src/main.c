/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:27:07 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:15:22 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_set_direction(t_data *data, char c)
{
	if (c == NORTH)
	{
		data->ray->dirx = -1;
		data->ray->diry = 0;
	}
	else if (c == SOUTH)
	{
		data->ray->dirx = 1;
		data->ray->diry = 0;
	}
	else if (c == WEST)
	{
		data->ray->dirx = 0;
		data->ray->diry = -1;
	}
	else if (c == EAST)
	{
		data->ray->dirx = 0;
		data->ray->diry = 1;
	}
}

void	ft_planes(t_data *data, char c)
{
	if (c == NORTH)
	{
		data->ray->plane_x = 0;
		data->ray->plane_y = 0.66;
	}
	else if (c == SOUTH)
	{
		data->ray->plane_x = 0;
		data->ray->plane_y = -0.66;
	}
	else if (c == WEST)
	{
		data->ray->plane_x = -0.66;
		data->ray->plane_y = 0;
	}
	else if (c == EAST)
	{
		data->ray->plane_x = 0.66;
		data->ray->plane_y = 0;
	}
}

void	ft_get_direction(t_data *data, char c)
{
	ft_set_direction(data, c);
	ft_planes(data, c);
}

void	ft_player_location(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == NORTH
			|| data->map->map[i][j] == SOUTH
			|| data->map->map[i][j] == WEST
			|| data->map->map[i][j] == EAST)
			{
				data->ray->posx = i + 0.5;
				data->ray->posy = j + 0.5;
				ft_get_direction(data, data->map->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
	ft_error("Player cannot found", data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_printf("Argument error\n");
		return (1);
	}
	ft_map_extension_check(argv[1], 0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	ft_memset(data, 0, sizeof(t_data));
	data->map_path = argv[1];
	if (ft_init(data))
	{
		ft_error("Malloc", data);
		return (1);
	}
	ft_mlx_hook(data);
	ft_free_data(data, 1);
}
