#include <stdio.h>

#define MAX_CHARS 256   /* max of different chars: going with ASCII */

/* print a histogram of the lengths of words in its input */
int main() {
    int i, c;
    int nchar[MAX_CHARS];
    
    for (i = 0; i < MAX_CHARS; ++i)
        nchar[i] = 0;

    while ((c = getchar()) != EOF) {
        ++nchar[c];
    }

    for (i = 0; i < MAX_CHARS; ++i) {
        if (nchar[i] > 0) {
            printf("'%c':\t", i);
            while (nchar[i] > 0) {
                printf("*");
                --nchar[i];
            }
            printf("\n");
        }
    }
}
