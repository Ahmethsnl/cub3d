/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:31:44 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 16:31:45 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;	

	if (!dst && !src)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	i = len;
	while (i > 0)
	{
		i--;
		((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
	}
	return (dst);
}
