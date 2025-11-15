/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:14:54 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/15 11:11:29 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE_HEX_MIN "0123456789abcdef"
# define BASE_HEX_MAX "0123456789ABCDEF"
# define BASE_DEC "0123456789"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n);
int		ft_putchar_fd(char c, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa_base(unsigned long n, char *base);
int		ft_printf(const char *format, ...);
int		ft_putnbr_fd(int n, int fd, int *nb_write_char);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif
