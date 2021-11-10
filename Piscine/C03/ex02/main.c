#include <string.h>



char    *ft_strcat(char *dest, char *src)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dest[i])
        i++;
    while (src[j])
    {
        dest[i+j] = src[j];
        j++;
    }
    dest[i+j] = 0;
    return (dest);
}


int main()
{
    char s1[100] = "this is test";
    char s2[] = "thas";
    char *p;
    
    ft_strcat(s1, s2);
    strcat(s1, s2);
    
    return 0;
}

