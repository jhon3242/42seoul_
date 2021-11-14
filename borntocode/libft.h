#ifndef LIBFT_H
#define LIBFT_H
#include <stdlib.h>
#include <string.h>

extern int ft_isalpha(int c);
extern int ft_isdigit(int c);
extern int ft_isalnum(int c);
extern int    ft_isascii(int c);
extern int ft_isprint(int c);
extern int ft_strlen(const char *str);
extern void	ft_bzero(void *s, size_t n);
extern char	*ft_strdup(const char *s1);
extern size_t	ft_strlcpy(char *dest, const char *src, size_t size);
extern size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);
extern char	*ft_strtrim(char const *s1, char const *set);
extern char	**ft_split(char const *s, char c);


#endif
