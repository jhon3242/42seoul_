int ft_isalpha(int c)
{
    if ('a' <= c && c <= 'z')
        return (2);
    if ('A' <= c && c <= 'Z')
        return (1);
    return (0);
}
