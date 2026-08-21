#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int r_ft;
    int r_lc;
    
    // Part 1: NULL and Basic Pointer / String Testing
    printf("--- Mandatory Edge Case: NULL String (s) ---\n");
    char *null_str = NULL;
    r_ft = ft_printf("ft   = [%s]\n", null_str);
    r_lc = printf("libc = [%s]\n", null_str);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Mandatory Edge Case: NULL Pointer (p) ---\n");
    r_ft = ft_printf("ft   = [%p]\n", NULL);
    r_lc = printf("libc = [%p]\n", NULL);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Mandatory Edge Case: Null Character (c) ---\n");
    r_ft = ft_printf("ft   = [%c]\n", '\0');
    r_lc = printf("libc = [%c]\n", '\0');
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);


    // Part 2: Number Limits and Sign Testing
    printf("--- Mandatory Edge Case: Signed Integer Limits (d/i) ---\n");
    r_ft = ft_printf("ft   = [%d] [%i]\n", INT_MAX, INT_MIN);
    r_lc = printf("libc = [%d] [%i]\n", INT_MAX, INT_MIN);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Mandatory Edge Case: Unsigned Limits (u) ---\n");
    r_ft = ft_printf("ft   = [%u] [%u]\n", 0, UINT_MAX);
    r_lc = printf("libc = [%u] [%u]\n", 0, UINT_MAX);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);


    // Part 3: Hexadecimal Cases
    printf("--- Mandatory Edge Case: Hexadecimal Limits (x/X) ---\n");
    r_ft = ft_printf("ft   = [%x] [%X] [%x]\n", 0, 0, UINT_MAX);
    r_lc = printf("libc = [%x] [%X] [%x]\n", 0, 0, UINT_MAX);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);


    // Part 4: Percent Sign and String Blending
    printf("--- Mandatory Edge Case: Percent Sign and Text Mix (%%) ---\n");
    r_ft = ft_printf("ft   = [%%%%] [Hello %% standard %% s world]\n");
    r_lc = printf("libc = [%%%%] [Hello %% standard %% s world]\n");
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);
}

