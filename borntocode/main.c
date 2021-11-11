#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ft.h"

int main(void)
{
	char test[] = "BlockDMask1234";
	for (int i =0 ; i < (int)strlen(test); i++)
	{
		printf("%d ", ft_isalnum(test[i]));
		printf("%d\n", isdigit(test[i]));


	}

	return (0);
}
