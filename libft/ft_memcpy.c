/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:24:57 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/13 10:31:33 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*temp;
	const char		*temp2;

	temp = dest;
	temp2 = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		temp[i] = temp2[i];
		i++;
	}
	return (dest);
}
