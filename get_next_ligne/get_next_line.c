/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:45:13 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/19 13:37:41 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


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
			*end = *end + 1;
			break ;
		}
		*end = *end + 1;
	}
	str = ft_strjoin(str, &stack[*start], *end);
	if (!str)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static int 		eof;
	static size_t	end;
	static size_t	start;
	static char		stack[BUFFER_SIZE];
	char			*str;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0 )
		return (NULL);
	str = NULL;
	if (stack[0] == '\0')
		eof = read(fd, stack, BUFFER_SIZE);
	if ((eof == 0 && stack[0] == '\0')
		|| eof == -1)
		return (NULL);
	else
		start += end;
	if (BUFFER_SIZE == 1)
		start = 0;
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
	if (!str)
		return (NULL);
	while (!ft_strrchr(str, '\n'))
	{
		start += end;
		if (start >= BUFFER_SIZE && stack[BUFFER_SIZE - 1] != '\0')
		{
			ft_bzero(stack, BUFFER_SIZE);
			end = 0;
			start = 0;
			if (read(fd, stack, BUFFER_SIZE) == 0)
				return (str);
		}
		str = untruc(&start, &end, stack, str);
		if (!str)
			return (NULL);
	}
	return (str);
}
