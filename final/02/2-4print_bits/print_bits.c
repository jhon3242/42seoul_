#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_bits(unsigned char octet)
{
	char re[] = "00000000";
	int	size;

	size = 8;
	while (--size > 0)
	{
		re[size] = octet % 2 + '0';
		octet /= 2;
	}
	ft_putstr(re);
}

int main()
{
	print_bits(8);
}
