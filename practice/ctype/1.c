#include <ctype.h>
#include <stdio.h>

#define LENGTH 14

int main()
{
    int i;
    char s[LENGTH] = "Hello,world!\n";

    for (i = 0; i < LENGTH; ++i)
        if (!isprint(s[i]))
            break;

    if (i != LENGTH)
        printf("isprint wrong for %d.\n", i);
    else
        printf("isprint correct.\n");

    for (i = 0; i < LENGTH; ++i)
        if (isgraph(s[i]))
            break;

    if (i != LENGTH)
        printf("isgraph wrong for %d.\n", i);
    else
        printf("isgraph correct.\n");

    for (i = 0; i < LENGTH; ++i)
        if(ispunct(s[i]))
            break;
    if (i != LENGTH)
        printf("ispunct wrong for %d.\n", i);
    else
        printf("ispunct correct.\n");

    return 0;
}
