#include <unistd.h>

void ft_print_numbers(void)
{
	char str[] = "0123456789";
	write(1,str,10);	
}
