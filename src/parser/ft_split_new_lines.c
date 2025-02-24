/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_new_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:27:49 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:48 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	**get_len_and_alloc(void)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (4));
	if (!tab)
		return (ft_error("Malloc failed", NULL), NULL);
	return (tab);
}

void	ft_split_helper(int *k, int *i, char *str)
{
	*k = *i - 2;
	while (str[(*i)] != '\0' && !(str[(*i)] != '\n' && \
		str[(*i) - 1] == '\n' && str[(*i) - 2] == '\n'))
		(*i)++;
	while (str[(*i)] == '\n')
		(*i)++;
}

int	line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int	dir_setter_helper(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	if ((str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ') || \
		(str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ') || \
		(str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ') || \
		(str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' '))
		return (1);
	return (0);
}

void	ft_free_tmps(char *tmp, char *tmp2)
{
	free(tmp);
	free(tmp2);
}
