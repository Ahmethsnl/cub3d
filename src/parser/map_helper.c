/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:27:00 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:27:26 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	**array_trimmer(char **tab)
{
	int		i;
	char	**trimmed_tab;

	i = 0;
	while (tab[i] != NULL)
		i++;
	trimmed_tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (!trimmed_tab)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		trimmed_tab[i] = ft_strtrim(tab[i], " ");
		if (!trimmed_tab[i])
		{
			while (i > 0)
				free(trimmed_tab[--i]);
			free(trimmed_tab);
			return (NULL);
		}
		i++;
	}
	trimmed_tab[i] = NULL;
	return (trimmed_tab);
}

int	invalid_str_check(char *str, int i)
{
	char	**tmp;
	char	**map;

	tmp = ft_split(str, '\n');
	map = array_trimmer(tmp);
	if (!map)
		return (1);
	while (map[i])
	{
		if (!((map[i][0] == 'N' && map[i][1] == 'O' && map[i][2] == ' ') || \
		(map[i][0] == 'S' && map[i][1] == 'O' && map[i][2] == ' ') || \
		(map[i][0] == 'W' && map[i][1] == 'E' && map[i][2] == ' ') || \
		(map[i][0] == 'E' && map[i][1] == 'A' && map[i][2] == ' ')) && \
		!((map[i][0] == 'F' && map[i][1] == ' ') || (map[i][0] == 'C' && \
		map[i][1] == ' ')) && !((map[i][0] == '1' || map[i][0] == '0')) \
		&& !(map[i][0] == '\0'))
		{
			ft_free_arrys(tmp, map);
			return (1);
		}
		i++;
	}
	ft_free_arrys(tmp, map);
	return (0);
}

int	is_map_line(char *str, int i)
{
	if (str[i] == '\n')
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'S' && \
		str[i] != 'W' && str[i] != 'E')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*map_setter_plus(char *str, int i, int j)
{
	char	*map;
	int		flag1;

	flag1 = 0;
	while (str[i] && !flag1)
	{
		if (str[i] == '\n')
		{
			if (is_map_line(str, i + 1))
			{
				i += 1;
				flag1 = 1;
			}
		}
		i++;
	}
	j = ft_strlen(str) - 1;
	while (j > 0 && (str[j] == '\n' || str[j] == ' '))
	{
		j--;
	}
	map = ft_substr(str, i, (j + 1) - i);
	return (map);
}

int	ft_split_lines(char *str, char ***t, t_data *data)
{
	char	**tab;

	if (invalid_str_check(str, 0))
	{
		free(str);
		ft_error("Invalid map file", data);
	}
	tab = get_len_and_alloc();
	tab[0] = dir_setter(str, 0, 0);
	tab[1] = rgb_setter(str, 0, 0);
	tab[2] = map_setter_plus(str, 0, 0);
	tab[3] = NULL;
	if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL)
	{
		if (tab[2] == NULL)
		{
			ft_free_array(tab);
			free(str);
			ft_error("Map error", data);
		}	
		return (1);
	}
	*t = tab;
	return (0);
}
