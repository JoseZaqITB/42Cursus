
#include "ft_printf.h"
#include <stdio.h>

void	returncmp(int n, int n2)
{
	printf("\nprintfR: %d | ft_printfR: %d\n", n, n2);
}

void	printhint(void)
{
	printf("---\n+: original\n-: mine\n---\n\n");
}

void	testc(void)
{
	int	n;
	int	n2;

	printhint();
	n = printf("+: %d\n", 42);
	n2 = ft_printf("-: %d\n", 42);
	returncmp(n, n2);
}

void	tests(void)
{
	int	n;
	int	n2;

	printhint();
	//
	n = printf("+: %s\n", "Random string");
	n2 = ft_printf("-: %s\n", "Random string");
	returncmp(n, n2);
	//
	n = printf("+: NULL %s NULL \n", NULL);
	n2 = ft_printf("-: NULL %s NULL \n", NULL);
	returncmp(n, n2);
}

void	testp(void)
{
	int	n;
	int	n2;

	printhint();
	n = printf("+: %p\n", &n);
	n2 = ft_printf("-: %p\n", &n);
	returncmp(n, n2);
	//
	n = printf("+: %p %p\n", 0, 0);
	n2 = ft_printf("-: %p %p\n", 0, 0);
	returncmp(n, n2);
}

void	testd(void)
{
	int	n;
	int	n2;

	printhint();
	n = printf("+: %d\n", 42);
	n2 = ft_printf("-: %d\n", 42);
	returncmp(n, n2);
}

void	testi(void)
{
	int	n;
	int	n2;

	printhint();
	n = printf("+: %d\n", 42);
	n2 = ft_printf("-: %d\n", 42);
	returncmp(n, n2);
}

void	testu(void)
{
	int	n;
	int	n2;

	printhint();
	n = printf("+: %u\n", -1);
	n2 = ft_printf("-: %u\n", -1);
	returncmp(n, n2);
}

void	testx(void)
{
	int	n;
	int	n2;

	printhint();
	n = printf("+: %x\n", 255);
	n2 = ft_printf("-: %x\n", 255);
	returncmp(n, n2);
	//
	n = printf("+: %x|%x|%x\n", 99, 100, 101);
	n2 = ft_printf("-: %x|%x|%x\n", 99, 100, 101);
	returncmp(n, n2);
}

void	testbx(void)
{
	int	n;
	int	n2;

	printhint();
	n = printf("+: %X\n", 255);
	n2 = ft_printf("-: %X\n", 255);
	returncmp(n, n2);
}

void	testpctg(void)
{
	int	n;
	int	n2;

	printhint();
	n = printf("+: %%\n");
	n2 = ft_printf("-: %%\n");
	returncmp(n, n2);
}

void	testmix(void)
{
	int	n;
	int	n2;

	printhint();
	n = printf("+: Oli: %s | %u | %c | %d | %i | %x | %X | %p | %u\n chai \n%","string", -1, '$', 4.1, 4.1, 345, 101, &n, -1);
	n2 = ft_printf("-: Oli: %s | %u | %c | %d | %i | %x | %X | %p | %u\n chai \n%","string", -1, '$', 4.1, 4.1, 345, 101, &n, -1);
	returncmp(n, n2);
}


int	main(void)
{
	int	in;

	while (1)
	{
		printf(
			"---MAIN MENU---\n"
			"1. %%c\n"
			"2. %%s\n"
			"3. %%p\n"
			"4. %%d\n"
			"5. %%i\n"
			"6. %%u\n"
			"7. %%x\n"
			"8. %%X\n"
			"9. %%%%\n"
			"10. mix\n"
			"0. end\n"
			);
		scanf("%d", &in);
		printf("\n||---------------\n\n");
		if (in == 1)
			testc();
		else if (in == 2)
			tests();
		else if (in == 3)
			testp();
		else if (in == 4)
			testd();
		else if (in == 5)
			testi();
		else if (in == 6)
			testu();
		else if (in == 7)
			testx();
		else if (in == 8)
			testbx();
		else if (in == 9)
			testpctg();
		else if (in == 10)
			testmix();
		else if (in == 0)
			return (0);
		else
			printf("Incorrect selection");
		printf("\n\n||---------------\n");
	}
	return (0);
}
