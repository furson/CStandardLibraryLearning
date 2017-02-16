#include <stdio.h>

struct x
{
    int x;
};

int x(int);

int main()
{
        goto x;
end:    return 0;
}

x:  ((struct x *)x) -> x = x(5);
    goto end;

int x(int num)
{
    return num;
}
