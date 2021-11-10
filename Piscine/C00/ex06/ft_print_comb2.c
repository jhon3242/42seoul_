#include <unistd.h>

void	ft_print_nb(int nb)
{
	char 	a;

	a = nb / 10 + '0';
	write(1,&a,1);
	a = nb % 10 + '0';
	write(1,&a,1);
}


void	ft_print_comb2(void)
{
	int 	a;
	int 	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			if (a<b)
			{
				ft_print_nb(a);
				write(1," ",1);
				ft_print_nb(b);
				if (a == 98 && b == 99)
					return;
				write(1,", ",2);
			}
			b++;
		}
		a++;
	}
	
}
