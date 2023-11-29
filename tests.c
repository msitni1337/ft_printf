#include "includes/ft_printf.h"

int print_usage(char*name)
{
	printf("Bad arguments. usage:\n");
	printf("%s [ [i,c,s,n,0] [format] [value] ]...\n", name);
	printf("i: to pass a number.\n");
	printf("s: to pass a string.\n");
	printf("n: to pass NULL.\n");
	printf("0: to pass just the format.\n");
	return 1;
}

int main(int c, char**v)
{
	if (!(c - 1) || (c - 1) % 3 != 0)
		return (print_usage(v[0]));

	for (int i = 0; i < (c - 1) / 3; i++)
	{
		switch (v[(i * 3) + 1][0])
		{
			case 'i':
					printf("\nGot %d writes.\n", printf(v[(i * 3) + 2], atoi(v[(i * 3) + 3])));
				break;
			case 'c':
					printf("\nGot %d writes.\n", printf(v[(i * 3) + 2], v[(i * 3) + 3][0]));
				break;
			case 's':
					printf("\nGot %d writes.\n", printf(v[(i * 3) + 2], v[(i * 3) + 3]));
				break;
			case 'n':
					printf("\nGot %d writes.\n", printf(v[(i * 3) + 2], NULL));
				break;
			case '0':
					printf("\nGot %d writes.\n", printf(v[(i * 3) + 2]));
				break;
			default:
					return (print_usage(v[0]));
				break;
		}
	}
}
