#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>

static void prclass(const char *name, int (*fn)(int))
{
    int c;

    fputs(name, stdout);
    fputs(": ", stdout);
    for (c = EOF; c <= UCHAR_MAX; ++c)
        if ((*fn)(c))
            fputc(c, stdout);
    fputs("\n", stdout);
}

int main()
{
    char *s;
    int c;

    prclass("ispunct", &ispunct);
    prclass("isdigit", &isdigit);
    prclass("islower", &islower);
    prclass("isupeer", &isupper);
    prclass("isalpha", &isalpha);
    prclass("isalnum", &isalnum);

    for (s = "0123456789"; *s; ++s)
        assert(isdigit(*s) && isxdigit(*s));
    for (s = "abcdefABCDEF"; *s; ++s)
        assert(isxdigit(*s));
    for (s = "abcdefghijklmnopqrstuvwxyz"; *s; ++s)
        assert(islower(*s));
    for (s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; *s; ++s)
        assert(isupper(*s));
    for (s = "!\"#%&'();<=>?[\\]*+,-./:^_{|}~"; *s; ++s)
        assert(ispunct(*s));
    for (s = "\f\n\r\t\v"; *s; ++s)
        assert(isspace(*s) && iscntrl(*s));
    assert(isspace(' ') && isprint(' '));
    assert(iscntrl('\a') && iscntrl('\b'));

    puts("SUCCESS testing <ctype.h> marco part\n");
    return 0;
}
