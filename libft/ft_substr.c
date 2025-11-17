/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:37:13 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/13 13:00:55 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	len_str;

	len_str = 0;
	if (!s || start > ft_strlen(s))
	{
		sub_str = ft_calloc(1, sizeof(char));
		if (!sub_str)
			return (NULL);
		return (sub_str);
	}
	len_str = ft_strlen(&s[start]);
	if (len >= len_str)
		len = (len_str + 1);
	else
		len = len + 1;
	sub_str = ft_calloc(len, sizeof(char));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, &s[start], len);
	return (sub_str);
}
