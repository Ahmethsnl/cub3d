/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:27:34 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:27:09 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_floor_ceiling_parse_helper(t_data *data, char **tmp2)
{
	char	*tmp;

	tmp = ft_strdup(tmp2[0]);
	free(tmp2[0]);
	tmp2[0] = ft_strtrim(tmp, " ");
	free(tmp);
	tmp = ft_strdup(tmp2[1]);
	free(tmp2[1]);
	tmp2[1] = ft_strtrim(tmp, " ");
	free(tmp);
	if (tmp2[0][0] == 'F')
	{
		data->map->fstr = ft_strdup(tmp2[0]);
		data->map->cstr = ft_strdup(tmp2[1]);
	}
	else if (tmp2[0][0] == 'C')
	{
		data->map->fstr = ft_strdup(tmp2[1]);
		data->map->cstr = ft_strdup(tmp2[0]);
	}
}

int	ft_multiple_map_check(char *str, int i)
{
	while (str[i] && str[i + 1])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n'))
			return (1);
		i++;
	}
	return (0);
}

void	double_array_printer(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}

int	rgb_checker(char **tmp2)
{
	char	*tmp;
	char	*tmp3;

	if (ft_tab_len(tmp2, 0) != 2)
		return (1);
	tmp = ft_strtrim(tmp2[0], " ");
	tmp3 = ft_strtrim(tmp2[1], " ");
	if (((tmp[0] == 'F' && tmp3[0] == 'C') \
	|| (tmp[0] == 'C' && tmp3[0] == 'F')))
	{
		free(tmp);
		free(tmp3);
		return (0);
	}
	free(tmp);
	free(tmp3);
	return (1);
}

int	ft_process_map_data(t_data *data, char *map_data, int i)
{
	char	**t;
	char	**tmp2;
	char	*map_two;

	if (ft_split_lines(map_data, &t, data))
		return (free(map_data), 1);
	data->map->wtexture = ft_split(t[0], '\n');
	if (ft_tab_len(data->map->wtexture, 0) != 4 || \
		ft_texture_counter(data->map->wtexture, 0, -1, 0) != 1)
		return (ft_free_array(t), free(map_data), 1);
	tmp2 = ft_split(t[1], '\n');
	if (rgb_checker(tmp2))
		return (ft_free_array(t), ft_free_array(tmp2), free(map_data), 1);
	ft_floor_ceiling_parse_helper(data, tmp2);
	i = 2;
	map_two = ft_strdup("");
	while (t[i])
	{
		map_two = ft_strjoin_gnl(map_two, t[i]);
		i++;
	}
	data->map->mstr = ft_strtrim(map_two, "\n");
	ft_free_array(t);
	ft_free_array(tmp2);
	return (free(map_data), free(map_two), 0);
}
