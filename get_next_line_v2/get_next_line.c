/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:45:13 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/20 11:55:07 by gacattan         ###   ########.fr       */
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

static char	*ft_strdup(const char *s, size_t len_line)
{
	size_t		i;
	char		*copy;

	i = 0;

	copy = ft_calloc(len_line + 1, (sizeof(char)));
	if (copy == NULL)
		return (NULL);
	while (i <= len_line)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			i++;
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *) &s[i]);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_data_keep	data;
	char				*line;
	char				*temp_stack;

	line = NULL;
	if (data.stack[0] == '\0')
		data.eof = read(fd, data.stack, BUFFER_SIZE);
	while (!ft_strchr(data.stack, '\n'))
	{
		line = ft_strnjoin(line, data.stack, data.eof);
		data.eof = read(fd, data.stack, BUFFER_SIZE);
		if (!line)
			return (NULL);
		if (data.eof == 0)
			return (line);
	}
	while (data.stack[data.kp_i] != '\n')
		data.kp_i++;
	line = ft_strnjoin(line, data.stack, data.kp_i + 1);
	temp_stack = ft_strdup(data.stack, data.eof);
	if (!temp_stack)
		return (NULL);
	ft_bzero(data.stack, data.eof);
	ft_strlcpy(data.stack, ft_strchr(temp_stack, '\n'), data.eof - data.kp_i);
	data.kp_i = 0;
	free(temp_stack);
	return (line);
}
