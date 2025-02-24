/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:30:46 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 16:30:47 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	buf = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		buf[j++] = s1[i++];
	i = 0;
	while (s2[i])
		buf[j++] = s2[i++];
	buf[j] = '\0';
	return (buf);
}
