/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:29:09 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:26 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_ray_cast(t_data *data, int x)
{
	x = 0;
	while (x < SWIDTH)
	{
		data->ray->camera = 2 * x / (double)SWIDTH - 1;
		data->ray->raydirx = data->ray->dirx + data->ray->plane_x
			* data->ray->camera;
		data->ray->raydiry = data->ray->diry + data->ray->plane_y
			* data->ray->camera;
		data->ray->grid_x = (int)data->ray->posx;
		data->ray->grid_y = (int)data->ray->posy;
		data->ray->deltadistx = fabs(1 / data->ray->raydirx);
		data->ray->deltadisty = fabs(1 / data->ray->raydiry);
		ft_send_ray(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
}

void	ft_direction(t_data *data)
{
	if (data->ray->raydirx < 0)
	{
		data->ray->stepx = -1;
		data->ray->sidedistx = (data->ray->posx - data->ray->grid_x)
			* data->ray->deltadistx;
	}
	else
	{
		data->ray->stepx = 1;
		data->ray->sidedistx = (data->ray->grid_x + 1.0 - data->ray->posx)
			* data->ray->deltadistx;
	}
	if (data->ray->raydiry < 0)
	{
		data->ray->stepy = -1;
		data->ray->sidedisty = (data->ray->posy - data->ray->grid_y)
			* data->ray->deltadisty;
	}
	else
	{
		data->ray->stepy = 1;
		data->ray->sidedisty = (data->ray->grid_y + 1.0 - data->ray->posy)
			* data->ray->deltadisty;
	}
}
