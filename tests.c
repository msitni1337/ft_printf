#include "includes/ft_printf.h"

int main(int c, char**v)
{
	char* format = v[1];
	int		nb		 = atoi(v[2]);
	
	printf(v[1], nb, v[3]);
}
