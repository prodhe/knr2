/*
 * Ex 3-1:
 * Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with
 * only one test inside the loop and measure the difference in run-time.
 */

#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1;  /* no match */
}

/* binsearch2 */
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low+high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    
    if (x == v[low])
        return low; /* return position of match */
    else
        return -1;  /* no match */
}


int main()
{
    int foo[6] = {1,3,4,6,7,8};
    int s = 6;

    if (binsearch2(s, foo, 6) != -1)
        printf("found %i in foo\n", s);
    else
        printf("not found\n");
    
    return 0;
}
