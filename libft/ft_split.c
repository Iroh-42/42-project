/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:25:18 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/13 13:26:02 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	nb_word;
	int	is_word;

	i = 0;
	nb_word = 0;
	is_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			is_word = 0;
			if (s[i] == '\0')
				return (nb_word);
		}
		if (is_word == 0 && s[i] != c)
		{
			nb_word++;
			is_word = 1;
		}
		i++;
	}
	return (nb_word);
}

static size_t	ft_strlen_split(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_free_all(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

static char	**create_array_split(unsigned int nb_word,
	char **str_split, char c, const char *s)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < nb_word)
	{
		if (s[start] == c)
			start++;
		else
		{
			end = ft_strlen_split(&s[start], c);
			str_split[i] = ft_substr(s, start, end);
			if (!str_split[i])
			{
				ft_free_all(str_split, i);
				return (NULL);
			}
			i++;
			start = start + end;
		}
	}
	return (str_split);
}

char	**ft_split(char const *s, char c)
{
	unsigned int		nb_word;
	char				**str_split;

	if (!s)
		return (str_split = NULL);
	nb_word = count_word(s, c);
	str_split = ft_calloc((nb_word + 1), sizeof(str_split));
	if (!str_split)
		return (NULL);
	str_split = create_array_split(nb_word, str_split, c, s);
	if (!str_split)
		return (NULL);
	str_split[nb_word] = 0;
	return (str_split);
}
