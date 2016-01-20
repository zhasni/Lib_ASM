
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>

extern int 		ft_isdigit(int nb);
extern int 		ft_isalpha(int nb);
extern int 		ft_isprint(int nb);
extern int 		ft_isascii(int nb);
extern int 		ft_isalnum(int nb);
extern void 	ft_bzero(void *str, int nb);
extern size_t	ft_strlen(const char *str);
extern char 	*ft_strcat(char *s1, const char *s2);
extern int 		ft_toupper(int c);
extern int 		ft_tolower(int c);
extern int 		ft_isupper(int c);
extern int 		ft_islower(int c);
extern int 		ft_isblank(int c);
extern int 		ft_iscntrl(int c);
extern int 		ft_isgraph(int c);
extern int 		ft_isspace(int c);
extern int 		ft_isxdigit(int c);
extern int 		ft_ispunct(int c);
extern void 	ft_puts(const char *str);
extern void 	ft_putstr(const char *str);
extern void 	ft_putchar(char c);
extern void 	*ft_memset(void *b, int c, size_t len);
extern void 	*ft_memcpy(void *dst, const void *src, size_t len);
extern char 	*ft_strdup(const char *str);
extern int 		ft_cat(int i);
extern void		ft_putstr_fd(char const *s, int fd);
extern void		ft_putchar_fd(char c, int fd);
extern void		ft_putendl(const char *s);
extern void		ft_putendl_fd(const char *s, int fd);
extern void 	*malloc(size_t size);

#define RED  	"\033[31m"
#define GREEN  	"\033[32m"
#define BLUE  	"\033[34m"
#define YELLOW  "\033[33m"
#define STOP 	"\033[0m"

int			ft_error_bzero(int ret, char *str1, char *str2, int test){
	if (ret == 0)
		printf(RED" KO\n"STOP);
	printf("\t• test %d\n\t  expected = <%s>\n\t  returned = <%s>\n", test, str1, str2);
	return (1);
}

int 		ft_check_s1_s2(char *str1, char *str2, int n){
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while(i < n){
		if (str1[i++] != 0){
			if (str1[i] != str2[i])
				return 1;
		}
	}
	while(j < n){
		if (str2[j++] != 0){
			if (str1[j] != str2[j])
				return 1;
		}
	}
	if (i != j)
		return 1;
	return 0;
}

void		ft_test_bzero(int null){
	// FT_BZERO
	int 	ret;
	char 	*str1;
	char 	*str2;
	char 	*bkp1;
	char 	*bkp2;
	char 	c1;
	char 	c2;

	c1 = 'c';
	c2 = 'c';
	ret = 0;
	str1 = NULL;
	str2 = NULL;
	bkp1 = NULL;
	bkp2 = NULL;
	printf(BLUE"ft_bzero   = "STOP);
	str1 = strdup("hello");
	str2 = strdup("hello");
	ft_bzero(str1, 0);
	bzero(str2, 0);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, strlen(str1)))
		ret = ft_error_bzero(ret, str1, str2, 0);
	str1 = strdup("hello");
	str2 = strdup("hello");
	ft_bzero(str1, 1);
	bzero(str2, 1);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, strlen(str1)))
		ret = ft_error_bzero(ret, str1, str2, 1);
	str1 = strdup("hello");
	str2 = strdup("hello");
	bkp1 = str1;
	bkp2 = str2;
	ft_bzero(str1, 1);
	bzero(str2, 1);
	str1++;
	str2++;
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, strlen(str1)))
		ret = ft_error_bzero(ret, str1, str2, 2);
	str1 = strdup("hello");
	str2 = strdup("hello");
	ft_bzero(str1, 10);
	bzero(str2, 10);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, 10))
		ret = ft_error_bzero(ret, str1, str2, 3);
	str1 = strdup("hello");
	str2 = strdup("hello");
	ft_bzero(str1, 100);
	bzero(str2, 100);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, 100))
		ret = ft_error_bzero(ret, str1, str2, 4);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	ft_bzero(str1, 0);
	bzero(str2, 0);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, strlen(str1)))
		ret = ft_error_bzero(ret, str1, str2, 5);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	ft_bzero(str1, 1);
	bzero(str2, 1);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, strlen(str1)))
		ret = ft_error_bzero(ret, str1, str2, 6);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	bkp1 = str1;
	bkp2 = str2;
	ft_bzero(str1, 1);
	bzero(str2, 1);
	str1++;
	str2++;
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, strlen(str1)))
		ret = ft_error_bzero(ret, str1, str2, 7);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	ft_bzero(str1, 10);
	bzero(str2, 10);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, 10))
		ret = ft_error_bzero(ret, str1, str2, 8);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	ft_bzero(str1, 100);
	bzero(str2, 100);
	if (strcmp(str1, str2) || ft_check_s1_s2(str1, str2, 100))
		ret = ft_error_bzero(ret, str1, str2, 9);
	c1 = 'c';
	c2 = 'c';
	ft_bzero(&c1, 1);
	bzero(&c2, 1);
	if (ft_check_s1_s2(&c1, &c2, 1))
		ret = ft_error_bzero(ret, &c1, &c2, 10);
	c1 = 'c';
	c2 = 'c';
	ft_bzero(&c1, 10);
	bzero(&c2, 10);
	if (ft_check_s1_s2(&c1, &c2, 10))
		ret = ft_error_bzero(ret, &c1, &c2, 11);
	if (!ret)
		printf(GREEN"OK\n"STOP);
	//NULL TEST
	if (null){
		char *test = NULL;
		ft_bzero(test, 1);
		printf("NULL TEST = <%s>\n", test);
	}
}

int 		ft_error_strcat(int ret, char *str1, char *str2, int test){
	if (ret == 0)
		printf(RED" KO\n"STOP);
	printf("\t• test %d\n\t  expected = <%s>\n\t  returned = <%s>\n", test, str1, str2);
	return (1);
}

void		ft_test_strcat(int null){

	//STRANGE ONE START
	int 	ret;

	ret = 0;

	char        abc[10] = "";
  	char        abc2[10] = "abcd";

  	ft_bzero(abc, 10);
  	abc2[4] = '\0';

  	char        *t1;
  	char        *t2;

	char        abcde1[10] = "";
  	char        abcde2[10] = "abcd";

  	ft_bzero(abcde1, 10);
  	abcde2[4] = '\0';

 	t1 = strcat(abc, abc2);
 	t2 = ft_strcat(abcde1, abcde2);
	if (strcmp(t1, t2))
		ret = ft_error_strcat(ret, t1, t2, 0);

	if (strcmp(abc, abcde1))
		ret = ft_error_strcat(ret, abc, abcde1, 1);
	//STRANGE ONE STOP

	char 	*bkp1;
	char 	*bkp2;
	char 	*str1;
	char 	*str2;
	char 	*stra;
	char 	*strb;

	ret = 0;
	bkp1 = NULL;
	bkp2 = NULL;
	str1 = NULL;
	str2 = NULL;
	stra = NULL;
	strb = NULL;
	// FT_STRCAT
	printf(BLUE"ft_strcat  = "STOP);
	str1 = strdup("Hello");
	str2 = strdup("world");
	stra = strdup("Hello");
	strb = strdup("world");
	bkp1 = strcat(str1, str2);
	bkp2 = ft_strcat(stra, strb);
	if (strcmp(bkp1, bkp2))
		ret = ft_error_strcat(ret, bkp1, bkp2, 2);

	if (strcmp(str1, stra))
		ret = ft_error_strcat(ret, str1, stra, 3);
	str1 = strdup("a");
	str2 = strdup("world");
	stra = strdup("a");
	strb = strdup("world");
	bkp1 = strcat(str1, str2);
	bkp2 = ft_strcat(stra, strb);
	if (strcmp(bkp1, bkp2))
		ret = ft_error_strcat(ret, bkp1, bkp2, 4);

	if (strcmp(str1, stra))
		ret = ft_error_strcat(ret, str1, stra, 5);
	str1 = strdup("Hello");
	str2 = strdup("");
	stra = strdup("Hello");
	strb = strdup("");
	bkp1 = strcat(str1, str2);
	bkp2 = ft_strcat(stra, strb);
	if (strcmp(bkp1, bkp2))
		ret = ft_error_strcat(ret, bkp1, bkp2, 6);

	if (strcmp(str1, stra))
		ret = ft_error_strcat(ret, str1, stra, 7);
	str1 = strdup("");
	str2 = strdup("world");
	stra = strdup("");
	strb = strdup("world");
	bkp1 = strcat(str1, str2);
	bkp2 = ft_strcat(stra, strb);
	if (strcmp(bkp1, bkp2))
		ret = ft_error_strcat(ret, bkp1, bkp2, 8);
	if (strcmp(str1, stra))
		ret = ft_error_strcat(ret, str1, stra, 9);
	str1 = strdup("a");
	str2 = strdup("b");
	stra = strdup("a");
	strb = strdup("b");
	bkp1 = strcat(str1, str2);
	bkp2 = ft_strcat(stra, strb);
	if (strcmp(bkp1, bkp2))
		ret = ft_error_strcat(ret, bkp1, bkp2, 10);
	if (strcmp(str1, stra))
		ret = ft_error_strcat(ret, str1, stra, 11);
	str1 = strdup("");
	str2 = strdup("");
	stra = strdup("");
	strb = strdup("");
	bkp1 = strcat(str1, str2);
	bkp2 = ft_strcat(stra, strb);
	if (strcmp(bkp1, bkp2))
		ret = ft_error_strcat(ret, bkp1, bkp2, 12);
	if (strcmp(str1, stra))
		ret = ft_error_strcat(ret, str1, stra, 13);
	if (!ret)
		printf(GREEN"OK\n"STOP);
	//NULL TEST
	if (null){
		char *test = ft_strcat(NULL, NULL);
		printf("NULL TEST = <%s>\n", test);
	}
}

