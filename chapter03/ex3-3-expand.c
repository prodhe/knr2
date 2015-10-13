/*
 * Ex 3-3:
 * Write a function expand(s1,s2) that expands shorthand notations like
 * a-z in the string s1 into the equivalt complete list abc..xyz in s2.
 * Allow for letters of either case and digits, and be prepared to handle
 * cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing
 * - is taken literally.
 */

#include <stdio.h>
#include <ctype.h>  // isalnum

#define MAXSIZE 512

int expand(char s1[], char s2[])
{
    int c, i, j;

    for (i=0, j=0; s1[i] != '\0'; i++) {
        s2[j++] = s1[i];
        if (s1[i] == '-' && isalnum(s1[i-1]) && isalnum(s1[i+1]))
            for (c = s1[i-1]+1, j--; c < s1[i+1]; c++, j++)
                s2[j] = c;
    }
    s2[j] = '\0';
    return j;
}

int main()
{
    char buf[MAXSIZE], result[MAXSIZE];
    int i, c;

    for (i=0; (c = getchar()) != EOF; i++)
        buf[i] = c;
    buf[i] = '\0';

    if (expand(buf, result) > 0)
        printf("%s\n%s\n", buf, result);

    return 0;
}
