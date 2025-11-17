/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:47:01 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/06 09:37:21 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*strcat;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	strcat = ft_calloc(size, sizeof(char));
	if (strcat == NULL)
		return (0);
	ft_strlcpy(strcat, s1, ft_strlen(s1) + 1);
	ft_strlcat(strcat, s2, size);
	return (strcat);
}
