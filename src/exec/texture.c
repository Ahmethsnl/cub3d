/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:26:21 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:18 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_help_texture(t_data *data)
{
	double	wallx;

	if (data->ray->side == 0)
		wallx = data->ray->posy + data->ray->perpwalldist * data->ray->raydiry;
	else
		wallx = data->ray->posx + data->ray->perpwalldist * data->ray->raydirx;
	wallx -= floor(wallx);
	data->ray->textr_x = (int)(wallx * (double)64);
	if (data->ray->side == 0 && data->ray->raydirx > 0)
		data->ray->textr_x = 64 - data->ray->textr_x - 1;
	if (data->ray->side == 1 && data->ray->raydiry < 0)
		data->ray->textr_x = 64 - data->ray->textr_x - 1;
	data->ray->textr_step = 1.0 * 64 / data->ray->lineheight;
	data->ray->textr_pos = (data->ray->drawstart - SHEIGHT
			/ 2 + data->ray->lineheight / 2) * data->ray->textr_step;
}

void	ft_draw_walls(t_data *data, int x, int tex_index)
{
	int			texy;

	while (data->ray->drawstart < data->ray->drawend)
	{
		texy = (int)data->ray->textr_pos & 63;
		data->ray->textr_pos += data->ray->textr_step;
		if (data->images[tex_index]->addr[64 * texy + data->ray->textr_x] > 0)
			data->mlx_o_data[data->ray->drawstart * SWIDTH + x]
				= data->images[tex_index]->addr[64 * texy + data->ray->textr_x];
		data->ray->drawstart++;
	}
}

void	ft_side_walls(t_data *data, int x)
{
	ft_help_texture(data);
	if (data->ray->side == 0 && data->ray->raydirx > 0)
		ft_draw_walls(data, x, 1);
	else if (data->ray->side == 0 && data->ray->raydirx < 0)
		ft_draw_walls(data, x, 2);
	else if (data->ray->side == 1 && data->ray->raydiry > 0)
		ft_draw_walls(data, x, 3);
	else
		ft_draw_walls(data, x, 4);
}
