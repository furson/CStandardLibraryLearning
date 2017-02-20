#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t idlen(const char *);

int main()
{
    //test
    const char *s = {"Furson123___ts\nrtrerer"};

    printf("The number of 's' led identifiers is %d\n", (int)idlen(s));
    return 0;
}

size_t idlen(const char *s)
{
    int i, j;
    size_t count = 0;

    for (i = 0; i < strlen(s); ++i)
        if (s[i] == 's')
        {
            for (j = 0; j < strlen(s); ++j)
                if (isalnum(s[j]) || s[j] == '_')
                    count++;
        }

    return count;
}
