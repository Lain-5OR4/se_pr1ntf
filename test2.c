#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
    int i;
    int j;
    i = printf("%5p, %5p, %5p, %5p, %5p, %5p\n", (void *)0, (void *)0xABCDE, (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352);
	j = ft_printf("%5p, %5p, %5p, %5p, %5p, %5p\n", (void *)0, (void *)0xABCDE, (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352);
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");
    
    i = printf("|%+7.0d|\n", 0);
    j = ft_printf("|%+7.0d|\n", 0);
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");

    i = printf("|%++10.0d|\n", 0);
    j = ft_printf("|%++10.0d|\n", 0);
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");

    i = printf("|%+d|\n", 123456);
    j = ft_printf("|%+d|\n", 123456);
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");

    i = printf("|%09.0d| |%020d|\n", 1234, 9876);
    j = ft_printf("|%09.0d| |%020d|\n", 1234, 9876);
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");

    i = printf("|%050.0d| |%030d|\n", 1234, -987612345);
    j = ft_printf("|%050.0d| |%030d|\n", 1234, -987612345);
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");
    i = printf("%c %s %p %d %d %i %u %x %X\n", 42, "42", NULL, 42, 42, 42, 42, 42, 42);
    j = ft_printf("%c %s %p %d %d %i %u %x %X\n", 42, "42", NULL, 42, 42, 42, 42, 42, 42);
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");

    i = printf("%d%d%d\n", INT_MAX, INT_MIN, 0);
    j = ft_printf("%d%d%d\n", INT_MAX, INT_MIN, 0);
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");

    i = printf("| %.2s %.1s |\n", "", "-");
    j = ft_printf("| %.2s %.1s |\n", "", "-");
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");
    // j = printf("%s\n", INT_MAX, 0); // Segmentation fault
    i = printf("| %.3s %.2s |\n", " - ", "");
    j = ft_printf("| %.3s %.2s |\n", " - ", "");
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");

    i = printf("| %.10d |\n", LONG_MAX);
    j = ft_printf("| %.10d |\n", LONG_MAX);
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");

    i = printf("| %.100d |\n", LONG_MAX);
    j = ft_printf("| %.100d |\n", LONG_MAX);
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");

    i = printf("| %.8d |\n", LONG_MAX);
    j = ft_printf("| %.8d |\n", LONG_MAX);
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");

    i = printf("|% 10d|\n", 255);
    j = ft_printf("|% 10d|\n", 255);
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");

    i = printf("|%m|\n");
    j = ft_printf("|%m|\n");
    printf("i = %d && j = %d\n", i, j);
    printf("------------------------------------------------\n");

    return 0;

}
