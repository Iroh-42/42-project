/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:45:13 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/25 14:53:25 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*temp;

	if (!s)
		return ;
	i = 0;
	temp = s;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

static char	*ft_strndup(const char *s, size_t len_line)
{
	size_t		i;
	size_t		len_s;
	char		*copy;

	i = 0;
	len_s = ft_strlen(s);
	copy = ft_calloc(len_line + 1, (sizeof(char)));
	if (copy == NULL)
		return (NULL);
	while (i < len_s)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	update_stack(t_data_keep data)
{
	char	*t_stack;

	t_stack = ft_strndup(data->stack, ft_strlen(data->stack));
	if (!t_stack)
		t_stack = NULL;
	free(data->stack);
	data->stack = ft_strndup(ft_strchr(t_stack, '\n') + 1, BUFFER_SIZE + 1);
	if (!data->stack)
		data->stack = NULL;
	data->kp_i = 0;
	free(t_stack);
}

static char	*extract_line(t_data_keep data, char *line, int fd)
{
	while (!ft_strchr(data->stack, '\n'))
	{
		line = ft_strnjoin(line, data->stack, ft_strlen(data->stack));
		ft_bzero(data->stack, ft_strlen(data->stack));
		data->eof = read(fd, data->stack, BUFFER_SIZE);
		if (!line || (data->eof == 0 && line[0] == '\0'))
		{
			free(data->stack);
			data->stack = NULL;
			if (line)
				free(line);
			return (NULL);
		}
		if (data->eof == 0)
		{
			free(data->stack);
			data->stack = NULL;
			return (line);
		}
	}
	while (data->stack[data->kp_i] != '\n')
		data->kp_i++;
	line = ft_strnjoin(line, data->stack, data->kp_i + 1);
	update_stack(data);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_data_keep	data;
	char				*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (!data[fd].stack)
	{
		data[fd].stack = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!data[fd].stack)
			return (NULL);
		data[fd].eof = read(fd, data[fd].stack, BUFFER_SIZE);
		if (data[fd].eof == 0 || data[fd].eof == -1)
		{
			free(data[fd].stack);
			data[fd].stack = NULL;
			return (NULL);
		}
	}
	line = extract_line(&data[fd], line, fd);
	if (!line)
		return (NULL);
	return (line);
}
