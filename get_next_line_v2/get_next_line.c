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

/* Remplit le buffer pour le fd s'il est vide. Retourne :
   >0  : nombre d'octets lus (ou 1 si le buffer était déjà non vide),
   0   : EOF,
   -1  : erreur de lecture. */
static ssize_t	read_buffer(t_data_keep *data, int fd)
{
    ssize_t bytes_read;

    if (data->kp_i >= (size_t)data->bytes)
    {
        bytes_read = read(fd, data->stack, BUFFER_SIZE);
        if (bytes_read <= 0)
            return (bytes_read);
        data->bytes = bytes_read;
        data->stack[data->bytes] = '\0';
        data->kp_i = 0;
        data->fd = fd;
        return (bytes_read);
    }
    return (1);
}

static void	len_new_line(t_data_keep *data, size_t *len, int *has_newline)
{
	size_t l = 0;
	while (data->kp_i + l < (size_t)data->bytes && data->stack[data->kp_i + l] != '\n')
		l++;
	*len = l;
	if (data->kp_i + l < (size_t)data->bytes && data->stack[data->kp_i + l] == '\n')
		*has_newline = 1;
	else
		*has_newline = 0;
}

/* Concatène len (+1 si has_nl) octets du buffer au résultat existant. */
static char *append_chunk(char *result, t_data_keep *data, size_t len, int has_newline)
{
	size_t add;

	if (has_newline)
		add = 1;
	else
		add = 0;
	result = ft_strnjoin(result, &data->stack[data->kp_i], len + add);
	return (result);
}

/* Avance kp_i du nombre d'octets consommés et réinitialise si nécessaire. */
static void	advance_pos(t_data_keep *data, size_t len, int has_newline)
{
	size_t add;

	if (has_newline)
		add = 1;
	else
		add = 0;
	data->kp_i += len + add;
	if (data->kp_i >= (size_t)data->bytes)
	{
		data->kp_i = 0;
		data->bytes = 0;
		data->stack[0] = '\0';
	}
}

char	*get_next_line(int fd)
{
	static t_data_keep	data_store[1024]; /* stockage par fd (supporte multi-fd) */
	char           *result;
	ssize_t        bytes_read;
	size_t         len;
	int            has_newline;

	has_newline = 0;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	while (!has_newline)
	{
		bytes_read = read_buffer(&data_store[fd], fd);
		if (bytes_read <= 0)
			break; /* EOF or error */
		len_new_line(&data_store[fd], &len, &has_newline);
		result = append_chunk(result, &data_store[fd], len, has_newline);
		if (!result)
			return (NULL);
		advance_pos(&data_store[fd], len, has_newline);
	}
	return (result);
}
