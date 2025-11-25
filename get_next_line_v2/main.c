/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:06:04 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/20 16:30:19 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
# include <unistd.h>
# include <stdio.h>

int main (void)
{
    int fd;
    char    *str;
    str = "";
    int     i;
    i = 0;

    fd = open("fichier.txt", O_RDONLY);
    while (i++ < 9)
    {
        str = get_next_line(fd);
        printf("%s", str);
        free(str);
    }
    close(fd);
}