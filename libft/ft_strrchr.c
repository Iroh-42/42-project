/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:36:43 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/13 10:39:38 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len_src;

	len_src = ft_strlen(s);
	if (s[len_src] == (char)c)
		return ((char *) &s[len_src]);
	while (len_src > 0)
	{
		len_src--;
		if (s[len_src] == (char)c)
			return ((char *) &s[len_src]);
	}
	return (NULL);
}
