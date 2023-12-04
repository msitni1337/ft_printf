#include "ft_printf.h"

#define CUSTOM_TEST

int print_usage(char*name)
{
	printf("Bad arguments.\n");
	printf("\nusage: %s [ [i,c,s,n,0] [format] [value] ]...\n", name);
	printf("i: to pass an int.\n");
	printf("s: to pass a pointer to string.\n");
	printf("n: to pass NULL.\n");
	printf("0: to pass just the format.\n");
	return 1;
}

void test_with_no_args(char*func_name, char*fmt ,int (*f)(const char*,...))
{
	printf("\n%s returns %d writes.\n", func_name, f(fmt)); 
}

#ifdef CUSTOM_TEST
void custom_test()
{
	printf("\nlibc returns %d writes.\n", printf(PUT HERE YOUR TEST));
	printf("\nyours returns %d writes.\n", ft_printf(PUT HERE YOUR TEST));
	exit(0);
}
#endif

int main(int c, char**v)
{
#ifdef CUSTOM_TEST
	custom_test();
#endif
	if (!(c - 1) || (c - 1) % 3 != 0)
		return (print_usage(v[0]));
	for (int i = 0; i < (c - 1) / 3; i++)
	{
		switch (v[(i * 3) + 1][0])
		{
			case 'i':
					printf("\nlibc returns %d writes.\n", printf(v[(i * 3) + 2], atoi(v[(i * 3) + 3])));
					printf("\nyours returns %d writes.\n", ft_printf(v[(i * 3) + 2], atoi(v[(i * 3) + 3])));
				break;
			case 'c':
					printf("\nlibc returns %d writes.\n", printf(v[(i * 3) + 2], v[(i * 3) + 3][0]));
					printf("\nyours returns %d writes.\n", ft_printf(v[(i * 3) + 2], v[(i * 3) + 3][0]));
				break;
			case 's':
					printf("\nlibc returns %d writes.\n", printf(v[(i * 3) + 2], v[(i * 3) + 3]));
					printf("\nyours returns %d writes.\n", ft_printf(v[(i * 3) + 2], v[(i * 3) + 3]));
				break;
			case 'n':
					printf("\nlibc returns %d writes.\n", printf(v[(i * 3) + 2], NULL));
					printf("\nyours returns %d writes.\n", ft_printf(v[(i * 3) + 2], NULL));
				break;
			case '0':
					
					test_with_no_args("libc", v[(i * 3) + 2], &printf);
					test_with_no_args("yours", v[(i * 3) + 2], &ft_printf);
				break;
			default:
					return (print_usage(v[0]));
				break;
		}
	}
}
