#include <stdio.h>

int main(void)
{
    int num;
    while (scanf("%d", &num) == 1 && num != 0) {
        while (num >= 10) {
            int total = 0;
            while (num != 0) {
                total += num % 10;
                num /= 10;
            }
            num = total;
        }
        printf("%d\n", num);
    }
    return 0;
}
