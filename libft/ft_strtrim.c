/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:19:06 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/07 14:41:35 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static unsigned int	start_check_set(char const *s1, char const *set)
{
	int	i;
	int	start;

	start = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (check_set(s1[i], set))
			start++;
		else
			break ;
		i++;
	}
	return (start);
}

static unsigned int	end_check_set(char const *s1, char const *set)
{
	size_t	i;
	int		end;

	end = 0;
	i = ft_strlen(s1);
	while (i > 0)
	{
		i--;
		if (check_set(s1[i], set))
			end++;
		else
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int		start;
	unsigned int		end;
	size_t				size;
	char				*copy_s1;

	start = 0;
	end = 0;
	size = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = start_check_set(s1, set);
	end = end_check_set(s1, set);
	if (ft_strlen(s1) == start)
		size = 0;
	else
		size = (ft_strlen(s1) - start) - end;
	copy_s1 = ft_calloc(size + 1, sizeof(char));
	if (!copy_s1)
		return (NULL);
	if (start == ft_strlen(s1))
		copy_s1[0] = '\0';
	ft_strlcpy(copy_s1, s1 + start, size + 1);
	return (copy_s1);
}
