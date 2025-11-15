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

static size_t	int_len(long int nb, size_t len_base)
{
	size_t		i;

	i = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / len_base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long nbr, char *base)
{
	size_t			size_int;
	size_t			len_base;
	char			*str_nb;

	if (!base)
		return (NULL);
	len_base = ft_strlen(base);
	size_int = int_len(nbr, len_base);
	str_nb = ft_calloc(size_int + 1, sizeof(char));
	if (!str_nb)
		return (NULL);
	if (nbr == 0)
		str_nb[0] = '0';
	str_nb[size_int] = '\0';
	while (nbr > 0)
	{
		size_int--;
		str_nb[size_int] = base[nbr % len_base];
		nbr = nbr / len_base;
	}
	return (str_nb);
}
