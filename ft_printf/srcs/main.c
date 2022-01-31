
#include "../includes/ft_printf.h"
int main()
{
    int t;
    int j;
    char s[] ="this is string";
    char c = 'T';
    unsigned int u = 4294967295;
    
    t=2147483647;
    j=-2147483648;
    
    ft_printf("%d\n%i\n%s\n%c\n%u\n%%\n%x\n%X", t, j, s, c, u, t, j);
}