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

int	ft_putnbr_fd(int n, int fd, int *nb_write_char)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd, nb_write_char);
		*nb_write_char += ft_putchar_fd(nb % 10 + '0', fd);
	}
	if (nb < 10)
		*nb_write_char += ft_putchar_fd(nb + '0', fd);
	return (*nb_write_char);
}
