#include <stdio.h>

#define CELSIUS     0
#define FAHRENHEIT  1

float convert_temp(float newtemp, int totemp);

int main() {
    float t;
    t = convert_temp(100, CELSIUS);
    printf("100 F > %f C > %f F\n", t, convert_temp(t, FAHRENHEIT));
    return 0;
}

float convert_temp(float temp, int to) {
    float newtemp;
    if (to == CELSIUS)
        newtemp = (5.0/9.0) * (temp-32.0);
    else if (to == FAHRENHEIT)
        newtemp = temp * (9.0/5.0) + 32.0;
    else
        newtemp = 0;
    return newtemp;
}
