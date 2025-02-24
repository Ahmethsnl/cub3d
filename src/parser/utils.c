/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:25:50 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:27:36 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_place_floor_ceiling(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < SHEIGHT / 2)
	{
		n = 0;
		while (n < SWIDTH)
		{
			data->mlx_o_data[i * SWIDTH + n] = data->map->cecolor;
			n++;
		}
		i++;
	}
	while (i < SHEIGHT)
	{
		n = 0;
		while (n < SWIDTH)
		{
			data->mlx_o_data[i * SWIDTH + n] = data->map->fcolor;
			n++;
		}
		i++;
	}
}

int	ft_tab_len(char **tab, int i)
{
	while (tab[i])
		i++;
	return (i);
}

int	compare_strings(const char *str1, const char *str2)
{
	int	len1;
	int	len2;
	int	i;
	int	j;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	i = 0;
	while (i <= len1 - len2)
	{
		j = 0;
		while (j < len2)
		{
			if (str1[i + j] != str2[j])
				break ;
			j++;
		}
		if (j == len2)
			return (i + j - 1);
		i++;
	}
	return (-1);
}
