/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:08:57 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/15 11:10:44 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd, int *written_count)
{
	long int	value;

	value = n;
	if (value < 0)
	{
		*written_count += ft_putchar_fd('-', fd);
		value = value * -1;
	}
	if (value >= 10)
	{
		ft_putnbr_fd(value / 10, fd, written_count);
		*written_count += ft_putchar_fd(value % 10 + '0', fd);
	}
	if (value < 10)
		*written_count += ft_putchar_fd(value + '0', fd);
	return (*written_count);
}
