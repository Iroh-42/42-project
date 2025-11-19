#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int f1 = open("test1.txt", O_RDONLY);
    int f2 = open("test2.txt", O_RDONLY);
    int fl = open("test_long.txt", O_RDONLY);
    char *s;

    if (f1 < 0 || f2 < 0 || fl < 0)
    {
        perror("open");
        return (1);
    }

    printf("=== interleaved read ===\n");
    s = get_next_line(f1); printf("f1: %s", s); free(s);
    s = get_next_line(f2); printf("f2: %s", s); free(s);
    s = get_next_line(f1); printf("f1: %s", s); free(s);
    s = get_next_line(f2); printf("f2: %s", s); free(s);
    s = get_next_line(f1); printf("f1: %s", s); free(s);
    s = get_next_line(f2); printf("f2: %s", s); free(s);

    printf("\n=== long line read ===\n");
    while ((s = get_next_line(fl)) != NULL)
    {
        printf("long: %s", s);
        free(s);
    }

    close(f1); close(f2); close(fl);
    return (0);
}
