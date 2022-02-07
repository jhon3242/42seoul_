#include <stdio.h>
#include "includes/ft_printf.h"

int main() {
    char a = 'A';
    int b = 2;
    float c = 4.0;
    double d = 5.0;
    char *e = "hello";
    printf("No Argument\n");
    printf("%c\n", a);
    printf("%c, %d\n", a, b);
    printf("%c, %d, %f\n", a, b, c);
    printf("%c, %d, %f, %lf\n", a, b, c, d);
    printf("%c, %d, %f, %lf, %s\n", a, b, c, d, e);
    ft_printf("No Argument\n");
    ft_printf("%c\n", a);
    ft_printf("%c, %d\n", a, b);
    ft_printf("%c, %d, %f\n", a, b, c);
    ft_printf("%c, %d, %f, %lf\n", a, b, c, d);
    ft_printf("%c, %d, %f, %lf, %s\n", a, b, c, d, e);
    return 0;
}