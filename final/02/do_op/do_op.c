#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_op(char *s1, char *op, char *s2)
{
	int n1;
	int n2;

	n1 = atoi(s1);
	n2 = atoi(s2);
	if (*op == '+')
		printf("%d",n1 + n2);
	else if (*op == '-')
		printf("%d", n1 - n2);
	else if (*op == '*')
		printf("%d", n1 * n2);
	else if (*op == '/')
		printf("%d", n1 / n2);
	else if (*op == '%')
		printf("%d", n1 % n2);
}

int main(int ac, char **av)
{
	if (ac == 4)
		ft_op(av[1], av[2], av[3]);
	write(1, "\n", 1);
}
