#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int r_ft;
    int r_lc;
    
    // Part 1: NULL and Edge Case Pointers / Strings
    printf("--- Edge Case: NULL String (s) ---\n");
    char *null_str = NULL;
    r_ft = ft_printf("ft   = [%s] [%.3s] [%10s]\n", null_str, null_str, null_str);
    r_lc = printf("libc = [%s] [%.3s] [%10s]\n", null_str, null_str, null_str);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Edge Case: NULL Pointer (p) ---\n");
    r_ft = ft_printf("ft   = [%p] [%20p] [%-20p]\n", NULL, NULL, NULL);
    r_lc = printf("libc = [%p] [%20p] [%-20p]\n", NULL, NULL, NULL);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Edge Case: Null Character (c) ---\n");
    r_ft = ft_printf("ft   = [%c] [%5c] [%-5c]\n", '\0', '\0', '\0');
    r_lc = printf("libc = [%c] [%5c] [%-5c]\n", '\0', '\0', '\0');
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);


    // Part 2: Number Limits and Sign Flipping
    printf("--- Edge Case: Signed Integer Limits (d/i) ---\n");
    r_ft = ft_printf("ft   = [%d] [%i]\n", INT_MAX, INT_MIN);
    r_lc = printf("libc = [%d] [%i]\n", INT_MAX, INT_MIN);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Edge Case: Unsigned Limits (u) ---\n");
    r_ft = ft_printf("ft   = [%u] [%u]\n", 0, UINT_MAX);
    r_lc = printf("libc = [%u] [%u]\n", 0, UINT_MAX);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);


    // --- SILENCE FORMAT WARNINGS FOR TESTING CONFLICTS ---
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wformat"
    #pragma GCC diagnostic ignored "-Wformat-extra-args"

    // Part 3: Flag Conflicts and Precision Overrides
    printf("--- Flag Interaction: Precision overrides Zero (0.) ---\n");
    r_ft = ft_printf("ft   = [%010.5d] [%08.3x]\n", 42, 42);
    r_lc = printf("libc = [%010.5d] [%08.3x]\n", 42, 42);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Flag Interaction: Minus overrides Zero (-0) ---\n");
    r_ft = ft_printf("ft   = [%-010d]\n", 42);
    r_lc = printf("libc = [%-010d]\n", 42);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    printf("--- Flag Interaction: Plus overrides Space (+ ) ---\n");
    r_ft = ft_printf("ft   = [%+ d] [% +d]\n", 42, 42);
    r_lc = printf("libc = [%+ d] [% +d]\n", 42, 42);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);

    // --- RESTORE WARNING SETTINGS ---
    #pragma GCC diagnostic pop


    printf("--- Flag Interaction: Hash on Zero Value (# with 0) ---\n");
    r_ft = ft_printf("ft   = [%#x] [%#X]\n", 0, 0);
    r_lc = printf("libc = [%#x] [%#X]\n", 0, 0);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);


    // Part 4: Precision Truncation on Zero Values
    printf("--- Edge Case: Value 0 with Precision 0 (.0) ---\n");
    r_ft = ft_printf("ft   = [%.0d] [%.d] [%5.0x]\n", 0, 0, 0);
    r_lc = printf("libc = [%.0d] [%.d] [%5.0x]\n", 0, 0, 0);
    printf("ret  = ft: %d | libc: %d\n\n", r_ft, r_lc);
}
