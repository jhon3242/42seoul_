unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned	int	i;

	i = 0;
	while (*dest && i < size)
	{
		dest++;
		i++;
	}
	while (*src && i + 1 < size)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	if (i < size) /* 만약 그냥 조건을 안주면 size 가 0일 떄 *dest 가 널이 됨*/
		*dest = 0;
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}
		

~
