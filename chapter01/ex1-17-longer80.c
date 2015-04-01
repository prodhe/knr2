#include <stdio.h>

#define MAXLINE 80    /* maximum input line size */

int getline_(char line[], int maxline);

/* print all lines longer than MAXLINE chars */
int main() {
    int len;        /* current line length */
    int row;       /* current row */
    char line[MAXLINE+1];     /* current input line */
    char longest[MAXLINE+1];  /* longest line saved here */

    printf("Lines longer than %d chars:\n", MAXLINE);
    row = 1;
    while ((len = getline_(line, MAXLINE)) > 0) {
        if (len > MAXLINE) {
            printf("%3d: %s\n", row, line);
        }
        ++row;
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline_(char s[], int lim) {
    int c, i, j;

    j = 0;
    for (i=0; (c=getchar()) != EOF && c != '\n'; ++i)
        if (i < lim) {
            j = i;
            s[j] = c;
        }
    if (c == '\n') {
        ++i;
    }
    s[j] = '\0';
    return i;
}

/* this line will be longer than 80 chars 'cause I will def make it so and now it's close */
