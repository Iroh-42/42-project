#include <stdio.h>
#include "ft_printf.h"

int main (int ac, char **av)
{

	int count_char1;
	int count_char2;

	count_char1 = 0;
	count_char2 = 0;
	if (ac > 1)
	{
		char *ptr = NULL;
		ft_printf("debut ft_printf\n");
		count_char1 = ft_printf("c = %c\n", 'a');
		ft_printf("s = %k \n", av[1]);
		ft_printf("s null = %s\n", ptr);
		ft_printf("p = %p\n", av[1]);
		ft_printf("p null = %p\n", ptr);
		ft_printf("d = %d\n", 11);
		ft_printf("i = %i\n", atoi(av[1]));
		ft_printf("u = %u\n", atoi(av[1]));
		ft_printf("x = %x\n", atoi(av[1]));
		ft_printf("X = %X\n", atoi(av[1]));
		ft_printf("end %%\n ************* \ndebut printf\n");

		count_char2 = printf("c = %c\n", 'a');
		printf("s = %k\n", av[1]);
		printf("s null = %s\n", ptr);
		printf("p = %p\n", av[1]);
		printf("p null = %p\n", ptr);
		printf("d = %d\n", atoi(av[1]));
		printf("i = %i\n", atoi(av[1]));
		printf("u = %u\n", atoi(av[1]));
		printf("x = %x\n", atoi(av[1]));
		printf("X = %X\n", atoi(av[1]));
		ft_printf("end %%\n************* \n");
		printf("ftp = %d\nvpt = %d\n", count_char1, count_char2);
	}
	return (0);
}
/*
/a.out 21474836472568            
c = a
s = (null)
p = (nil)
d = -7432
i = -7432
u = 4294959864
x = ffffe2f8
X = FFFFE2F8
%

./a.out 21474836472568452
c = a
s = (null)
p = (nil)
d = -7431548
i = -7431548
u = 4287535748
x = ff8e9a84
X = FF8E9A84
%

./a.out 99999999999999999999999   
c = a
s = (null)
p = (nil)
d = -1
i = -1
u = 4294967295
x = ffffffff
X = E4B59E55
%

./a.out absolument       
c = a
s = (null)
p = (nil)
d = 0
i = 0
u = 0
x = 0
X = 0
%

./a.out 12345absolument
c = a
s = (null)
p = (nil)
d = 12345
i = 12345
u = 12345
x = 3039
X = 3039
%

./a.out 99999999ghuti9999999999999dgdrjkgbjbd
c = a
s = 99999999ghuti9999999999999dgdrjkgbjbd
p = 0x7ffe8fc4be47
d = 99999999
i = 99999999
u = 99999999
x = 5f5e0ff
X = 5F5E0FF
%

*/
