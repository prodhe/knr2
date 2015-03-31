#include <stdio.h>

void fahr2cels();
void cels2fahr();

int main() {
    printf("Fahrenheit to Celsius:\n");
    fahr2cels();
    printf("\nCelsius to Fahrenheit:\n");
    cels2fahr();

    printf("Fahrenheit to Celsius (using for and in reverse):\n");
    int fahr;
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, ((fahr - 32.0) / 1.8));

}

void fahr2cels() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size in fahrenheit */

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

void cels2fahr() {
    float fahr, celsius;
    int lower, upper, step;

    lower = -17;      /* lower limit of table */
    upper = 150;    /* upper limit */
    step = 11;      /* step size in celsius */

    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * (9.0/5.0) + 32.0;
        printf("%6.1f %3.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
