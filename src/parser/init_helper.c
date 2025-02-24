/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:27:42 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:53 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_max_index(char **map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

void	ft_create_map(t_data *data)
{
	if (ft_multiple_map_check(data->map->mstr, 0))
	{
		ft_error("Multiple maps", data);
	}
	data->map->map = ft_split(data->map->mstr, '\n');
	data->map->flood_fill = ft_split(data->map->mstr, '\n');
	data->map->grid_x = ft_max_index(data->map->map);
	data->map->grid_y = ft_tab_len(data->map->map, 0);
}

void	ft_init_ray(t_ray *ray)
{
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->perpwalldist = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->grid_x = 0;
	ray->grid_y = 0;
	ray->side = 0;
	ray->wall = 0;
	ray->raydirx = 0;
	ray->raydiry = 0;
}

int	ft_check_load_textures(t_data *data, char *line)
{
	char	*texture;
	char	*texture_tmp;
	int		err;
	char	*tmp;

	err = 0;
	tmp = ft_strtrim(line, " ");
	texture_tmp = ft_strdup(tmp + 2);
	texture = ft_strtrim(texture_tmp, " ");
	free(texture_tmp);
	if (ft_strncmp(line, "NO", 2) == 0)
		err = ft_walls(data, texture, 1);
	else if (ft_strncmp(tmp, "SO", 2) == 0)
		err = ft_walls(data, texture, 2);
	else if (ft_strncmp(tmp, "WE", 2) == 0)
		err = ft_walls(data, texture, 3);
	else if (ft_strncmp(tmp, "EA", 2) == 0)
		err = ft_walls(data, texture, 4);
	else
	{
		free(texture);
		return (1);
	}
	free(tmp);
	return (err);
}

int	ft_texture_counter(char **wtext, int i, int j, int k)
{
	char	**t;

	t = malloc(sizeof(char *) * 4);
	while (++j < 4)
		t[j] = "0";
	while (wtext[i])
	{
		k = 0;
		while (wtext[i][k] && wtext[i][k + 1])
		{
			if (wtext[i][k] == 'N' && wtext[i][k + 1] == 'O')
				t[0] = "1";
			else if (wtext[i][k] == 'S' && wtext[i][k + 1] == 'O')
				t[1] = "1";
			else if (wtext[i][k] == 'W' && wtext[i][k + 1] == 'E')
				t[2] = "1";
			else if (wtext[i][k] == 'E' && wtext[i][k + 1] == 'A')
				t[3] = "1";
			k++;
		}	
		i++;
	}
	i = (t[0][0] == '1' && t[1][0] == '1' && t[2][0] == '1' && t[3][0] == '1');
	free(t);
	return (i);
}
