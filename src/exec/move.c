/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:26:29 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:19 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	key_left(t_data *data)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->ray->dirx;
	data->ray->dirx = data->ray->dirx * cos(0.01) - data->ray->diry
		* sin(0.01);
	data->ray->diry = old_dirx * sin(0.01) + data->ray->diry
		* cos(0.01);
	old_planex = data->ray->plane_x;
	data->ray->plane_x = data->ray->plane_x * cos(0.01) - data->ray->plane_y
		* sin(0.01);
	data->ray->plane_y = old_planex * sin(0.01) + data->ray->plane_y
		* cos(0.01);
}

void	key_right(t_data *data)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->ray->dirx;
	data->ray->dirx = data->ray->dirx * cos(-0.01) - data->ray->diry
		* sin(-0.01);
	data->ray->diry = old_dirx * sin(-0.01) + data->ray->diry
		* cos(-0.01);
	old_planex = data->ray->plane_x;
	data->ray->plane_x = data->ray->plane_x * cos(-0.01) - data->ray->plane_y
		* sin(-0.01);
	data->ray->plane_y = old_planex * sin(-0.01) + data->ray->plane_y
		* cos(-0.01);
}

void	ft_move(t_data *data)
{
	if (data->w_pressed)
		key_w(data);
	if (data->s_pressed)
		key_s(data);
	if (data->left)
		key_left(data);
	if (data->right)
		key_right(data);
	if (data->a_pressed)
		key_a(data);
	if (data->d_pressed)
		key_d(data);
}
