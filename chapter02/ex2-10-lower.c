/*
 * Ex: 2-10
 *
 * Rewrite the function lower, which converts upper case letters
 * to lower case, with a conditional expression instead of if-else.
 *
 */

#import <stdio.h>

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A': c;
}

int main()
{
    char c = 'P';
    printf("%c -> %c\n", c, lower(c));
    return 0;
}

