#include <stdio.h>

#define MAX_WORDS 1000
#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

/* print a histogram of the lengths of words in its input */
int main() {
    int i, wc, c, state;
    int word[MAX_WORDS];
    
    state = OUT;
    wc = 0;

    for (i = 0; i < MAX_WORDS; ++i)
        word[i] = 0;

    while ((c = getchar()) != EOF) {
       if (c == ' ' || c == '\t' || c == '\n') {
           if (state == IN)
               ++wc;
           state = OUT;
       } else {
           state = IN;
           ++word[wc];
       } 
    }

    for (i = 0; i < wc; ++i) {
        printf("%3d: ", i);
        while (word[i] > 0) {
            printf("*");
            --word[i];
        }
        printf("\n");
    }
}
