/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:26:35 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:20 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_is_map_char(char c)
{
	if (c == NORTH || c == SOUTH
		|| c == EAST || c == WEST)
		return (1);
	return (0);
}

void	key_w(t_data *data)
{
	if (data->map->map[(int)(data->ray->posx + data->ray->dirx
			* 0.01)][(int)(data->ray->posy)] == '0'
		|| ft_is_map_char(data->map->map[(int)(data->ray->posx + data->ray->dirx
				* 0.01)][(int)(data->ray->posy)]))
		data->ray->posx += data->ray->dirx * 0.01;
	if (data->map->map[(int)data->ray->posx][(int)(data->ray->posy
		+ data->ray->diry * 0.01)] == '0'
		|| ft_is_map_char(data->map->map[(int)data->ray->posx] \
		[(int)(data->ray->posy + data->ray->diry * 0.01)]))
		data->ray->posy += data->ray->diry * 0.01;
}

void	key_s(t_data *data)
{
	if (data->map->map[(int)(data->ray->posx - data->ray->dirx
			* 0.01)][(int)(data->ray->posy)] == '0'
		|| ft_is_map_char(data->map->map[(int)(data->ray->posx - data->ray->dirx
				* 0.01)][(int)(data->ray->posy)]))
		data->ray->posx -= data->ray->dirx * 0.01;
	if (data->map->map[(int)(data->ray->posx)][(int)(data->ray->posy
			- data->ray->diry * 0.01)] == '0'
		|| ft_is_map_char(data->map->map[(int)(data->ray->posx)][
			(int)(data->ray->posy - data->ray->diry * 0.01)]))
		data->ray->posy -= data->ray->diry * 0.01;
}

void	key_d(t_data *data)
{
	if (data->map->map[(int)(data->ray->posx + data->ray->diry
			* 0.01)][(int)(data->ray->posy)] == '0'
		|| ft_is_map_char(data->map->map[(int)(data->ray->posx + data->ray->diry
				* 0.01)][(int)(data->ray->posy)]))
		data->ray->posx += data->ray->diry * 0.01;
	if (data->map->map[(int)(data->ray->posx)][(int)(data->ray->posy
			- data->ray->dirx * 0.01)] == '0'
		|| ft_is_map_char(data->map->map[(int)(data->ray->posx)]
		[(int)(data->ray->posy - data->ray->dirx * 0.01)]))
		data->ray->posy -= data->ray->dirx * 0.01;
}

void	key_a(t_data *data)
{
	if (data->map->map[(int)(data->ray->posx - data->ray->diry
			* 0.01)][(int)(data->ray->posy)] == '0'
		|| ft_is_map_char(data->map->map[(int)(data->ray->posx - data->ray->diry
				* 0.01)][(int)(data->ray->posy)]))
		data->ray->posx -= data->ray->diry * 0.01;
	if (data->map->map[(int)(data->ray->posx)][(int)(data->ray->posy
			+ data->ray->dirx * 0.01)] == '0'
		|| ft_is_map_char(data->map->map[(int)(data->ray->posx)]
		[(int)(data->ray->posy + data->ray->dirx * 0.01)]))
		data->ray->posy += data->ray->dirx * 0.01;
}
