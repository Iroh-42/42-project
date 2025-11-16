/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:55:47 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/14 14:52:25 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	int_len(unsigned long nb, size_t len_base)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / len_base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long nbr, const char *base)
{
	size_t			digits_count;
	size_t			len_base;
	char			*str_nb;

	if (!base)
		return (NULL);
	len_base = ft_strlen(base);
	digits_count = int_len(nbr, len_base);
	str_nb = ft_calloc(digits_count + 1, sizeof(char));
	if (!str_nb)
		return (NULL);
	if (nbr == 0)
		str_nb[0] = '0';
	str_nb[digits_count] = '\0';
	while (nbr > 0)
	{
		digits_count--;
		str_nb[digits_count] = base[nbr % len_base];
		nbr = nbr / len_base;
	}
	return (str_nb);
}
