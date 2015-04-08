/*
 * Exercise 1-21:
 * Write a program 'entab' that replaces strings of blanks by the
 * minumum number of tabs and blanks to achieve the same spacing. Use the
 * same tab stops as for detab. When either a tab or single blank would suffice
 * to reach a tab stop, which should be given preference?
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
#define SPACE 1
#define NOSPACE 0

int entab_line(char s[], int lim, int tabstop);

/* main: entab - turn a proper amount of spaces into tabs and spaces */
int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int len, tabstop;

    if (argc > 1)
        tabstop = atoi(argv[1]);
    else
        tabstop = 8;

    while ((len = entab_line(line, MAXLINE, tabstop)) > 0)
        printf("%s", line);

    return 0;
}

/* entab_line: read a line into s, maybe insert tabs and return length */
int entab_line(char s[], int lim, int tabstop) {
    int c, i, blank_count, state;

    blank_count = 0;
    state = NOSPACE;
    for (i=0; i < lim-tabstop-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        if (c == ' ') {
            state = SPACE; 
            ++blank_count;
            --i;
        } else {
            if (state == SPACE)
                while (blank_count > 0) {
                    if (blank_count / tabstop > 0) {
                        s[i] = '\t';
                        blank_count -= tabstop;
                        ++i;
                    } else if (blank_count % tabstop > 0) {
                        s[i] = ' ';
                        ++i;
                        --blank_count;
                    }
                }
            state = NOSPACE;
            s[i] = c;
        }
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
