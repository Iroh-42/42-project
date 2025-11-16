/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:01:25 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/15 10:57:11 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(const char *s, int fd)
{
	ssize_t	written;

	if (!s)
		return (0);
	written = write(fd, s, ft_strlen(s));
	if (written < 0)
		return (0);
	return ((int)written);
}
