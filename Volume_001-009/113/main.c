#include <stdio.h>
#include <math.h>

int main(void)
{
    double n;
    double p;
    while (scanf("%lf%lf", &n, &p) != EOF)
        printf("%.0f\n", pow(p, 1 / n));
    return 0;
}
