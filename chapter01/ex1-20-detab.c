/*
 * Exercise 1-20:
 * Write a program 'detab' that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed
 * set of tab stops, say every <n> colums. Should <n> be a variable or a
 * symbolic parameter?
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int detab_line(char s[], int lim, int tabstop);

/* main: detab - turn every tab into proper number of blanks */
int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int len, rows, tabstop;

    if (argc > 0) {
        tabstop = atoi(argv[1]);
    } else {
        tabstop = 8;
    }

    rows = 0; 
    while ((len = detab_line(line, MAXLINE, tabstop)) > 0) {
        ++rows;
        printf("%s", line);
    }

    return 0;
}

/* getline: read a line into s, return length */
int detab_line(char s[], int lim, int tabstop) {
    int c, i;

    for (i=0; i < lim-tabstop-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        if (c == '\t') {
            s[i] = ' ';
            while ((i+1) % tabstop > 0) {
                ++i;
                s[i] = ' ';
            }
        } else {
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
