/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:12:15 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/13 12:59:57 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*copy;

	j = 0;
	i = 0;
	while (s[i] != '\0')
		i++;
	copy = ft_calloc(i + 1, (sizeof(char)));
	if (copy == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		copy[j] = s[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
