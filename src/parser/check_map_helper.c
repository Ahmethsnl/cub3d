/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:29:19 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:16 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	player(char c)
{
	if (c == NORTH || c == SOUTH || \
		c == WEST || c == EAST)
		return (1);
	return (0);
}

void	ft_check_player_amount(t_data *data)
{
	int	i;
	int	j;
	int	player_amount;

	i = 0;
	player_amount = 0;
	while (i < data->map->grid_y && data->map->map[i])
	{
		j = 0;
		while (j < (int)ft_strlen(data->map->map[i]))
		{
			if (player(data->map->map[i][j]))
				player_amount++;
			j++;
		}
		i++;
	}
	if (player_amount != 1)
		ft_error("There are more than one player", data);
}

void	ft_check_characters(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->grid_y && data->map->map[i])
	{
		j = 0;
		while (j < (int)ft_strlen(data->map->map[i]))
		{
			if (data->map->map[i][j] != FLOOR && \
			data->map->map[i][j] != WALL && data->map->map[i][j] != NORTH && \
			data->map->map[i][j] != SOUTH && data->map->map[i][j] != WEST && \
			data->map->map[i][j] != EAST && data->map->map[i][j] != ' ')
				ft_error("Map includes wrong characters", data);
			j++;
		}
		i++;
	}
}

int	ft_map_extension_check(char *file, int i)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error("Incorrect map extension", NULL), 0);
	close(fd);
	i = ft_strlen(file) - 1;
	if (ft_strlen(file) < 5)
	{
		ft_error("Incorrect map extension", NULL);
		return (1);
	}
	if (!(file[i] == 'b' && file[i - 1] == 'u' && \
	file[i - 2] == 'c' && file[i - 3] == '.'))
		return (ft_error("Incorrect map extension", NULL), 0);
	else if (file[i - 4] && file[i - 4] == '/')
		return (ft_error("Incorrect map extension", NULL), 0);
	return (0);
}

void	ft_map_and_character(t_data *data)
{
	ft_create_map(data);
	ft_player_location(data);
	ft_check_map(data);
}
