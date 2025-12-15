/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:45:16 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/27 16:31:04 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

//# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef int	t_bool;

typedef struct s_data_keep
{
	char	*stack;
	int		fd;
	size_t	kp_i;
	ssize_t	eof;
}	t_data_keep[1024];

size_t	ft_strlen(const char *s);
char	*ft_strnjoin(char *s1, char const *s2, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

#endif