#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int getline_(char line[], int maxline);
void stripline(char line[], int maxline);

/* remove trailing blanks and tabs from each line
 * of input and delete entirely blank lines
 *
 * write to stdout */
int main() {
    int len;        /* current line length */
    int row;       /* current row */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    row = 1;
    while ((len = getline_(line, MAXLINE)) > 0) {
        if (len > 1) {
            if (len > MAXLINE) {
                printf("---ERROR reading line %d---", row);
            } else {
                stripline(line, MAXLINE);
                printf("%s", line);
            }
        }
        ++row;
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline_(char s[], int lim) {
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* stripline: removes trailing blanks and tabs */
void stripline(char s[], int lim) {
    int i;

    for (i = 0; i < lim-1 && s[i] != '\0'; ++i)
        ;
    while (i > 0 && (s[i] == '\0' || s[i] == '\n'
                 || s[i] == '\t' || s[i] == ' '))
        --i;
    s[i+1] = '\n';
    s[i+2] = '\0';
}
