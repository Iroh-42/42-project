/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:06:04 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/25 14:41:53 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
# include <unistd.h>
# include <stdio.h>

int main (void)
{
    int fd[5];
    char    *str;
    str = "";
    int     i;
    int j;
    j = 0;
    i = 0;

    fd[0] = open("41_with_nl", O_RDONLY);
    fd[1] = open("42_with_nl", O_RDONLY);
    fd[2] = open("43_with_nl", O_RDONLY);
    fd[3] = open("nl", O_RDONLY);
    while (j < 4)
    {
        str = get_next_line(fd[i]);
        printf("\nlecture  fd =%d\n %s", i, str);
        free(str);
        ++i;
        if (i == 4)
        {
            i = 0;
            ++j;
        }
    }
    j = 0;
    while (fd[j])
    {
        close(fd[j]);
        j++;
    }
}