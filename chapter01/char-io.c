#include <stdio.h>

/* copy input to output */
int main() {
    printf("EOF is: %d\n", EOF);

    printf("(getchar() != EOF: %d\n", (getchar() != EOF));

    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
    /*
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
    */
}
