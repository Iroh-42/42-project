/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:45:16 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/20 10:52:43 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	100
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef int	t_bool;

typedef struct s_data_keep
{
	char	stack[BUFFER_SIZE + 1];
	int		fd;
	size_t	kp_i;
	size_t	eof;
}	t_data_keep;

size_t	ft_strlen(const char *s);
char	*ft_strnjoin(char *s1, char const *s2, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);

#endif