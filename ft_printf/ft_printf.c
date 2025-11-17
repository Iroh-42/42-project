/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:15:19 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/17 13:29:27 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_base(va_list list, char format, int *written_count)
{
	char	*num_str;
	void	*ptr;

	num_str = NULL;
	if (format == 'p')
	{
		ptr = va_arg(list, void *);
		if (!ptr)
		{
			*written_count += ft_putstr_fd("(nil)", 1);
			return (*written_count);
		}
		num_str = ft_itoa_base((unsigned long)ptr, BASE_HEX_MIN);
		*written_count += ft_putstr_fd("0x", 1);
	}
	else if (format == 'x')
		num_str = ft_itoa_base(va_arg(list, unsigned int), BASE_HEX_MIN);
	else if (format == 'X')
		num_str = ft_itoa_base(va_arg(list, unsigned int), BASE_HEX_MAX);
	*written_count += ft_putstr_fd(num_str, 1);
	free(num_str);
	return (*written_count);
}

static int	print_arg(va_list list, const char *format, int *written_count)
{
	char	*num_str;
	char	*arg_str;

	if (format[0] == 'c')
		*written_count += ft_putchar_fd(va_arg(list, unsigned int), 1);
	else if (format[0] == 's')
	{
		arg_str = va_arg(list, char *);
		if (!arg_str)
			return (*written_count += ft_putstr_fd("(null)", 1));
		*written_count += ft_putstr_fd(arg_str, 1);
	}
	else if (format[0] == 'i' || format[0] == 'd')
		ft_putnbr_fd(va_arg(list, int), 1, written_count);
	else if (format[0] == 'u')
	{
		num_str = ft_itoa_base(va_arg(list, unsigned int), BASE_DEC);
		*written_count += ft_putstr_fd(num_str, 1);
		free(num_str);
	}
	else if (format[0] == 'p' || format[0] == 'x' || format[0] == 'X')
		format_base(list, format[0], written_count);
	else if (format[0] == '%')
		*written_count += ft_putchar_fd('%', 1);
	return (*written_count);
}

int	ft_printf(const char *format, ...)
{
	int				idx;
	int				written_count;
	va_list			list;

	idx = 0;
	written_count = 0;
	va_start(list, format);
	while (format[idx] != '\0')
	{
		if (format[idx] == '%')
		{
			print_arg(list, &format[++idx], &written_count);
			idx++;
		}
		else
		{
			written_count += ft_putchar_fd(format[idx], 1);
			idx++;
		}
	}
	va_end(list);
	return (written_count);
}
