/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:45:13 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/19 16:46:51 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


// static void	ft_bzero(void *s, size_t n)
// {
// 	unsigned int	i;
// 	char			*temp;

// 	i = 0;
// 	temp = s;
// 	while (i < n)
// 	{
// 		temp[i] = 0;
// 		i++;
// 	}
// }

static char	*ft_strdup(const char *s, size_t len_line)
{
	size_t		i;
	char	*copy;

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

static char	*cpy_line(t_data_keep *data, size_t len_line,
	int fd, t_bool is_new_line)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	if (is_new_line)
	{
		line = ft_strdup(&data->stack[data->kp_i], len_line);
		data->kp_i = len_line;
	}
	else
	{
		read(fd, data->stack, BUFFER_SIZE);
		line = ft_strdup(&data->stack[data->kp_i], len_line);
		data->kp_i += len_line;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_data_keep	data;
	size_t				len_line;
	char				*line;
	t_bool				is_new_line;

	is_new_line = 0;
	len_line = 0;
	line = NULL;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (data.stack[0] == '\0')
		read(fd, data.stack, BUFFER_SIZE);
	while (data.stack[len_line] != '\n' && data.stack[len_line] != '\0'
		&& len_line <= BUFFER_SIZE)
		len_line++;
	if (data.stack[len_line] == '\n')
		is_new_line = 1;
	line = cpy_line(&data, len_line, fd, is_new_line);
	return (line);
}
