/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:45:10 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/25 10:34:40 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnjoin(char *s1, const char *s2, size_t size)
{
	char	*str_cat;
	size_t	len1;
	size_t	i;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	str_cat = ft_calloc(len1 + size + 1, sizeof(char));
	if (s1)
		ft_strlcpy(str_cat, s1, len1 + 1);
	i = 0;
	while (i < size)
	{
		str_cat[len1 + i] = s2[i];
		i++;
	}
	str_cat[len1 + i] = '\0';
	if (s1)
		free(s1);
	return (str_cat);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			len;

	len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len);
	while ((src[i] != '\0') && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			total;
	size_t			i;
	char			*temp;

	total = nmemb * size;
	if (size && nmemb && nmemb > (size_t) - 1 / size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	temp = ptr;
	while (i < total)
	{
		temp[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *) &s[i]);
	return (NULL);
}
