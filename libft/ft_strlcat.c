/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:47:35 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/13 12:43:16 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			len_dest;
	size_t			len_src;
	unsigned int	i;

	i = 0;
	if ((!dst || !src) && !size)
		return (0);
	len_dest = ft_strlen((const char *)dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (len_dest == size - 1)
		return (len_dest + len_src);
	else if (len_dest > size - 1)
		return (size + len_src);
	else
	{
		while (src[i] != '\0' && len_dest + i < size - 1)
		{
			dst[len_dest + i] = src[i];
			i++;
		}
		dst[len_dest + i] = '\0';
		return (len_src + len_dest);
	}
}
