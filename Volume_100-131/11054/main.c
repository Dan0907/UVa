#include <stdio.h>

int main(void)
{
    int num;
    while (scanf("%d", &num) && num != 0) {
        int i;
        int acc = 0;
        long int count = 0;
        for (i = 0; i < num; i++) {
            int temp;
            scanf("%d", &temp);
            acc += temp;
            count += (acc >= 0) ? (long int)acc : (long int)(-acc);
        }
        printf("%ld\n", count);
    }
    return 0;
}
