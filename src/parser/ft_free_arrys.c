/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arrys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:27:56 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:42 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_free_arrys(char **tmp, char **map)
{
	ft_free_array(tmp);
	ft_free_array(map);
}

void	ft_xpm_files_check(t_data *data, char **line)
{
	int		fd;
	char	**tmp;
	int		i;

	i = 0;
	while (line[i])
	{	
		tmp = ft_split(line[i], ' ');
		fd = open(tmp[1], O_RDONLY);
		if (fd < 0)
		{
			ft_free_array(tmp);
			ft_error("Invalid XPM file", data);
		}
		close(fd);
		ft_free_array(tmp);
		i++;
	}
}

int	ft_join_read_map(int fd, char **result)
{
	char	*line;
	char	*tmp;

	tmp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			break ;
		}
		tmp = ft_strjoin_gnl(tmp, line);
		free(line);
	}
	*result = tmp;
	return (0);
}

int	map_setter_util2(char **map, char *str, int *i, int j)
{
	char	*tmp;
	char	*tmp2;

	*i += line_len(str + *i);
	tmp = *map;
	tmp2 = ft_substr(str, j, (*i - j));
	*map = ft_strjoin(*map, tmp2);
	ft_free_tmps(tmp, tmp2);
	tmp = *map;
	*map = ft_strjoin(*map, "\n");
	free(tmp);
	return (1);
}
