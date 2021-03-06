#include <stdio.h>

#define MAXLINE 30    /* maximum input line size */

int getline_(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() {
    int len;        /* current line length */
    int max;        /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline_(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("%d: %s\n", max, longest);
    return 0;
}

/* getline: read a line into s, return length */
int getline_(char s[], int lim) {
    int c, i, j;

    j = 0;
    for (i=0; (c=getchar()) != EOF && c != '\n'; ++i)
        if (i < lim-1) {
            j = i;
            s[j] = c;
        }
    if (c == '\n') {
        ++i;
        s[j] = c;
        ++j;
    }
    s[j] = '\0';
    return i;
}

/* copy: copy 'from' into 'to': assume 'to' is big enough */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

