/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:29:03 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:25 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_dda(t_data *data)
{
	data->ray->wall = 0;
	while (!data->ray->wall)
	{
		if (data->ray->sidedistx < data->ray->sidedisty)
		{
			data->ray->sidedistx += data->ray->deltadistx;
			data->ray->grid_x += data->ray->stepx;
			data->ray->side = 0;
		}
		else
		{
			data->ray->sidedisty += data->ray->deltadisty;
			data->ray->grid_y += data->ray->stepy;
			data->ray->side = 1;
		}
		if (data->map->map[data->ray->grid_x][data->ray->grid_y] == WALL)
			data->ray->wall = 1;
	}
}

void	ft_raydistance(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->perpwalldist = data->ray->sidedistx - data->ray->deltadistx;
	else
		data->ray->perpwalldist = data->ray->sidedisty - data->ray->deltadisty;
	if (data->ray->perpwalldist < 0.001)
		data->ray->perpwalldist += 0.001;
	data->ray->lineheight = (int)(SHEIGHT / data->ray->perpwalldist * 2);
	data->ray->drawstart = -data->ray->lineheight / 2 + SHEIGHT / 2;
	if (data->ray->drawstart < 0)
		data->ray->drawstart = 0;
	data->ray->drawend = data->ray->lineheight / 2 + SHEIGHT / 2;
	if (data->ray->drawend >= SHEIGHT)
		data->ray->drawend = SHEIGHT - 1;
}

void	ft_send_ray(t_data *data, int x)
{
	ft_direction(data);
	ft_dda(data);
	ft_raydistance(data);
	ft_side_walls(data, x);
}
