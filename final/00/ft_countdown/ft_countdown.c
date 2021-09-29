#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

int main()
{
	int a;

	a = 10;
	while (--a > 0)
		ft_putnbr(a);
}
