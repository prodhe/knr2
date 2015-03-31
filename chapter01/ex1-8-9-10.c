#include <stdio.h>

/* ex1-8: count blanks, tabs and newlines
int main() {
    long nc;
    int c;

    nc = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
            ++nc;
    printf("%ld\n", nc);
}
*/

/* ex1-9: copy input to output, replace each string of
 * one or more blanks by a single blank
int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            while ((c = getchar()) == ' ')
                ;
            printf(" %c", c);
        } else {
            printf("%c", c);
        }
    }
}
*/

/* ex1-10: copy input to output, replace each tab by \t,
 * each backspace by \b and each backslash by \\ */
int main() {
    int c;

    while ((c = getchar()) != EOF)
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            printf("%c", c);
}
