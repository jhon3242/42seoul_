int ft_isalpha(int c)
{
	if ('a' <= c && c <= 'z')
		return (c);
	if ('A' <= c && c <= 'Z')
		return (c);
	return (0);
}
