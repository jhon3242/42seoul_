
#include "../includes/ft_printf.h"
#include <stdio.h>

int main()
{
    int t;
    long long j;
    char s[] ="this is string";
    char c = 'T';
    unsigned int u = 4294967295;

    t=2147483647;
    j= -2147483648 ;
    ft_printf("%d\n%s\n%c\n%u\n%x\n%X\n%p\n", t, s, c, u, t, -t,&u);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("%d\n%s\n%c\n%u\n%x\n%X\n%p\n", t, s, c, u, t, -t, &u);
}