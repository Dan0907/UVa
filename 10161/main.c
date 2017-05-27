#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    int temp;
    int start;
    int x, y;
    int r;
    while (scanf("%d", &n) && n != 0) {
        temp = pow(n, 0.5);
        if (temp % 2 == 0) {
            x = temp;
            y = 1;
            start = temp * temp;
            r = n - start;
            if (r == 1) {
                x = temp + 1;
            } else if (r != 0 && r <= temp + 1) {
                x = temp + 1;
                y = r;
            } else if (r > temp + 1) {
                y = temp + 1;
                x = (temp + 1) * 2 - r;
            }

        } else {
            x = 1;
            y = temp;
            start = temp * temp;
            r = n - start;
            if (r == 1) {
                y = temp + 1;
            } else if (r != 0 && r <= temp + 1) {
                y = temp + 1;
                x = r;
            } else if (r > temp + 1) {
                x = temp + 1;
                y = (temp + 1) * 2 - r;
            }
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}
