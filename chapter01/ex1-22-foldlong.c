/*
 * Ex1-22:
 * Write a program to 'fold' long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>
#define BUFSIZE 1000
#define INSIDE 1        /* inside a word */
#define OUTSIDE 0       /* outside a word */

int breakline(char line[], int lim, int colstop);
void copystr(char from[], char to[], int len);
void addchar(char c, char dest[]);
int lenstr(char str[]);

int main(void) {
    int len, column;
    char line[BUFSIZE];

    column = 80;
    while ((len = breakline(line, BUFSIZE, column)) > 0)
        //printf("%s", line);
        ;

    return 0;
}

/* breakline: read a line from stdin and insert \n between words near
 * every given col */
int breakline(char s[], int lim, int colstop) {
    int i, c, col, word_state;
    char word[BUFSIZE];

    col = 0;
    word_state = OUTSIDE;
    word[0] = '\0';

    for (i=0; i < lim && (c=getchar()) != EOF && c != '\n'; ++i) {
        ++col;

        if (c == ' ' || c == '\t')
            word_state = OUTSIDE;
        else
            word_state = INSIDE;

        if (word_state == INSIDE) {
            addchar(c, word);
        } else if (word_state == OUTSIDE) {
            int lenw = lenstr(word);
            printf("%d", lenw);
            if (lenw > 0) {
                printf("%s\n", word);
                //copystr(word, &s[i-lenw], lenw);
                word[0] = '\0';
            }
            s[i] = c;

            /*
            if (col > colstop) {
                ++i;
                s[i] = '\n';
                col = 0;
            }
            */
        }
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* ugly version of string copy */
void copystr(char from[], char to[], int len) {
    int i;
    i = 0;
    while (len > 0 && (to[i] = from[i]) != '\0') {
        --len;
        ++i;
    }
}

/* add char to str */
void addchar(char c, char dest[]) {
    int i;
    i = 0;
    while (dest[i] != '\0')
        ++i;
    dest[i] = c;
    dest[i+1] = '\0';
}

/* count string length */
int lenstr(char s[]) {
    int i;
    i = 0;
    while(s[i] != '\0')
        ++i;
    return i;
}
