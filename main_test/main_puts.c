#include <stdio.h>

int     ft_puts(const char *s);

int		main(void)
{
	char *str;
	char *str1;
	int ret = 0; 
	str = "zinedinecoucoucaca";
	str1 = 0;
/*
	printf("str = %s\n", str);
	printf("puts = ");
	ret = puts(str);
	printf("ret puts(str) = %d\n", ret);
	printf("ft_puts = ");
	ret = ft_puts(str);
	printf("ret ft_puts(str) = %d\n", ret);
	printf("\n\ntestNULL\n\n");
	puts(str1);
	ft_puts(str1);
	ret = puts(str);
	printf("ret puts(str) = %d\n", ret);
*/
	ret = puts("aaaa\n(null)\n");
	printf("ret puts(aaaa\n(null)\n) = %d\n", ret);
	ret = ft_puts("aaaa\n(null)\n");
	printf("ret puts(aaaa\n(null)\n) = %d\n", ret);
	return (0);
}
