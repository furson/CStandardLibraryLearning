#include <stdio.h>

int main()
{
    double a[] = {1.0, 2.0};
    double *p = a;
    double sqr(double x) {return x * x;}
    #define sqr(x) x * x

    printf("%lf\n", sqr(3.0));
    printf("%d\n", sqr(3));
    printf("%d\n", sqr(3+3));
    printf("%d\n", !sqr(3));
    printf("%lf\n", sqr(*p++));
    printf("%lf\n", (sqr)(3+3));

    return 0;
}
