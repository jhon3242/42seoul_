#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
#include <limits.h> 
#include <stdio.h>
#include "../libft/libft.h"

// typedef struct	s_info
// {
// 	// bool	s_minus;
// 	// bool	s_zero;
// 	int		s_base;
// 	char	s_format;
// }				t_info;


int ft_printf(const char *str, ...);
int ft_unsigned_int(unsigned int n);
int	print_persent(void);
int print_str(char *str);
int print_char(int n);
int print_nub(int n);
int print_hex(long long num, char fmt);
int	print_pointer(unsigned long long n);

#endif
