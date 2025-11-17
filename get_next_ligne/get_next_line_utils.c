/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:45:10 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/17 16:33:50 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' || s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t size)
{
	char	*strcat;

	if (!s1 || !s2)
		return (NULL);
	if (ft_strlen(s2) > 0)
		size = ft_strlen(s2);
	size = ft_strlen(s1) + size + 1;
	strcat = ft_calloc(size, sizeof(char));
	if (strcat == NULL)
		return (0);
	ft_strlcpy(strcat, s1, ft_strlen(s1) + 1);
	ft_strlcat(strcat, s2, size);
	return (strcat);
}

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
		while ((src[i] != '\0' || src[i] != '\n') && len_dest + i < size - 1)
		{
			dst[len_dest + i] = src[i];
			i++;
		}
		dst[len_dest + i] = '\0';
		return (len_src + len_dest);
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			len;

	len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len);
	while ((src[i] != '\0' || src[i] == '\n') && i < (size - 1))
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
