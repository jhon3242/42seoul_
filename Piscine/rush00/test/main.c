#include <unistd.h>

void    ft_putchar(const char c)
{
    write(1, &c, 1);
}


void    drawing(int i_x, int i_y, int x, int y)
{
    if (i_x == 0 && i_y == 0)
        ft_putchar('A');
    else if (i_x == x-1 && i_y == y-1 && y != 1 && x != 1)
        ft_putchar('A');
    else if (i_x == x-1 && i_y == 0)
        ft_putchar('C');
    else if (i_x == 0 && i_y == y-1)
        ft_putchar('C');
    else
        ft_putchar('B');
}

void    moving(int x, int y)
{
    int    i_x;
    int    i_y;

    i_x = 0;
    i_y = 0;
    while (i_y < y)
    {
        while (i_x < x)
        {
            drawing(i_x, i_y, x, y);
            i_x++;
        }
        i_x = 0;
        ft_putchar('\n');
        i_y++;
    }
}

void    rush(int x, int y)
{
    moving(x, y);
}

        
int    main()
{
    rush(4, 4);
    return (0);
}
