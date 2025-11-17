/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:55:47 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/13 10:26:14 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(long int nb)
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
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	size_t		size_int;
	char		*str_nb;

	nbr = n;
	size_int = int_len(nbr);
	str_nb = ft_calloc(size_int + 1, sizeof(char));
	if (!str_nb)
		return (NULL);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		str_nb[0] = '-';
	}
	if (nbr == 0)
		str_nb[0] = '0';
	str_nb[size_int] = '\0';
	while (nbr > 0)
	{
		size_int--;
		str_nb[size_int] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str_nb);
}
