/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:45:13 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/18 13:41:00 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


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

static char	*untruc(size_t *start, size_t *end, char *stack, char *str)
{
	while (*end <= BUFFER_SIZE)
	{
		if (stack[*end + *start] == '\n' || stack[*end + *start] == '\0')
		{
			break ;
		}
		*end = *end + 1;
	}
	*end = *end + 1;
	str = ft_strjoin(str, &stack[*start], *end);
	return (str);
}

char	*get_next_line(int fd)
{
	static size_t	end;
	static size_t	start;
	static char		stack[BUFFER_SIZE];
	char			*str;

	str = NULL;
	if (stack[0] == '\0')
	{
		if (read(fd, stack, BUFFER_SIZE) == 0)
			return (NULL);
	}
	else
		start += end;
	end = 0;
	if (start >= BUFFER_SIZE)
	{
		ft_bzero(stack, BUFFER_SIZE);
		end = 0;
		start = 0;
		if (read(fd, stack, BUFFER_SIZE) == 0)
			return (NULL);
	}
	str = untruc(&start, &end, stack, str);

	while (str[ft_strlen(str)] != '\n')
	{
		start += end;
		if (start >= BUFFER_SIZE)
		{
			ft_bzero(stack, BUFFER_SIZE);
			end = 0;
			start = 0;
			if (read(fd, stack, BUFFER_SIZE) == 0)
				return (str);
		}
		str = untruc(&start, &end, stack, str);
	}
	return (str);
}
