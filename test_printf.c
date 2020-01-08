#include <stdio.h>

void	test_pf_c(int	(*pf)(char *str, ...))
{
	pf(":%c:\n", NULL);
	pf(":%.10c:\n", 'a');
	pf(":%+10.c:\n", 'a');
}

int	main(void)
{
	int i = 2;

	i |= 1;
	i |= 3;
	i &= 2;
	printf(":%d:\n", i);
//	test_pf_c(printf);
	return (0);
}
