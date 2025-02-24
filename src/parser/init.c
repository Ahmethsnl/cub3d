/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:27:13 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:27:22 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_process_map(t_data *data)
{
	char	*map_data;

	data->map_fd = open(data->map_path, O_RDONLY);
	if (data->map_fd < 0)
		return (1);
	if (ft_join_read_map(data->map_fd, &map_data))
		return (1);
	if (ft_process_map_data(data, map_data, 0))
	{
		return (1);
	}
	return (0);
}

int	ft_comma_counter(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	ft_is_only_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_rgb_cleaner_helper(t_data *data, char *tmp, char *tmp2)
{
	ft_free_tmps(tmp, tmp2);
	ft_error("Invalid rgb values", data);
}

char	**ft_rgb_cleaner(char *rgb_str, int i, t_data *data)
{
	char	**rgb;
	char	*tmp;
	char	*tmp2;

	tmp = ft_substr(rgb_str, 1, ft_strlen(rgb_str) - 1);
	tmp2 = ft_strtrim(tmp, " ");
	if (ft_comma_counter(tmp2) != 2)
		ft_rgb_cleaner_helper(data, tmp, tmp2);
	rgb = ft_split(tmp2, ',');
	ft_free_tmps(tmp, tmp2);
	while (rgb[i] && tmp)
	{
		tmp = ft_strtrim(rgb[i], " ");
		if (ft_strchr(tmp, ' ') || !ft_is_only_numeric(tmp))
		{
			ft_free_array(rgb);
			ft_rgb_cleaner_helper(data, tmp, NULL);
		}
		free(rgb[i]);
		rgb[i] = tmp;
		i++;
	}
	return (rgb);
}
