/*
 * Ex2-3:
 * Write the function htoi(s), which converts a string of hexadecimal
 * digits (including an optional 0x or 0X) into its equivalent integer
 * value. The allowable digits are 0 through 9, a through f and A
 * through F.
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 512

int htoi(char s[]);

int main()
{
    char input[BUFSIZE], c;
    int i;
    for(i=0; i < BUFSIZE && (c=getchar()) != '\n'; ++i)
        input[i] = c;
    input[i] = '\0';
    printf("%i\n", htoi(input));
    return 0;
}

/* htoi: convert hexadecimal string s to integer */
int htoi(char s[])
{
    char c;
    int i=0;
    int n=0;

    while ((c = s[i++]) != '\0') {
        n *= 16;
        //printf("%d: %c\n", c, c);
        if (c >= '0' && c <= '9')
            n += c - '0';
        else if (c >= 'a' && c <= 'f')
            n += 10 + (c-'a');
        else if (c >= 'A' && c <= 'F')
            n += 10 + (c-'A');
        else if (c == 'x')
            n = n;
        else
            return -1;
    }
    return n;
}
