/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:30:09 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 16:30:10 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!needle[0] && len == 0)
		return ((char *) haystack);
	if (!haystack[0] && !needle[0])
		return ((char *) haystack);
	if ((!haystack && !needle) || len == 0)
		return (NULL);
	i = 0;
	while (haystack[i] && i < len - ft_strlen(needle) + 1)
	{
		if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
			return ((char *) &haystack[i]);
		i++;
	}
	return (NULL);
}
