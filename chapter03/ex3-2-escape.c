/*
 * Ex 3-2:
 * Write a function escape(s,t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t as it copies the
 * string t to s. Use a switch. Write a function for the other direction as
 * well, converting esacape sequences into the real characters.
 */

#include <stdio.h>

#define MAXSIZE 8192

int escape(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (t[i] != '\0') {
        switch(t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        ++i;
    }
    s[j] = '\0';
    return j;
}

int unescape(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (t[i] != '\0') {
        switch(t[i]) {
            case '\\':
                if (t[i+1] == 'n') {
                    s[j++] = '\n';
                    ++i;
                } else if (t[i+1] == 't') {
                    s[j++] = '\t';
                    ++i;
                }
                break;
            default:
                s[j++] = t[i];
                break;
        }
        ++i;
    }
    s[j] = '\0';
    return j;
}

int main()
{
    char buf[MAXSIZE], str[MAXSIZE];
    int c, i;

    i = 0;
    while (((c = getchar()) != EOF) && i < MAXSIZE) {
        buf[i] = c;
        ++i;
    }
    buf[i] = '\0';
    unescape(str, buf);
    printf("%s\n", str);
    return 0;
}