int			ft_error_ptr(int c, int ret, int (*my_ptr)(int), int (*libc_ptr)(int), int test){
	if (ret == 0)
		printf(RED" KO\n"STOP);
	printf("\t• test %d\n\t  char = <%c> ascii = <%d>\n\t  expected = <%d>\n\t  returned = <%d>\n", test, c, c, libc_ptr(c), my_ptr(c));
	return (1);
}

void		ft_test_isalpha(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	ret = 0;
	c = 'a';
	my_ptr = ft_isalpha;
	libc_ptr = isalpha;
	// FT_ISAPLHA
	printf(BLUE"ft_isalpha = "STOP);
	while (c++ <= 'z'){
		if (ft_isalpha(c) != isalpha(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 0); 
	}
	if (ft_isalpha(65) != isalpha(65))
		ret = ft_error_ptr(65, ret, my_ptr, libc_ptr, 1); 
	if (ft_isalpha('a') != isalpha('a'))
		ret = ft_error_ptr('a', ret, my_ptr, libc_ptr, 2); 
	if (ft_isalpha(97) != isalpha(97))
		ret = ft_error_ptr(97, ret, my_ptr, libc_ptr, 3); 
	if (ft_isalpha('z') != isalpha('z'))
		ret = ft_error_ptr('z', ret, my_ptr, libc_ptr, 4); 
	if (ft_isalpha(122) != isalpha(122))
		ret = ft_error_ptr(122, ret, my_ptr, libc_ptr, 5); 
	if (ft_isalpha('\0') != isalpha('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 6); 
	if (ft_isalpha(48) != isalpha(48))
		ret = ft_error_ptr(48, ret, my_ptr, libc_ptr, 7); 
	if (ft_isalpha('0') != isalpha('0'))
		ret = ft_error_ptr('0', ret, my_ptr, libc_ptr, 8); 
	if (ft_isalpha(57) != isalpha(57))
		ret = ft_error_ptr(57, ret, my_ptr, libc_ptr, 9); 
	if (ft_isalpha('9') != isalpha('9'))
		ret = ft_error_ptr('9', ret, my_ptr, libc_ptr, 10); 
	if (ft_isalpha(1) != isalpha(1))
		ret = ft_error_ptr(1, ret, my_ptr, libc_ptr, 11); 
	if (ft_isalpha(0) != isalpha(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 12); 
	if (ft_isalpha(42) != isalpha(42))
		ret = ft_error_ptr(42, ret, my_ptr, libc_ptr, 13); 
	if (ft_isalpha(2147483647) != isalpha(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 14); 
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_isdigit(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	ret = 0;
	c = '0';
	my_ptr = ft_isdigit;
	libc_ptr = isdigit;
	// FT_ISDIGIT
	printf(BLUE"ft_isdigit = "STOP); 
	while (c <= '9'){
		if (ft_isdigit(c) != isdigit(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_isdigit(48) != isdigit(48))
		ret = ft_error_ptr(48, ret, my_ptr, libc_ptr, 1);
	if (ft_isdigit('0') != isdigit('0'))
		ret = ft_error_ptr('0', ret, my_ptr, libc_ptr, 2);
	if (ft_isdigit(57) != isdigit(57))
		ret = ft_error_ptr(57, ret, my_ptr, libc_ptr, 3);
	if (ft_isdigit('9') != isdigit('9'))
		ret = ft_error_ptr('9', ret, my_ptr, libc_ptr, 4);
	if (ft_isdigit('\0') != isdigit('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 5);
	if (ft_isdigit('a') != isdigit('a'))
		ret = ft_error_ptr('a', ret, my_ptr, libc_ptr, 6);
	if (ft_isdigit(97) != isdigit(97))
		ret = ft_error_ptr(97, ret, my_ptr, libc_ptr, 7);
	if (ft_isdigit('z') != isdigit('z'))
		ret = ft_error_ptr('z', ret, my_ptr, libc_ptr, 8);
	if (ft_isdigit(122) != isdigit(122))
		ret = ft_error_ptr(122, ret, my_ptr, libc_ptr, 9);
	if (ft_isdigit(1) != isdigit(1))
		ret = ft_error_ptr(1, ret, my_ptr, libc_ptr, 10);
	if (ft_isdigit(0) != isdigit(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 11);
	if (ft_isdigit(127) != isdigit(127))
		ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 12);
	if (ft_isdigit(2147483647) != isdigit(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 13);
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_isalnum(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	ret = 0;
	my_ptr = ft_isalnum;
	libc_ptr = isalnum;
	// FT_ISALNUM
	printf(BLUE"ft_isalnum = "STOP); 
	if (ft_isalnum('a') != ft_isalnum('a'))
		ret = ft_error_ptr('a', ret, my_ptr, libc_ptr, 0);
	if (ft_isalnum(97) != ft_isalnum(97))
		ret = ft_error_ptr(97, ret, my_ptr, libc_ptr, 1);
	if (ft_isalnum('z') != ft_isalnum('z'))
		ret = ft_error_ptr('z', ret, my_ptr, libc_ptr, 2);
	if (ft_isalnum(122) != ft_isalnum(122))
		ret = ft_error_ptr(122, ret, my_ptr, libc_ptr, 3);
	if (ft_isalnum(48) != ft_isalnum(48))
		ret = ft_error_ptr(48, ret, my_ptr, libc_ptr, 4);
	if (ft_isalnum('0') != ft_isalnum('0'))
		ret = ft_error_ptr('0', ret, my_ptr, libc_ptr, 5);
	if (ft_isalnum(57) != ft_isalnum(57))
		ret = ft_error_ptr(57, ret, my_ptr, libc_ptr, 6);
	if (ft_isalnum('9') != ft_isalnum('9'))
		ret = ft_error_ptr('9', ret, my_ptr, libc_ptr, 7);
	c = '0';
	while (c++ <= '9'){
		if (ft_isalnum(c) != ft_isalnum(c))
			ret = ft_error_ptr('9', ret, my_ptr, libc_ptr, 8);
	}
	c = 'A';
	while (c++ <= 'Z'){
		if (ft_isalnum(c) != ft_isalnum(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 9);
	}
	c = 'a';
	while (c++ <= 'z'){
		if (ft_isalnum(c) != ft_isalnum(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 10);
	}
	if (ft_isalnum('\0') != isalnum('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 11);
	if (ft_isalnum(1) != isalnum(1))
		ret = ft_error_ptr(1, ret, my_ptr, libc_ptr, 12);
	if (ft_isalnum(40) != isalnum(40))
		ret = ft_error_ptr(40, ret, my_ptr, libc_ptr, 13);
	if (ft_isalnum(58) != isalnum(58))
		ret = ft_error_ptr(58, ret, my_ptr, libc_ptr, 14);
	if (ft_isalnum(92) != isalnum(92))
		ret = ft_error_ptr(92, ret, my_ptr, libc_ptr, 15);
	if (ft_isalnum(123) != isalnum(123))
		ret = ft_error_ptr(123, ret, my_ptr, libc_ptr, 16);
	if (ft_isalnum(0) != isalnum(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 17);
	if (ft_isalnum(127) != isalnum(127))
		ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 18);
	if (ft_isalnum(2147483647) != isalnum(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 19);
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_isascii(){	
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	my_ptr = ft_isascii;
	libc_ptr = isascii;
	c = 0;
	ret = 0;
	// FT_ISASCII
	printf(BLUE"ft_isascii = "STOP); 
	while (c <= 127){
		if (ft_isascii(c) != isascii(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_isascii(2147483647) != isascii(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 1);
	if (ft_isascii(-1) != isascii(-1))
		ret = ft_error_ptr(-1, ret, my_ptr, libc_ptr, 2);
	if (ft_isascii(128) != isascii(128))
		ret = ft_error_ptr(128, ret, my_ptr, libc_ptr, 3);
	if (ft_isascii(2147483648) != isascii(2147483648))
		ret = ft_error_ptr(2147483648, ret, my_ptr, libc_ptr, 4);
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_isprint(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	my_ptr = ft_isprint;
	libc_ptr = isprint;
	c = 32;
	ret = 0;
	// FT_ISPRINT
	printf(BLUE"ft_isprint = "STOP); 
	while (c <= 126){
		if (!ft_isprint(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_isprint(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 1);
	if (ft_isprint(27))
		ret = ft_error_ptr(27, ret, my_ptr, libc_ptr, 2);
	if (ft_isprint(31))
		ret = ft_error_ptr(31, ret, my_ptr, libc_ptr, 3);
	if (ft_isprint(4))
		ret = ft_error_ptr(4, ret, my_ptr, libc_ptr, 4);
	if (ft_isprint(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 5);
	if (ft_isprint(-1))
		ret = ft_error_ptr(-1, ret, my_ptr, libc_ptr, 6);
	if (ft_isprint(128))
		ret = ft_error_ptr(128, ret, my_ptr, libc_ptr, 7);
	if (ft_isprint(127))
		ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 8);
	if (ft_isprint(30))
		ret = ft_error_ptr(30, ret, my_ptr, libc_ptr, 9);
	if (ft_isprint(2147483648))
		ret = ft_error_ptr(2147483648, ret, my_ptr, libc_ptr, 10);
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_toupper(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	my_ptr = ft_toupper;
	libc_ptr = toupper;
	ret = 0;
	// FT_TOUPPER
	printf(BLUE"ft_toupper = "STOP); 
	c = 'a';
	while (c <= 'z'){
	if (ft_toupper(c) != toupper(c))
		ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_toupper('A') != toupper('A'))
		ret = ft_error_ptr('A', ret, my_ptr, libc_ptr, 1);
	if (ft_toupper(12) != toupper(12))
		ret = ft_error_ptr(12, ret, my_ptr, libc_ptr, 2);
	if (ft_toupper(0) != toupper(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 3);
	if (ft_toupper(-1) != toupper(-1))
		ret = ft_error_ptr(-1, ret, my_ptr, libc_ptr, 4);
	if (ft_toupper(4) != toupper(4))
		ret = ft_error_ptr(4, ret, my_ptr, libc_ptr, 5);
	if (ft_toupper(2147483648) != toupper(2147483648))
		ret = ft_error_ptr(2147483648, ret, my_ptr, libc_ptr, 6);
	if (ft_toupper(2147483647) != toupper(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 7);
	if (ft_toupper(-2147483648) != toupper(-2147483648))
		ret = ft_error_ptr(-2147483648, ret, my_ptr, libc_ptr, 8);
	if (ft_toupper('\0') != toupper('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 9);
	c = 'A';
	while (c <= 'Z'){
		if (ft_toupper(c) != toupper(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 10);
		c++;
	}
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_tolower(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	my_ptr = ft_tolower;
	libc_ptr = tolower;
	ret = 0;
	// FT_TOLOWER
	printf(BLUE"ft_tolower = "STOP); 
	c = 'a';
	while (c <= 'z'){
		if (ft_tolower(c) != tolower(c))
			ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_tolower('A') != tolower('A'))
		ret = ft_error_ptr('A', ret, my_ptr, libc_ptr, 1);
	if (ft_tolower(12) != tolower(12))
		ret = ft_error_ptr(12, ret, my_ptr, libc_ptr, 2);
	if (ft_tolower(0) != tolower(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 3);
	if (ft_tolower(-1) != tolower(-1))
		ret = ft_error_ptr(-1, ret, my_ptr, libc_ptr, 4);
	if (ft_tolower(4) != tolower(4))
		ret = ft_error_ptr(4, ret, my_ptr, libc_ptr, 5);
	if (ft_tolower(2147483648) != tolower(2147483648))
		ret = ft_error_ptr(2147483648, ret, my_ptr, libc_ptr, 6);
	if (ft_tolower(2147483647) != tolower(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 7);
	if (ft_tolower(-2147483648) != tolower(-2147483648))
		ret = ft_error_ptr(-2147483648, ret, my_ptr, libc_ptr, 8);
	if (ft_tolower('\0') != tolower('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 9);
	c = 'A';
	while (c <= 'Z'){
		if (ft_tolower(c) != tolower(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 10);
		c++;
	}
	if (!ret)
		printf(GREEN"OK\n"STOP);
}
void		ft_test_isupper(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	my_ptr = ft_isupper;
	libc_ptr = isupper;
	ret = 0;
	// FT_isupper
	printf(BLUE"ft_isupper = "STOP); 
	c = 'a';
	while (c <= 'z'){
	if (ft_isupper(c) != isupper(c))
		ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_isupper('A') != isupper('A'))
		ret = ft_error_ptr('A', ret, my_ptr, libc_ptr, 1);
	if (ft_isupper(12) != isupper(12))
		ret = ft_error_ptr(12, ret, my_ptr, libc_ptr, 2);
	if (ft_isupper(0) != isupper(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 3);
	if (ft_isupper(-1) != isupper(-1))
		ret = ft_error_ptr(-1, ret, my_ptr, libc_ptr, 4);
	if (ft_isupper(4) != isupper(4))
		ret = ft_error_ptr(4, ret, my_ptr, libc_ptr, 5);
	if (ft_isupper(2147483648) != isupper(2147483648))
		ret = ft_error_ptr(2147483648, ret, my_ptr, libc_ptr, 6);
	if (ft_isupper(2147483647) != isupper(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 7);
	if (ft_isupper(-2147483648) != isupper(-2147483648))
		ret = ft_error_ptr(-2147483648, ret, my_ptr, libc_ptr, 8);
	if (ft_isupper('\0') != isupper('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 9);
	c = 'A';
	while (c <= 'Z'){
		if (ft_isupper(c) != isupper(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 10);
		c++;
	}
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_islower(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	my_ptr = ft_islower;
	libc_ptr = islower;
	ret = 0;
	// FT_islower
	printf(BLUE"ft_islower = "STOP); 
	c = 'a';
	while (c <= 'z'){
		if (ft_islower(c) != islower(c))
			ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_islower('A') != islower('A'))
		ret = ft_error_ptr('A', ret, my_ptr, libc_ptr, 1);
	if (ft_islower(12) != islower(12))
		ret = ft_error_ptr(12, ret, my_ptr, libc_ptr, 2);
	if (ft_islower(0) != islower(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 3);
	if (ft_islower(-1) != islower(-1))
		ret = ft_error_ptr(-1, ret, my_ptr, libc_ptr, 4);
	if (ft_islower(4) != islower(4))
		ret = ft_error_ptr(4, ret, my_ptr, libc_ptr, 5);
	if (ft_islower(2147483648) != islower(2147483648))
		ret = ft_error_ptr(2147483648, ret, my_ptr, libc_ptr, 6);
	if (ft_islower(2147483647) != islower(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 7);
	if (ft_islower(-2147483648) != islower(-2147483648))
		ret = ft_error_ptr(-2147483648, ret, my_ptr, libc_ptr, 8);
	if (ft_islower('\0') != islower('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 9);
	c = 'A';
	while (c <= 'Z'){
		if (ft_islower(c) != islower(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 10);
		c++;
	}
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_isblank(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	ret = 0;
	c = '0';
	my_ptr = ft_isblank;
	libc_ptr = isblank;
	// FT_ISblank
	printf(BLUE"ft_isblank = "STOP); 
	while (c <= '9'){
		if (ft_isblank(c) != isblank(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_isblank(9) != isblank(9))
		ret = ft_error_ptr(9, ret, my_ptr, libc_ptr, 1);
	if (ft_isblank(32) != isblank(32))
		ret = ft_error_ptr(32, ret, my_ptr, libc_ptr, 1);

	if (ft_isblank(48) != isblank(48))
		ret = ft_error_ptr(48, ret, my_ptr, libc_ptr, 1);
	if (ft_isblank('0') != isblank('0'))
		ret = ft_error_ptr('0', ret, my_ptr, libc_ptr, 2);
	if (ft_isblank(57) != isblank(57))
		ret = ft_error_ptr(57, ret, my_ptr, libc_ptr, 3);
	if (ft_isblank('9') != isblank('9'))
		ret = ft_error_ptr('9', ret, my_ptr, libc_ptr, 4);
	if (ft_isblank('\0') != isblank('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 5);
	if (ft_isblank('a') != isblank('a'))
		ret = ft_error_ptr('a', ret, my_ptr, libc_ptr, 6);
	if (ft_isblank(97) != isblank(97))
		ret = ft_error_ptr(97, ret, my_ptr, libc_ptr, 7);
	if (ft_isblank('z') != isblank('z'))
		ret = ft_error_ptr('z', ret, my_ptr, libc_ptr, 8);
	if (ft_isblank(122) != isblank(122))
		ret = ft_error_ptr(122, ret, my_ptr, libc_ptr, 9);
	if (ft_isblank(1) != isblank(1))
		ret = ft_error_ptr(1, ret, my_ptr, libc_ptr, 10);
	if (ft_isblank(0) != isblank(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 11);
	if (ft_isblank(127) != isblank(127))
		ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 12);
	if (ft_isblank(2147483647) != isblank(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 13);
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_iscntrl(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	ret = 0;
	c = '0';
	my_ptr = ft_iscntrl;
	libc_ptr = iscntrl;
	// FT_IScntrl
	printf(BLUE"ft_iscntrl = "STOP); 
	while (c <= '9'){
		if (ft_iscntrl(c) != iscntrl(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_iscntrl(9) != iscntrl(9))
		ret = ft_error_ptr(9, ret, my_ptr, libc_ptr, 1);
	if (ft_iscntrl(32) != iscntrl(32))
		ret = ft_error_ptr(32, ret, my_ptr, libc_ptr, 1);
	if (ft_iscntrl(15) != iscntrl(15))
		ret = ft_error_ptr(15, ret, my_ptr, libc_ptr, 1);

	if (ft_iscntrl(48) != iscntrl(48))
		ret = ft_error_ptr(48, ret, my_ptr, libc_ptr, 1);
	if (ft_iscntrl('0') != iscntrl('0'))
		ret = ft_error_ptr('0', ret, my_ptr, libc_ptr, 2);
	if (ft_iscntrl(57) != iscntrl(57))
		ret = ft_error_ptr(57, ret, my_ptr, libc_ptr, 3);
	if (ft_iscntrl('9') != iscntrl('9'))
		ret = ft_error_ptr('9', ret, my_ptr, libc_ptr, 4);
	if (ft_iscntrl('\0') != iscntrl('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 5);
	if (ft_iscntrl('a') != iscntrl('a'))
		ret = ft_error_ptr('a', ret, my_ptr, libc_ptr, 6);
	if (ft_iscntrl(97) != iscntrl(97))
		ret = ft_error_ptr(97, ret, my_ptr, libc_ptr, 7);
	if (ft_iscntrl('z') != iscntrl('z'))
		ret = ft_error_ptr('z', ret, my_ptr, libc_ptr, 8);
	if (ft_iscntrl(122) != iscntrl(122))
		ret = ft_error_ptr(122, ret, my_ptr, libc_ptr, 9);
	if (ft_iscntrl(1) != iscntrl(1))
		ret = ft_error_ptr(1, ret, my_ptr, libc_ptr, 10);
	if (ft_iscntrl(0) != iscntrl(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 11);
	if (ft_iscntrl(127) != iscntrl(127))
		ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 12);
	if (ft_iscntrl(2147483647) != iscntrl(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 13);
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_isgraph(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	ret = 0;
	c = '0';
	my_ptr = ft_isgraph;
	libc_ptr = isgraph;
	// FT_ISgraph
	printf(BLUE"ft_isgraph = "STOP); 
	while (c <= '9'){
		if (ft_isgraph(c) != isgraph(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_isgraph(9) != isgraph(9))
		ret = ft_error_ptr(9, ret, my_ptr, libc_ptr, 1);
	if (ft_isgraph(32) != isgraph(32))
		ret = ft_error_ptr(32, ret, my_ptr, libc_ptr, 1);
	if (ft_isgraph(15) != isgraph(15))
		ret = ft_error_ptr(15, ret, my_ptr, libc_ptr, 1);

	if (ft_isgraph(48) != isgraph(48))
		ret = ft_error_ptr(48, ret, my_ptr, libc_ptr, 1);
	if (ft_isgraph('0') != isgraph('0'))
		ret = ft_error_ptr('0', ret, my_ptr, libc_ptr, 2);
	if (ft_isgraph(57) != isgraph(57))
		ret = ft_error_ptr(57, ret, my_ptr, libc_ptr, 3);
	if (ft_isgraph('9') != isgraph('9'))
		ret = ft_error_ptr('9', ret, my_ptr, libc_ptr, 4);
	if (ft_isgraph('\0') != isgraph('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 5);
	if (ft_isgraph('a') != isgraph('a'))
		ret = ft_error_ptr('a', ret, my_ptr, libc_ptr, 6);
	if (ft_isgraph(97) != isgraph(97))
		ret = ft_error_ptr(97, ret, my_ptr, libc_ptr, 7);
	if (ft_isgraph('z') != isgraph('z'))
		ret = ft_error_ptr('z', ret, my_ptr, libc_ptr, 8);
	if (ft_isgraph(122) != isgraph(122))
		ret = ft_error_ptr(122, ret, my_ptr, libc_ptr, 9);
	if (ft_isgraph(1) != isgraph(1))
		ret = ft_error_ptr(1, ret, my_ptr, libc_ptr, 10);
	if (ft_isgraph(0) != isgraph(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 11);
	if (ft_isgraph(127) != isgraph(127))
		ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 12);
	if (ft_isgraph(2147483647) != isgraph(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 13);
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_isspace(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	ret = 0;
	c = '0';
	my_ptr = ft_isspace;
	libc_ptr = isspace;
	// FT_ISspace
	printf(BLUE"ft_isspace = "STOP); 
	while (c <= '9'){
		if (ft_isspace(c) != isspace(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_isspace(9) != isspace(9))
		ret = ft_error_ptr(9, ret, my_ptr, libc_ptr, 1);
	if (ft_isspace(32) != isspace(32))
		ret = ft_error_ptr(32, ret, my_ptr, libc_ptr, 1);
	if (ft_isspace(15) != isspace(15))
		ret = ft_error_ptr(15, ret, my_ptr, libc_ptr, 1);

	if (ft_isspace(48) != isspace(48))
		ret = ft_error_ptr(48, ret, my_ptr, libc_ptr, 1);
	if (ft_isspace('0') != isspace('0'))
		ret = ft_error_ptr('0', ret, my_ptr, libc_ptr, 2);
	if (ft_isspace(57) != isspace(57))
		ret = ft_error_ptr(57, ret, my_ptr, libc_ptr, 3);
	if (ft_isspace('9') != isspace('9'))
		ret = ft_error_ptr('9', ret, my_ptr, libc_ptr, 4);
	if (ft_isspace('\0') != isspace('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 5);
	if (ft_isspace('a') != isspace('a'))
		ret = ft_error_ptr('a', ret, my_ptr, libc_ptr, 6);
	if (ft_isspace(97) != isspace(97))
		ret = ft_error_ptr(97, ret, my_ptr, libc_ptr, 7);
	if (ft_isspace('z') != isspace('z'))
		ret = ft_error_ptr('z', ret, my_ptr, libc_ptr, 8);
	if (ft_isspace(122) != isspace(122))
		ret = ft_error_ptr(122, ret, my_ptr, libc_ptr, 9);
	if (ft_isspace(1) != isspace(1))
		ret = ft_error_ptr(1, ret, my_ptr, libc_ptr, 10);
	if (ft_isspace(0) != isspace(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 11);
	if (ft_isspace(127) != isspace(127))
		ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 12);
	if (ft_isspace(2147483647) != isspace(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 13);
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_isxdigit(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	ret = 0;
	c = '0';
	my_ptr = ft_isxdigit;
	libc_ptr = isxdigit;
	// FT_ISxdigit
	printf(BLUE"ft_isxdigit = "STOP); 
	while (c <= '9'){
		if (ft_isxdigit(c) != isxdigit(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_isxdigit(9) != isxdigit(9))
		ret = ft_error_ptr(9, ret, my_ptr, libc_ptr, 1);
	if (ft_isxdigit(32) != isxdigit(32))
		ret = ft_error_ptr(32, ret, my_ptr, libc_ptr, 1);
	if (ft_isxdigit(15) != isxdigit(15))
		ret = ft_error_ptr(15, ret, my_ptr, libc_ptr, 1);

	if (ft_isxdigit(48) != isxdigit(48))
		ret = ft_error_ptr(48, ret, my_ptr, libc_ptr, 1);
	if (ft_isxdigit('0') != isxdigit('0'))
		ret = ft_error_ptr('0', ret, my_ptr, libc_ptr, 2);
	if (ft_isxdigit(57) != isxdigit(57))
		ret = ft_error_ptr(57, ret, my_ptr, libc_ptr, 3);
	if (ft_isxdigit('9') != isxdigit('9'))
		ret = ft_error_ptr('9', ret, my_ptr, libc_ptr, 4);
	if (ft_isxdigit('\0') != isxdigit('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 5);
	if (ft_isxdigit('a') != isxdigit('a'))
		ret = ft_error_ptr('a', ret, my_ptr, libc_ptr, 6);
	if (ft_isxdigit(97) != isxdigit(97))
		ret = ft_error_ptr(97, ret, my_ptr, libc_ptr, 7);
	if (ft_isxdigit('z') != isxdigit('z'))
		ret = ft_error_ptr('z', ret, my_ptr, libc_ptr, 8);
	if (ft_isxdigit(122) != isxdigit(122))
		ret = ft_error_ptr(122, ret, my_ptr, libc_ptr, 9);
	if (ft_isxdigit(1) != isxdigit(1))
		ret = ft_error_ptr(1, ret, my_ptr, libc_ptr, 10);
	if (ft_isxdigit(0) != isxdigit(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 11);
	if (ft_isxdigit(127) != isxdigit(127))
		ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 12);
	if (ft_isxdigit(2147483647) != isxdigit(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 13);
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_ispunct(){
	int 	c;
	int 	ret;
	int 	(*my_ptr)(int);
	int 	(*libc_ptr)(int);

	ret = 0;
	c = '0';
	my_ptr = ft_ispunct;
	libc_ptr = ispunct;
	// FT_ISpunct
	printf(BLUE"ft_ispunct = "STOP); 
	while (c <= '9'){
		if (ft_ispunct(c) != ispunct(c))
			ret = ft_error_ptr(c, ret, my_ptr, libc_ptr, 0);
		c++;
	}
	if (ft_ispunct(9) != ispunct(9))
		ret = ft_error_ptr(9, ret, my_ptr, libc_ptr, 1);
	if (ft_ispunct(32) != ispunct(32))
		ret = ft_error_ptr(32, ret, my_ptr, libc_ptr, 1);
	if (ft_ispunct(15) != ispunct(15))
		ret = ft_error_ptr(15, ret, my_ptr, libc_ptr, 1);

	if (ft_ispunct(48) != ispunct(48))
		ret = ft_error_ptr(48, ret, my_ptr, libc_ptr, 1);
	if (ft_ispunct('0') != ispunct('0'))
		ret = ft_error_ptr('0', ret, my_ptr, libc_ptr, 2);
	if (ft_ispunct(57) != ispunct(57))
		ret = ft_error_ptr(57, ret, my_ptr, libc_ptr, 3);
	if (ft_ispunct('9') != ispunct('9'))
		ret = ft_error_ptr('9', ret, my_ptr, libc_ptr, 4);
	if (ft_ispunct('\0') != ispunct('\0'))
		ret = ft_error_ptr('\0', ret, my_ptr, libc_ptr, 5);
	if (ft_ispunct('a') != ispunct('a'))
		ret = ft_error_ptr('a', ret, my_ptr, libc_ptr, 6);
	if (ft_ispunct(97) != ispunct(97))
		ret = ft_error_ptr(97, ret, my_ptr, libc_ptr, 7);
	if (ft_ispunct('z') != ispunct('z'))
		ret = ft_error_ptr('z', ret, my_ptr, libc_ptr, 8);
	if (ft_ispunct(122) != ispunct(122))
		ret = ft_error_ptr(122, ret, my_ptr, libc_ptr, 9);
	if (ft_ispunct(1) != ispunct(1))
		ret = ft_error_ptr(1, ret, my_ptr, libc_ptr, 10);
	if (ft_ispunct(0) != ispunct(0))
		ret = ft_error_ptr(0, ret, my_ptr, libc_ptr, 11);
	if (ft_ispunct(127) != ispunct(127))
		ret = ft_error_ptr(127, ret, my_ptr, libc_ptr, 12);
	if (ft_ispunct(2147483647) != ispunct(2147483647))
		ret = ft_error_ptr(2147483647, ret, my_ptr, libc_ptr, 13);
	if (!ret)
		printf(GREEN"OK\n"STOP);
}

void		ft_test_putchar(){
	int 	i;

	i = 0;
	// FT_PUTS
	printf(BLUE"ft_putchar = \n"STOP); 

	printf("\nc          = 'c'\n");
	write(1 , "OF_putchar = <", 14);
	putchar('c');
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar('c');
	printf("<\n");

	printf("\nc          = 'a'\n");
	write(1 , "OF_putchar = <", 14);
	putchar('a');
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar('a');
	printf("<\n");

	printf("\nc          = 41\n");
	write(1 , "OF_putchar = <", 14);
	putchar(41);
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar(41);
	printf("<\n");

	printf("\nc          = 'A'\n");
	write(1 , "OF_putchar = <", 14);
	putchar('A');
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar('A');
	printf("<\n");

	printf("\nc          = 4\n");
	write(1 , "OF_putchar = <", 14);
	putchar(4);
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar(4);
	printf("<\n");

	printf("\nc          = 52\n");
	write(1 , "OF_putchar = <", 14);
	putchar(52);
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar(52);
	printf("<\n");

	printf("\nc          = 123\n");
	write(1 , "OF_putchar = <", 14);
	putchar(123);
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar(123);
	printf("<\n");

	printf("\nc          = 9\n");
	write(1 , "OF_putchar = <", 14);
	putchar(9);
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar(9);
	printf("<\n");

	printf("\nc          = 57\n");
	write(1 , "OF_putchar = <", 14);
	putchar(57);
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar(57);
	printf("<\n");

	printf("\nc          = 127\n");
	write(1 , "OF_putchar = <", 14);
	putchar(127);
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar(127);
	printf("<\n");

	printf("\nc          = '*'\n");
	write(1 , "OF_putchar = <", 14);
	putchar('*');
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar('*');
	printf("<\n");

	printf("\nc          = -1\n");
	write(1 , "OF_putchar = <", 14);
	putchar(-1);
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar(-1);
	printf("<\n");

	printf("\nc          = 0\n");
	write(1 , "OF_putchar = <", 14);
	putchar(0);
	printf(">\n");
	write(1 , "FT_putchar = >", 14);
	ft_putchar(0);
	printf("<\n");

	char *str = strdup("Hello World");
	while(str[i]){
		printf("\nc          = '%c'\n", str[i]);
		write(1 , "OF_putchar = <", 14);
		putchar(str[i]);
		printf(">\n");
		write(1 , "FT_putchar = >", 14);
		ft_putchar(str[i]);
		printf("<\n");
		i++;
	}
}

void		ft_test_putchar_fd(){
	int 	i;

	i = 0;
	int fd = 1;
	// FT_PUTS
	printf(BLUE"ft_putchar_fd = \n"STOP); 

	printf("\nc             = 'c'\n");
	write(1 , "OF_putchar    = <", 17);
	putchar('c');
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd('c', fd);
	printf("<\n");

	printf("\nc             = 'a'\n");
	write(1 , "OF_putchar    = <", 17);
	putchar('a');
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd('a', fd);
	printf("<\n");

	printf("\nc             = 41\n");
	write(1 , "OF_putchar    = <", 17);
	putchar(41);
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd(41, fd);
	printf("<\n");

	printf("\nc             = 'A'\n");
	write(1 , "OF_putchar    = <", 17);
	putchar('A');
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd('A', fd);
	printf("<\n");

	printf("\nc             = 4\n");
	write(1 , "OF_putchar    = <", 17);
	putchar(4);
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd(4, fd);
	printf("<\n");

	printf("\nc             = 52\n");
	write(1 , "OF_putchar    = <", 17);
	putchar(52);
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd(52, fd);
	printf("<\n");

	printf("\nc             = 123\n");
	write(1 , "OF_putchar    = <", 17);
	putchar(123);
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd(123, fd);
	printf("<\n");

	printf("\nc             = 9\n");
	write(1 , "OF_putchar    = <", 17);
	putchar(9);
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd(9, fd);
	printf("<\n");

	printf("\nc             = 57\n");
	write(1 , "OF_putchar    = <", 17);
	putchar(57);
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd(57, fd);
	printf("<\n");

	printf("\nc             = 127\n");
	write(1 , "OF_putchar    = <", 17);
	putchar(127);
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd(127, fd);
	printf("<\n");

	printf("\nc             = '*'\n");
	write(1 , "OF_putchar    = <", 17);
	putchar('*');
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd('*', fd);
	printf("<\n");

	printf("\nc             = -1\n");
	write(1 , "OF_putchar    = <", 17);
	putchar(-1);
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd(-1, fd);
	printf("<\n");

	printf("\nc             = 0\n");
	write(1 , "OF_putchar    = <", 17);
	putchar(0);
	printf(">\n");
	write(1 , "ft_putchar_fd = >", 17);
	ft_putchar_fd(0, fd);
	printf("<\n");

	char *str = strdup("Hello World");
	while(str[i]){
		printf("\nc             = '%c'\n", str[i]);
		write(1 , "OF_putchar    = <", 17);
		putchar(str[i]);
		printf(">\n");
		write(1 , "ft_putchar_fd = >", 17);
		ft_putchar_fd(str[i], fd);
		printf("<\n");
		i++;
	}
}

void	ft_test_puts(int null){
	char *str;

	str = NULL;
	// FT_PUTS
	printf(BLUE"ft_puts = \n"STOP);

	printf("\nstr     = 'aaaa'\n");
	write(1 , "puts    = <", 11);
	puts("aaaa");
	printf(">\n");
	write(1 , "ft_puts = <", 11);
	ft_puts("aaaa");
	printf(">\n");
	
	printf("\nstr     = 'Gro'\n");
	write(1 , "puts    = <", 11);
	puts("Gro");
	printf(">\n");
	write(1 , "ft_puts = <", 11);
	ft_puts("Gro");
	printf(">\n");


	printf("\nstr     = 'Bplop'\n");
	write(1 , "puts    = <", 11);
	puts("Bplop");
	printf(">\n");
	write(1 , "ft_puts = <", 11);
	ft_puts("Bplop");
	printf(">\n");


	printf("\nstr     = 'ZzZz'\n");
	write(1 , "puts    = <", 11);
	puts("ZzZz");
	printf(">\n");
	write(1 , "ft_puts = <", 11);
	ft_puts("ZzZz");
	printf(">\n");


	printf("\nstr     = 'a'\n");
	write(1 , "puts    = <", 11);
	puts("a");
	printf(">\n");
	write(1 , "ft_puts = <", 11);
	ft_puts("a");
	printf(">\n");

	printf("\nstr     = 'AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA'\n");
	write(1 , "puts    = <", 11);
	puts("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	printf(">\n");
	write(1 , "ft_puts = <", 11);
	ft_puts("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	printf(">\n");

	str     = strdup("Hello World");
	printf("\nstr     = %s\n", str);
	write(1 , "puts    = <", 11);
	puts(str);
	printf(">\n");
	write(1 , "ft_puts = <", 11);
	ft_puts(str);
	printf(">\n");

	//NULL TEST
	if (null){
		printf("\nstr     = NULL\n");
		write(1 , "puts    = <", 11);
		puts(NULL);
		printf(">\n");

		write(1 , "ft_puts = <", 11);
		ft_puts(NULL);
		printf(">\n");
	}
}

void	ft_test_putendl(int null){
	char *str;

	str = NULL;
	// FT_PUTS
	printf(BLUE"ft_putendl = \n"STOP);

	printf("\nstr        = 'aaaa'\n");
	write(1 , "puts       = <", 14);
	puts("aaaa");
	printf(">\n");
	write(1 , "ft_putendl = <", 14);
	ft_putendl("aaaa");
	printf(">\n");
	
	printf("\nstr        = 'Gro'\n");
	write(1 , "puts       = <", 14);
	puts("Gro");
	printf(">\n");
	write(1 , "ft_putendl = <", 14);
	ft_putendl("Gro");
	printf(">\n");


	printf("\nstr        = 'Bplop'\n");
	write(1 , "puts       = <", 14);
	puts("Bplop");
	printf(">\n");
	write(1 , "ft_putendl = <", 14);
	ft_putendl("Bplop");
	printf(">\n");


	printf("\nstr        = 'ZzZz'\n");
	write(1 , "puts       = <", 14);
	puts("ZzZz");
	printf(">\n");
	write(1 , "ft_putendl = <", 14);
	ft_putendl("ZzZz");
	printf(">\n");


	printf("\nstr        = 'a'\n");
	write(1 , "puts       = <", 14);
	puts("a");
	printf(">\n");
	write(1 , "ft_putendl = <", 14);
	ft_putendl("a");
	printf(">\n");

	printf("\nstr        = 'AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA'\n");
	write(1 , "puts       = <", 14);
	puts("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	printf(">\n");
	write(1 , "ft_putendl = <", 14);
	ft_putendl("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	printf(">\n");

	str     = strdup("Hello World");
	printf("\nstr        = %s\n", str);
	write(1 , "puts       = <", 14);
	puts(str);
	printf(">\n");
	write(1 , "ft_putendl = <", 14);
	ft_putendl(str);
	printf(">\n");

	//NULL TEST
	str = 0;
	if (null){
		printf("\nstr        = %s\n", str);
		write(1 , "puts       = <", 14);
		puts(str);
		printf(">\n");

		write(1 , "ft_putendl = <", 14);
		ft_putendl(str);
		printf(">\n");
	}
}

void	ft_test_putendl_fd(int null){
	char *str;

	str = NULL;
	int fd = 1;
	// FT_PUTS
	printf(BLUE"ft_putendl_fd = \n"STOP);

	printf("\nstr           = 'aaaa'\n");
	write(1 , "puts          = <", 17);
	puts("aaaa");
	printf(">\n");
	write(1 , "ft_putendl_fd = <", 17);
	ft_putendl_fd("aaaa", fd);
	printf(">\n");
	
	printf("\nstr           = 'Gro'\n");
	write(1 , "puts          = <", 17);
	puts("Gro");
	printf(">\n");
	write(1 , "ft_putendl_fd = <", 17);
	ft_putendl_fd("Gro", fd);
	printf(">\n");


	printf("\nstr           = 'Bplop'\n");
	write(1 , "puts          = <", 17);
	puts("Bplop");
	printf(">\n");
	write(1 , "ft_putendl_fd = <", 17);
	ft_putendl_fd("Bplop", fd);
	printf(">\n");


	printf("\nstr           = 'ZzZz'\n");
	write(1 , "puts          = <", 17);
	puts("ZzZz");
	printf(">\n");
	write(1 , "ft_putendl_fd = <", 17);
	ft_putendl_fd("ZzZz", fd);
	printf(">\n");


	printf("\nstr           = 'a'\n");
	write(1 , "puts          = <", 17);
	puts("a");
	printf(">\n");
	write(1 , "ft_putendl_fd = <", 17);
	ft_putendl_fd("a", fd);
	printf(">\n");

	printf("\nstr           = 'AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA'\n");
	write(1 , "puts          = <", 17);
	puts("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	printf(">\n");
	write(1 , "ft_putendl_fd = <", 17);
	ft_putendl_fd("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA", fd);
	printf(">\n");

	str     = strdup("Hello World");
	printf("\nstr           = %s\n", str);
	write(1 , "puts          = <", 17);
	puts(str);
	printf(">\n");
	write(1 , "ft_putendl_fd = <", 17);
	ft_putendl_fd(str, fd);
	printf(">\n");

	//NULL TEST
	if (null){
		str = 0;
		printf("\nstr        = %s\n", str);
		write(1 , "puts          = <", 17);
		puts(str);
		printf(">\n");

		write(1 , "ft_putendl_fd = <", 17);
		ft_putendl_fd(str, fd);
		printf(">\n");
	}
}

void	ft_test_putstr(int null){
	char *str;

	str = NULL;
	// FT_PUTS
	printf(BLUE"ft_putstr = \n"STOP);

	printf("\nstr       = 'aaaa'\n");
	// puts("aaaa");
	// ft_puts("aaaa");
	write(1 , "ft_putstr = <", 13);
	ft_putstr("aaaa");
	printf(">\n");
	
	printf("\nstr       = 'Gro'\n");
	// puts("Gro");
	// ft_puts("Gro");
	write(1 , "ft_putstr = <", 13);
	ft_putstr("Gro");
	printf(">\n");

	printf("\nstr       = 'Bplop'\n");
	// puts("Bplop");
	// ft_puts("Bplop");
	write(1 , "ft_putstr = <", 13);
	ft_putstr("Bplop");
	printf(">\n");


	printf("\nstr       = 'ZzZz'\n");
	// puts("ZzZz");
	// ft_puts("ZzZz");
	write(1 , "ft_putstr = <", 13);
	ft_putstr("ZzZz");
	printf(">\n");


	printf("\nstr       = 'a'\n");
	// puts("a");
	// ft_puts("a");
	write(1 , "ft_putstr = <", 13);
	ft_putstr("a");
	printf(">\n");

	printf("\nstr       = 'AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA'\n");
	// puts("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	// ft_puts("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	write(1 , "ft_putstr = <", 13);
	ft_putstr("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	printf(">\n");

	str     = strdup("Hello World");
	printf("\nstr       = %s\n", str);
	// puts(str);
	// ft_puts(str);
	write(1 , "ft_putstr = <", 13);
	ft_putstr(str);
	printf(">\n");

	//NULL T  EST
	if (null){
		str = 0;
		printf("\nstr        = %s\n", str);
		// puts(NULL);
		// ft_puts(NULL);
		write(1 , "ft_putstr = <", 13);
		ft_putstr(str);
		printf(">\n");
	}

}void	ft_test_putstr_fd(int null){
	char *str;

	str = NULL;
	int 	fd = 1;
	// FT_PUTS
	printf(BLUE"ft_putstr_fd = \n"STOP);

	printf("\nstr          = 'aaaa'\n");
	// puts("aaaa");
	// ft_puts("aaaa");
	write(1 , "ft_putstr_fd = <", 16);
	ft_putstr_fd("aaaa", fd);
	printf(">\n");
	
	printf("\nstr          = 'Gro'\n");
	// puts("Gro");
	// ft_puts("Gro");
	write(1 , "ft_putstr_fd = <", 16);
	ft_putstr_fd("Gro", fd);
	printf(">\n");


	printf("\nstr          = 'Bplop'\n");
	// puts("Bplop");
	// ft_puts("Bplop");
	write(1 , "ft_putstr_fd = <", 16);
	ft_putstr_fd("Bplop", fd);
	printf(">\n");


	printf("\nstr          = 'ZzZz'\n");
	// puts("ZzZz");
	// ft_puts("ZzZz");
	write(1 , "ft_putstr_fd = <", 16);
	ft_putstr_fd("ZzZz", fd);
	printf(">\n");


	printf("\nstr          = 'a'\n");
	// puts("a");
	// ft_puts("a");
	write(1 , "ft_putstr_fd = <", 16);
	ft_putstr_fd("a", fd);
	printf(">\n");

	printf("\nstr          = 'AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA'\n");
	// puts("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	// ft_puts("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	write(1 , "ft_putstr_fd = <", 16);
	ft_putstr_fd("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA", fd);
	printf(">\n");

	str     = strdup("Hello World");
	printf("\nstr          = %s\n", str);
	// puts(str);
	// ft_puts(str);
	write(1 , "ft_putstr_fd = <", 16);
	ft_putstr_fd(str, fd);
	printf(">\n");

	//NULL TE     ST
	if (null){
		str = 0;
		printf("\nstr          = %s\n", str);
		// puts(NULL);
		// ft_puts(NULL);
		write(1 , "ft_putstr_fd = <", 16);
		ft_putstr_fd(str , fd);
		printf(">\n");
	}
}

int 		ft_error_ft_strlen(int ret, char *str, int len1, int len2, int test){
	if (ret == 0)
		printf(RED" KO\n"STOP);
	printf("\t• test %d\n\t  str = <%s>\n\t  expected = <%d>\n\t  returned = <%d>\n", test, str, len2, len1);
	return (1);	
}
	
void		ft_test_strlen(int null){
	int 	ret;
	char 	*str;

	ret = 0;
	str = NULL;
	// FT_STRLEN
	printf(BLUE"ft_strlen  = "STOP); 
	str = strdup("hello");
	if (strlen(str) != ft_strlen(str))
		ret = ft_error_ft_strlen(ret, str, strlen(str), ft_strlen(str), 0);
	str = strdup("hello World!");
	if (strlen(str) != ft_strlen(str))
		ret = ft_error_ft_strlen(ret, str, strlen(str), ft_strlen(str), 1);
	str = strdup("helloYou....");
	if (strlen(str) != ft_strlen(str))
		ret = ft_error_ft_strlen(ret, str, strlen(str), ft_strlen(str), 2);
	str = strdup("hello!");
	if (strlen(str) != ft_strlen(str))
		ret = ft_error_ft_strlen(ret, str, strlen(str), ft_strlen(str), 3);
	str = strdup("");
	if (strlen(str) != ft_strlen(str))
		ret = ft_error_ft_strlen(ret, str, strlen(str), ft_strlen(str), 4);
	if (strlen("plop") != ft_strlen("plop"))
		ret = ft_error_ft_strlen(ret, "plop", strlen("plop"), ft_strlen("plop"), 5);
	if (strlen("") != ft_strlen(""))
		ret = ft_error_ft_strlen(ret, "", strlen(""), ft_strlen(""), 6);
	if (strlen("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA") != ft_strlen("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA"))
		ret = ft_error_ft_strlen(ret, "AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA", strlen("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA"), ft_strlen("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA"), 7);	// str2 = NULL;
	if (!ret)
		printf(GREEN"OK\n"STOP);
	//NULL TEST
	if (null){
		int test = ft_strlen(NULL);
		printf("NULL TEST = <%d>\n", test);
	}
}


int 		ft_error_ft_memset(int ret, char *str1, char *str2, int test){
	if (ret == 0)
		printf(RED"KO\n"STOP);
	printf("\t• test %d\n\t  expected = <%s>\n\t  returned = <%s>\n", test, str1, str2);
	return (1);	
}


void		ft_test_memset(int null){
	int 	ret;
	char 	*str1;
	char 	*str2;

	ret = 0;
	// FT_MEMSET
	printf(BLUE"ft_memset  = "STOP); 
//printf("test 0\n");
	str1 = strdup("hello");
	str2 = strdup("hello");
	memset(str1, 'a', 1);
	ft_memset(str2, 'a', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 0);
//printf("test 1\n");
	str1 = strdup("hello");
	str2 = strdup("hello");
	str1 = memset(str1, 'a', 1);
	str2 = ft_memset(str2, 'a', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 1);
//printf("test 2\n");
	str1 = strdup("hello");
	str2 = strdup("hello");
	memset(str1, 'a', 4);
	ft_memset(str2, 'a', 4);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 2);
//printf("test 3\n");
	str1 = strdup("hello");
	str2 = strdup("hello");
	str1 = memset(str1, 'a', 4);
	str2 = ft_memset(str2, 'a', 4);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 3);
//printf("test 4\n");
	str1 = strdup("hello");
	str2 = strdup("hello");
	memset(str1, 'a', 10);
	ft_memset(str2, 'a', 10);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 4);
//printf("test 5\n");
	str1 = strdup("hello");
	str2 = strdup("hello");
	str1 = memset(str1, 'a', 10);
	str2 = ft_memset(str2, 'a', 10);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 5);
//printf("test 6\n");
	str1 = strdup("a");
	str2 = strdup("a");
	memset(str1, 'z', 1);
	ft_memset(str2, 'z', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 6);
//printf("test 7\n");
	str1 = strdup("a");
	str2 = strdup("a");
	str1 = memset(str1, 'z', 1);
	str2 = ft_memset(str2, 'z', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 7);
//printf("test 8\n");
	str1 = strdup("a");
	str2 = strdup("a");
	memset(str1, 'z', 0);
	ft_memset(str2, 'z', 0);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 8);
//printf("test 9\n");
	str1 = strdup("a");
	str2 = strdup("a");
	str1 = memset(str1, 'z', 0);
	str2 = ft_memset(str2, 'z', 0);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 9);
//printf("test 10\n");
	str1 = strdup("");
	str2 = strdup("");
	memset(str1, 'z', 1);
	ft_memset(str2, 'z', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 10);
//printf("test 11\n");
	str1 = strdup("");
	str2 = strdup("");
	str1 = memset(str1, 'z', 1);
	str2 = ft_memset(str2, 'z', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 11);
//printf("test 12\n");
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	memset(str1, 'z', 1);
	ft_memset(str2, 'z', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 12);
//printf("test 13\n");
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str1 = memset(str1, 'z', 1);
	str2 = ft_memset(str2, 'z', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 13);
//printf("test 14\n");
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	memset(str1, 'z', 50);
	ft_memset(str2, 'z', 50);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 14);
//printf("test 15\n");
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str1 = memset(str1, 'z', 50);
	str2 = ft_memset(str2, 'z', 50);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 15);
//printf("test 16\n");
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	memset(str1, 'z', strlen(str1));
	ft_memset(str2, 'z', strlen(str2));
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 16);
//printf("test 17\n");
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str1 = memset(str1, 'z', strlen(str1));
	str2 = ft_memset(str2, 'z', strlen(str2));
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 17);
//printf("test 18\n");
	str1 = strdup("Hello World!");
	str2 = strdup("Hello World!");
	memset(str1, 'z', 1);
	ft_memset(str2, 'z', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 18);
//printf("test 19\n");
	str1 = strdup("Hello World!");
	str2 = strdup("Hello World!");
	str1 = memset(str1, 'z', 1);
	str2 = ft_memset(str2, 'z', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 19);
//printf("test 0\n");
	str1 = strdup("  Hello World!  ");
	str2 = strdup("  Hello World!  ");
	memset(str1, 'z', strlen(str1));
	ft_memset(str2, 'z', strlen(str2));
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 20);
//printf("test 20\n");
	str1 = strdup("  Hello World!  ");
	str2 = strdup("  Hello World!  ");
	str1 = memset(str1, 'z', strlen(str1));
	str2 = ft_memset(str2, 'z', strlen(str2));
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 21);
//printf("test 21\n");
	str1 = strdup("  Hello World!  ");
	str2 = strdup("  Hello World!  ");
	memset(str1, 'z', 1);
	ft_memset(str2, 'z', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 22);
//printf("test 22\n");
	str1 = strdup("  Hello World!  ");
	str2 = strdup("  Hello World!  ");
	str1 = memset(str1, 'z', 1);
	str2 = ft_memset(str2, 'z', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 23);
//printf("test 23\n");
	int a;
	int b;
	int *i;
	int *j;

	a = 65;
	b = 65;
	i = &a;
	j = &b;
//printf("test 24\n");
	str1 = (char *)memset(i, 'z', 1);
	str2 = (char *)ft_memset(j, 'z', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 24);
//printf("test 25\n");
	a = 65;
	b = 65;
	i = &a;
	j = &b;
//printf("test 26\n");
	str1 = (char *)memset(i, 'z', 1);
	str2 = (char *)ft_memset(j, 'z', 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memset(ret, str1, str2, 25);
	if (!ret)
		printf(GREEN"OK\n"STOP);
	if (null){
		char *test = ft_memset(NULL, 'z', 10);
		printf("NULL TEST = <%s>\n", test);
//printf("test OK\n");
	}
}

int 		ft_error_ft_memcpy(int ret, char *str1, char *str2, int test){
	if (ret == 0)
		printf(RED"KO\n"STOP);
	printf("\t• test %d\n\t  expected = <%s>\n\t  returned = <%s>\n", test, str1, str2);
	return (1);	
}


void		ft_test_memcpy(int null){
	int 	ret;
	char 	*str1;
	char 	*str2;

	ret = 0;
	// FT_MEMSET
	printf(BLUE"ft_memcpy  = "STOP); 
	str1 = strdup("aaaaa");
	str2 = strdup("aaaaa");
	str1 = memcpy(str1, "xxxxx", 1);
	str2 = memcpy(str2, "xxxxx", 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memcpy(ret, str1, str2, 0);
	str1 = strdup("a");
	str2 = strdup("a");
	str1 = memcpy(str1, "xxxxx", 1);
	str2 = memcpy(str2, "xxxxx", 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memcpy(ret, str1, str2, 1);
	str1 = strdup("");
	str2 = strdup("");
	str1 = memcpy(str1, "xxxxx", 1);
	str2 = memcpy(str2, "xxxxx", 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memcpy(ret, str1, str2, 2);
	str1 = strdup("");
	str2 = strdup("");
	str1 = memcpy(str1, "xxxxx", 0);
	str2 = memcpy(str2, "xxxxx", 0);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memcpy(ret, str1, str2, 3);
	str1 = strdup("");
	str2 = strdup("");
	str1 = memcpy(str1, "", 1);
	str2 = memcpy(str2, "", 1);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memcpy(ret, str1, str2, 4);
	str1 = strdup("Hello World");
	str2 = strdup("Hello World");
	str1 = memcpy(str1, "q", 30);
	str2 = memcpy(str2, "q", 30);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memcpy(ret, str1, str2, 5);
	str1 = strdup("Hello World");
	str2 = strdup("Hello World");
	str1 = memcpy(str1, "q", 100);
	str2 = memcpy(str2, "q", 100);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memcpy(ret, str1, str2, 6);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str1 = memcpy(str1, "z", 10);
	str2 = memcpy(str2, "z", 10);
	if (strcmp(str1, str2))
		ret = ft_error_ft_memcpy(ret, str1, str2, 7);
	if (!ret)
		printf(GREEN"OK\n"STOP);
	if (null){
		char *test = ft_memset(NULL, 'a', 10);
		printf("NULL TEST = <%s>\n", test);
	}
}


int 		ft_error_strdup(int ret, char *str1, char *str2, int test){
	if (ret == 0)
		printf(RED" KO\n"STOP);
	printf("\t• test %d\n\t  expected = <%s>\n\t  returned = <%s>\n", test,  str1, str2);
	return (1);	
}


void		ft_test_strdup(int null){
	int 	ret;
	char 	*str1;
	char 	*str2;
	ret = 0;

	// FT_STRDUP
	printf(BLUE"ft_strdup  = "STOP); 
	str1 = NULL;
	str2 = NULL;
	str1 = strdup("hello");
	str2 = ft_strdup("hello");
	if (strcmp(str1, str2))
		ret = ft_error_strdup(ret, str1, str2, 0);
	str1 = strdup("Abracadabra");
	str2 = ft_strdup("Abracadabra");
	if (strcmp(str1, str2))
		ret = ft_error_strdup(ret, str1, str2, 1);
	str1 = strdup("a");
	str2 = ft_strdup("a");
	if (strcmp(str1, str2))
		ret = ft_error_strdup(ret, str1, str2, 2);
	str1 = strdup("");
	str2 = ft_strdup("");
	if (strcmp(str1, str2))
		ret = ft_error_strdup(ret, str1, str2, 3);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = ft_strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	if (strcmp(str1, str2))
		ret = ft_error_strdup(ret, str1, str2, 4);
	str1 = strdup(" ");
	str2 = ft_strdup(" ");
	if (strcmp(str1, str2))
		ret = ft_error_strdup(ret, str1, str2, 5);
	str1 = strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	str2 = ft_strdup("AaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA");
	if (!ret)
		printf(GREEN"OK\n"STOP);		
	if (null){
		char *test = ft_strdup(NULL);
		printf("NULL TEST = <%s>\n", test);
	}

}

void 	ft_error(char *str)
{
	printf("%s\n", str);
	return ;
}

void 		ft_test_cat(){
	int 	fd;
	char 	buff[1024];

	//FT_CAT
	printf(BLUE"ft_cat  = \n"STOP);
	write(1, YELLOW"opening makefile", 16+ strlen(YELLOW));
	write(1, ".", 1);
	usleep(500000);
	write(1, ".", 1);
	usleep(500000);
	write(1, "."STOP, 1 + strlen(STOP));
	usleep(500000);
	write(1, "\n", 1);
	if ((fd = open("Makefile", O_RDONLY)) == -1)
		ft_error(RED"OPEN FAILED"STOP);
	else{
printf("fd == %d\n", fd);
		ft_cat(fd);
		if ((close(fd)) == -1)
			ft_error(RED"CLOSE FAILED"STOP);
	}
printf("________________\n");
	while (1){
		printf(GREEN"\ncontinue Y/N?\n"STOP);
		bzero(buff, 100);
		read(0, buff, 100);
		if (buff[0] == 'N')
			return;
		else if (buff[0] == 'Y')
			break;
	}
printf("________________\n");
	printf(YELLOW"type a filename to open it:\033[0m\n");
	bzero(buff, 100);
	read(0, buff, 100);
	sleep(1);
	char *filename = ft_strdup(buff);
	filename[strlen(filename) - 1] = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error(RED"OPEN FAILED"STOP);
	else{
		ft_cat(fd);
		if ((close(fd)) == -1)
			return (ft_error(RED"CLOSE FAILED"STOP));
	}
printf("\n________________\n");
printf("\nft_cat(-1): no problem?\n");
	while (1){
		printf(GREEN"\ncontinue Y/N?\n"STOP);
		bzero(buff, 100);
		read(0, buff, 100);
		if (buff[0] == 'N')
			return;
		else if (buff[0] == 'Y')
			break;
	}
	fd = 0;
	ft_cat(-1);
printf("\nft_cat(-1): OK !!!!\n");
printf("\n________________\n");
printf("\nft_cat(fd): open main.c\n");
	while (1){
		printf(GREEN"\ncontinue Y/N?\n"STOP);
		bzero(buff, 100);
		read(0, buff, 100);
		if (buff[0] == 'N')
			return;
		else if (buff[0] == 'Y')
			break;
	}
	fd = open(__FILE__, O_RDONLY);
	printf("\nft_cat(fd): open main.c\n");
	ft_cat(fd);

	printf("\n________________\n");
	while (1){
		printf(GREEN"\ncontinue Y/N?\n"STOP);
		bzero(buff, 100);
		read(0, buff, 100);
		if (buff[0] == 'N')
			return;
		else if (buff[0] == 'Y')
			break;
	}
	printf("\n________________\n");
	printf(GREEN"\nft_cat(0): type some text\033[0m\n");
	ft_cat(0);
	close(fd);
	printf(GREEN"BRAVO\n"STOP);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!strcmp(av[1], "-info")){
			printf(RED"\t• /!\\ If a test is KO, it is not necessarily\n false, please make sure you understand the test before\n grading your peer.\n"STOP);
			printf(RED"\t• A segfault in libcnull test, is not\n necessarily bad, the libc also may segfault the same\n way so please don't be a dickhead!\n"STOP);
			printf("Special Thx to Tpageard and Erobert for their help\n");
		}
		if (!strcmp(av[1], "-libc")){
			ft_test_bzero(0);
			ft_test_strcat(0);
			ft_test_isalpha();
			ft_test_isdigit();
			ft_test_isalnum();
			ft_test_isascii();
			ft_test_isprint();
			ft_test_toupper();
			ft_test_tolower();
			ft_test_strlen(0);
			ft_test_memset(0);
			ft_test_memcpy(0);
			ft_test_strdup(0);
		}
		if (!strcmp(av[1], "-part1")){
			ft_test_bzero(0);
			ft_test_strcat(0);
			ft_test_isalpha();
			ft_test_isdigit();
			ft_test_isalnum();
			ft_test_isascii();
			ft_test_isprint();
			ft_test_toupper();
			ft_test_tolower();
		}
		if (!strcmp(av[1], "-part2")){
			ft_test_strlen(0);
			ft_test_memset(0);
			ft_test_memcpy(0);
			ft_test_strdup(0);
		}
		if (!strcmp(av[1], "-part3")){
			ft_test_cat();
		}
		if (!strcmp(av[1], "-null")){
			ft_test_puts(1);
			ft_test_bzero(1);
			ft_test_strcat(1);
			ft_test_strlen(1);
			ft_test_memset(1);
			ft_test_memcpy(1);
			ft_test_strdup(1);
			ft_test_puts(1);
		}
		if (!strcmp(av[1], "-bonus")){
			ft_test_isupper();
			ft_test_islower();
			ft_test_isblank();
			ft_test_iscntrl();
			ft_test_isgraph();
			ft_test_isspace();
			ft_test_isxdigit();
			ft_test_ispunct();

		}
		if (!strcmp(av[1], "-full")){
			ft_test_bzero(1);
			ft_test_strcat(1);
			ft_test_isalpha();
			ft_test_isdigit();
			ft_test_isalnum();
			ft_test_isascii();
			ft_test_isprint();
			ft_test_toupper();
			ft_test_tolower();
			ft_test_strlen(1);
			ft_test_memset(1);
			ft_test_memcpy(1);
			ft_test_strdup(1);
			ft_test_puts(1);
			ft_test_cat();
	}
		else if (!strcmp(av[1], "-puts"))
			ft_test_puts(0);
		else if (!strcmp(av[1], "-putchar"))
			ft_test_putchar();
		 else if (!strcmp(av[1], "-putstr"))
		 	ft_test_putstr(1);
		 else if (!strcmp(av[1], "-putendl"))
		 	ft_test_putendl(1);
		else if (!strcmp(av[1], "-putchar_fd"))
			ft_test_putchar_fd();
		 else if (!strcmp(av[1], "-putstr_fd"))
		 	ft_test_putstr_fd(1);
		 else if (!strcmp(av[1], "-putendl_fd"))
		 	ft_test_putendl_fd(1);
		else if (!strcmp(av[1], "-ft_cat"))
			ft_test_cat();
	}
	else{
			printf(RED"Welcome to main_libftasm V0.3\n"STOP);		
			printf("usage ./a.out -[ARG]\n");
			printf("-libc to have libc compare test\n");
			printf("-part1 to have part1 compare test\n");
			printf("-part2 to have part2 compare test\n");
			printf("-puts to have the puts test\n");
			printf("-part3 to have the ft_cat test\n");
			printf("-bonus to have bonus compare test\n");
			printf("-null to have libc compare test and null test (view info)\n");
			printf("-ft_cat to have the ft_cat test\n");
			printf("-putchar to have the putchar test(bonus)\n");
			printf("-putstr to have the putstr test(bonus)\n");
			printf("-putchar_fd to have the putchar_fd test(bonus)\n");
			printf("-putstr_fd to have the putstr_fd test(bonus)\n");
			printf("-putendl to have the putendl test(bonus)\n");
			printf("-putendl_fd to have the putendl_fd test(bonus)\n");
			printf("-full to have all test\n");
			printf("-info for more informations\n");
	}

	return(0);
}

