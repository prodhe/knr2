/*
 * Ex2-2:
 * Write a loop equivalent to the for loop above without using
 * && or ||.
 *
 * The for loop:
 *
 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; i++)
 *     s[i] = c;
 */

#include <stdio.h>

#define LIMIT 512 /* max chars on line */

/* getline without for loop */
int main()
{
    int i;
    int c;
    int lim;
    char s[LIMIT];

    i = 0;
    lim = LIMIT;
    while (i < lim-1) {
        c = getchar();
        if (c == '\n')
            lim = 0;
        else if (c == EOF)
            lim = 0;
        else
            s[i++] = c;
    }
    s[i] = '\0';
    printf("%s\n", s);
    return 0;
}
