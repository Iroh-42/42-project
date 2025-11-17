/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:45:13 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/17 17:00:00 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strdup(const char *s, size_t len)
{
	size_t	j;
	char	*copy;

	j = 0;
	copy = ft_calloc(len, (sizeof(char)));
	if (copy == NULL)
		return (NULL);
	while (j < len)
	{
		copy[j] = s[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

static void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	temp = s;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

static char	*untruc(size_t *start, size_t *end, char *stack,
		t_bool jesuisnathan)
{
	char	*str;

	while (jesuisnathan)
	{
		while (*start <= BUFFER_SIZE && jesuisnathan)
		{
			if (stack[*end + *start] == '\n' || stack[*end + *start] == '\0')
			{
				jesuisnathan = 0;
				break ;
			}
			*end = *end + 1;
		}
		*end = *end + 1;
		if (jesuisnathan == 0)
			str = ft_strdup(&stack[*start], *end);
		else
			ft_strjoin(str, &stack[*start], *end);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static size_t	end;
	static size_t	start;
	static char		stack[BUFFER_SIZE]; // taille du seau
	char			*str; //pisicne
	t_bool			jesuisnathan;

	jesuisnathan = 1;
	if (stack[0] == '\0')
	{
		if (read(fd, stack, BUFFER_SIZE) == 0) // si la citerne est vide
			return (NULL);
	}
	else
		start += end;
	end = 0;
	if (start >= BUFFER_SIZE)
	{
		ft_bzero(stack, BUFFER_SIZE); // vide le seau
		if (read(fd, stack, BUFFER_SIZE) == 0)
			return (NULL);
		start = end;
	}
	str = untruc(&start, &end, stack, jesuisnathan);
	while (str[ft_strlen(str) - 1] != '\n')
		str = untruc(&start, &end, stack, jesuisnathan);
	return (str);
}
