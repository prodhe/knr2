/*
 * Ex2-4:
 * Write an alternate version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in the string s2.
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char str[] = "the quick brown fox jumps over lazy dog";
    char remove[] = "apple";
    printf("%s\n", str);
    squeeze(str, remove);
    printf("%s\n", str);
    return 0;
}

/* squeeze: removes any character in null-terminated s1 found in s2 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int found;

    i = 0;
    k = 0;
    while (s1[i] != '\0') {
        found = 0;
        for (j=0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j])
                found = 1;
        }
        if (!found)
            s1[k++] = s1[i];
        ++i;
    }
    s1[k] = '\0';
}
