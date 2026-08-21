#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int r_ft;
    int r_lc;

    // Part 1: Basic Specifiers (c, s, p, %)
    printf("--- Specifier: %%c ---\n");
    r_ft = ft_printf("ft   = [%c]\n", 'A');
    r_lc = printf("libc = [%c]\n", 'A');
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Specifier: %%s ---\n");
    r_ft = ft_printf("ft   = [%s]\n", "42BornToCode");
    r_lc = printf("libc = [%s]\n", "42BornToCode");
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Specifier: %%p ---\n");
    int n = 42;
    r_ft = ft_printf("ft   = [%p]\n", &n);
    r_lc = printf("libc = [%p]\n", &n);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Specifier: %%%% ---\n");
    r_ft = ft_printf("ft   = [%%%%]\n");
    r_lc = printf("libc = [%%%%]\n");
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);


    // Part 2: Number Specifiers (d, i, u, x, X)
    printf("--- Specifiers: %%d and %%i ---\n");
    r_ft = ft_printf("ft   = [%d] [%i]\n", INT_MIN, 12345);
    r_lc = printf("libc = [%d] [%i]\n", INT_MIN, 12345);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Specifier: %%u ---\n");
    r_ft = ft_printf("ft   = [%u]\n", UINT_MAX);
    r_lc = printf("libc = [%u]\n", UINT_MAX);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Specifiers: %%x and %%X ---\n");
    r_ft = ft_printf("ft   = [%x] [%X]\n", 255, 255);
    r_lc = printf("libc = [%x] [%X]\n", 255, 255);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

/*
    // Part 3: Width & Precision Flags
    printf("--- Width & Precision ---\n");
    r_ft = ft_printf("ft   = [%10.5d] [%-10.5s]\n", 42, "42");
    r_lc = printf("libc = [%10.5d] [%-10.5s]\n", 42, "42");
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);


    // Part 4: Flags (- + 0 # space)
    printf("--- Flags: minus (-) and zero (0) ---\n");
    r_ft = ft_printf("ft   = [%05d] [%-5d]\n", 42, 42);
    r_lc = printf("libc = [%05d] [%-5d]\n", 42, 42);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Flags: plus (+) and space ( ) ---\n");
    r_ft = ft_printf("ft   = [%+d] [% d]\n", 42, 42);
    r_lc = printf("libc = [%+d] [% d]\n", 42, 42);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Flag: hash (#) ---\n");
    r_ft = ft_printf("ft   = [%#x] [%#X]\n", 42, 42);
    r_lc = printf("libc = [%#x] [%#X]\n", 42, 42);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    return (0);*/
}
