/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:26:50 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:27:31 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*dir_setter(char *str, int i, int k)
{
	char	*dir;
	char	*tmp;
	char	*tmp2;

	dir = ft_strdup("");
	while (str[i])
	{
		k = i;
		if (dir_setter_helper(str, i))
		{
			i += line_len(str + i);
			tmp = dir;
			tmp2 = ft_substr(str, k, (i - k));
			dir = ft_strjoin(dir, tmp2);
			ft_free_tmps(tmp, tmp2);
			tmp = dir;
			dir = ft_strjoin(dir, "\n");
			free(tmp);
		}
		else
			i += line_len(str + i);
		if (str[i] != '\0')
			i++;
	}
	return (dir);
}

int	rgb_setter_helper(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	if ((str[i] == 'F' && str[i + 1] == ' ') || (str[i] == 'C' \
		&& str[i + 1] == ' '))
		return (1);
	return (0);
}

char	*rgb_setter(char *str, int i, int k)
{
	char	*rgb;
	char	*tmp;
	char	*tmp2;

	rgb = ft_strdup("");
	while (str[i])
	{
		k = i;
		if (rgb_setter_helper(str, i))
		{
			i += line_len(str + i);
			tmp = rgb;
			tmp2 = ft_substr(str, k, (i - k));
			rgb = ft_strjoin(rgb, tmp2);
			ft_free_tmps(tmp, tmp2);
			tmp = rgb;
			rgb = ft_strjoin(rgb, "\n");
			free(tmp);
		}
		else
			i += line_len(str + i);
		if (str[i] != '\0')
			i++;
	}
	return (rgb);
}

int	map_setter_helper(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	if (str[i] != 'F' && str[i] != 'C' && str[i] != 'N' \
		&& str[i] != 'S' && str[i] != 'W' && str[i] != 'E' && str[i] != '\n')
		return (1);
	return (0);
}

void	map_trim(char **map)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;

	i = 0;
	if (!(*map[i]))
		return ;
	while ((!((*map)[i] == '1' || (*map)[i] == '0' || (*map)[i] == 'N' \
		|| (*map)[i] == 'S' || (*map)[i] == 'W' || (*map)[i] == 'E') \
		|| ((*map)[i] == ' ' || (*map)[i] == '\n')) && (*map)[i])
		i++;
	while ((*map)[i] != '\n' && i > 0)
		i--;
	j = ft_strlen(*map) - 1;
	while (!((*map)[j] == '1' || (*map)[j] == '0' || (*map)[j] == 'N' \
	|| (*map)[j] == 'S' || (*map)[j] == 'W' || (*map)[j] == 'E') && (*map)[i])
		j--;
	tmp = ft_substr(*map, i, j - i + 1);
	tmp2 = tmp;
	tmp = ft_strjoin(tmp, "\n");
	free(tmp2);
	free(*map);
	*map = tmp;
}
