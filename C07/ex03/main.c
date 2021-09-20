#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ret_strlen(int size, char **strs)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (i < size)
	{
		ret += ft_strlen(strs[i]);
		i++;
	}
	ret += size;
	return (ret - 1);
}

void	ft_strcpy(char *dec, char *src)
{
	while (*src)
	{
		*dec = *src;
		dec++;
		src++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{	
	char	*ret;
	char	*tmp;
	int		strlen;
	int		i;

	strlen = ret_strlen(size, strs);
	ret = (char *)malloc(sizeof(char) * (strlen + 1));
	tmp = ret;
	i = 0;
	while (i < size)
	{
		while (*strs[i])
		{
			*tmp = *strs[i];
			tmp++;
			strs[i]++;
		}
		*tmp = *sep;
		tmp++;
		i++;
	}
	*(--tmp) = 0; 
	return (ret);
}

int main()
{
    char *p[2];
    char *t;
    p[0] = "test";
    p[1] = "is";
    t = ft_strjoin(2, p, "@");
    printf("%s\n",t);
    return (0);
}
    
