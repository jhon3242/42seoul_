#include <unistd.h>

void	ft_print_comb(void)
{
	char 	arr[3];
	
	arr[0] = '0';
	while (arr[0] <= '7')
	{
		arr[1] = arr[0] + 1;
		while (arr[1] <= '8')
		{
			arr[2] = arr[1] + 1;
			while (arr[2] <= '9')
			{
				write(1,arr,3);
				if (arr[0] == '7' && arr[1] =='8' && arr[2] =='9' )
					return;
				write(1,", ",2);
				arr[2] ++;
			}
			arr[1] ++;
		}
		arr[0]++;
	}	
}
