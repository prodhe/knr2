#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[]);
int getline_(char line[], int maxline);

/* reverse each line of input */
int main() {
    char line[MAXLINE];

    while ((getline_(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

/* reverse: reverse an entire string; assume 's' is null-terminated */
void reverse(char s[]) {
    char tmp;
    int i, j;

    for (i = 0; s[i] != '\0'; ++i)
        ;
    --i;
    if (s[i] == '\n')
        --i;

    j = 0;
    while (i > j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        --i;
        ++j;
    }
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

