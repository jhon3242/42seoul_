#include <unistd.h>

extern int ft_atoi(char *str);
extern int ft_sum(int n1, int n2);
extern int ft_min(int n1, int n2);
extern int ft_mul(int n1, int n2);
extern int ft_div(int n1, int n2);
extern int ft_mod(int n1, int n2);

extern void ft_putnbr(int n);

void	ft_ret(int nb1, int(*f)(int, int), int nb2)
{
	f(nb1, nb2);
}

int main(int argc, char **argv)
{
	int	nb1;
	int	nb2;

	if (argc != 4)
		return (0);
	nb1 = ft_atoi(argv[1]);
	nb2 = ft_atoi(argv[3]);
	if (argv[2][0] == '+')
		ft_ret(nb1, &ft_sum, nb2);
	else if (argv[2][0] == '-')
		ft_ret(nb1, &ft_min, nb2);
	else if (argv[2][0] == '*')
		ft_ret(nb1, &ft_mul, nb2);
	else if (argv[2][0] == '/')
		ft_ret(nb1, &ft_div, nb2);
	else if (argv[2][0] == '%')
		ft_ret(nb1, &ft_mod, nb2);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
