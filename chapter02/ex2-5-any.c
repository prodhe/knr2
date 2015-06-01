/*
 * Ex2-5:
 * Write the function any(s1,s2), which returns the first location
 * in the string s1 where any character from the string s2 occurs,
 * or -1 if s1 contains no characters from s2.
 */

#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    int location;

    char str[] = "the quick brown fox jumps over lazy dog";
    char find[] = "any";
    if ((location = any(str, find)) > 0)
        printf("found one of \"%s\" in location %i (zero-indexed):\n%s\n",
                find, location, str);
    else
        printf("%s not found\n", find);
    return 0;
}

/* any: returns the first location of any char from s2 found in s1
 * returns -1 if none found */
int any(char s1[], char s2[])
{
    int i, j;
    
    for (i=0; s1[i] != '\0'; ++i)
        for(j=0; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j])
                return i;
    
    return -1;
}
