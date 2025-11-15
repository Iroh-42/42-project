/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:15:19 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/15 15:35:00 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_itoa(va_list list, char format, int *nb_write_char)
{
	char			*str;
	unsigned long	nbr;

	str = NULL;
	if (format == 'p')
	{
		nbr = va_arg(list, unsigned long);
		if (!nbr)
		{
			*nb_write_char += ft_putstr_fd("(nil)", 1);
			return (*nb_write_char);
		}
		str = ft_itoa_base(nbr, BASE_HEX_MIN);
		*nb_write_char += ft_putstr_fd("0x", 1);
	}
	else if (format == 'x')
		str = ft_itoa_base(va_arg(list, unsigned int), BASE_HEX_MIN);
	else if (format == 'X')
		str = ft_itoa_base(va_arg(list, unsigned int), BASE_HEX_MAX);
	*nb_write_char += ft_putstr_fd(str, 1);
	free (str);
	return (*nb_write_char);
}

static int	next_pourcent(va_list list, const char *format, int *nb_write_char)
{
	char	*str;
	char	*ptr;

	if (format[0] == 'c')
		*nb_write_char += ft_putchar_fd(va_arg(list, unsigned int), 1);
	else if (format[0] == 's')
	{
		ptr = va_arg(list, char *);
		if (!ptr)
			*nb_write_char += ft_putstr_fd("(null)", 1);
		*nb_write_char += ft_putstr_fd(ptr, 1);
	}
	else if (format[0] == 'i' || format[0] == 'd')
		ft_putnbr_fd(va_arg(list, int), 1, nb_write_char);
	else if (format[0] == 'u')
	{
		str = ft_itoa_base(va_arg(list, unsigned int), BASE_DEC);
		*nb_write_char += ft_putstr_fd(str, 1);
	}
	else if (format[0] == 'p' || format[0] == 'x' || format[0] == 'X')
		check_itoa(list, format[0], nb_write_char);
	else if (format[0] == '%')
		*nb_write_char += ft_putchar_fd('%', 1);
	return (*nb_write_char);

}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				nb_write_char;
	va_list			list;

	i = 0;
	nb_write_char = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			next_pourcent(list, &format[++i], &nb_write_char);
			i++;
		}
		else
		{
			nb_write_char += ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	va_end(list);
	return (nb_write_char);
}
