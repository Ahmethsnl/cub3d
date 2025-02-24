/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:29:14 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:15 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_check_stars_helper(t_data *data, int i, int j, char *line)
{
	if (j > 0 && !(line[j - 1] == '*' || line[j - 1] == WALL))
		ft_error("Right border of the map is not closed", data);
	if (j < (int)ft_strlen(line) - 1 && !(line[j + 1] == '*' \
		|| line[j + 1] == WALL))
		ft_error("Left border of the map is not closed", data);
	if (i > 0 && !(data->map->map[i - 1][j] == '*' \
		|| data->map->map[i - 1][j] == WALL))
		ft_error("Border border of the map is not closed", data);
	if (i < data->map->grid_y - 1
		&& !(data->map->map[i + 1][j] == '*' \
		|| data->map->map[i + 1][j] == WALL))
		ft_error("Top border of the map is not closed", data);
}

void	ft_check_stars(t_data *data, int i, int j)
{
	char	*line;

	i = 0;
	while (i < data->map->grid_y)
	{
		j = 0;
		line = data->map->map[i];
		while (j < (int)ft_strlen(line))
		{
			if (line[j] == '*')
				ft_check_stars_helper(data, i, j, line);
			j++;
		}
		i++;
	}
}

void	ft_check_border(t_data *data, int i, int j)
{
	i = 0;
	while (i < data->map->grid_y)
	{
		j = 0;
		while (j < (int)ft_strlen(data->map->map[i]))
		{
			if (i == 0 || i == data->map->grid_y - 1 || j == 0 \
			|| j == (int)ft_strlen(data->map->map[i]) - 1)
			{
				if (data->map->map[i][j] != WALL
				&& data->map->map[i][j] != '*')
					ft_error("Map borders is not closed", data);
			}
			j++;
		}
		i++;
	}
}

void	ft_get_new_map(t_data *data)
{
	char	**mapp;
	int		i;
	int		j;

	i = 0;
	mapp = malloc(sizeof(char *) * (data->map->grid_y + 1));
	while (i < data->map->grid_y)
	{
		j = 0;
		mapp[i] = ft_calloc(sizeof(char), (data->map->grid_x + 1));
		ft_memset(mapp[i], '*', data->map->grid_x);
		ft_memcpy(mapp[i], data->map->map[i], ft_strlen(data->map->map[i]));
		while (j < (int)data->map->grid_x)
		{
			if (mapp[i][j] == ' ')
				mapp[i][j] = '*';
			j++;
		}
		i++;
	}
	mapp[i] = NULL;
	ft_free_array(data->map->map);
	data->map->map = mapp;
}

void	ft_check_map(t_data *data)
{
	flood_fill(data, (int)data->ray->posy, (int)data->ray->posx);
	ft_check_flood(data);
	ft_check_player_amount(data);
	ft_check_characters(data);
	ft_get_new_map(data);
	ft_check_stars(data, 0, 0);
	ft_check_border(data, 0, 0);
}
