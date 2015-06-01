/*
 * Ex 2-1:
 * Write a program to determine the ranges of char, short, int, and
 * long variables, both signed and unsigned, by printing appropriate
 * values from standard headers and by direct computation. Harder if
 * you compute them: determine the ranges of the various floating-
 * point types.
 */

#include <stdio.h>
#include <limits.h>

int main()
{
    printf("From <limits.h>\n");
    printf("signed char: %d\nunsigned char: %u\n", CHAR_MAX, UCHAR_MAX);
    printf("signed short: %d\nunsigned short: %u\n", SHRT_MAX, USHRT_MAX);
    printf("signed int: %i\nunsigned int: %u\n", INT_MAX, UINT_MAX);
    printf("signed long: %ld\nunsigned long: %lu\n", LONG_MAX, ULONG_MAX);

    return 0;
}
