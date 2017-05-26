#include <stdio.h>

int fib[100000];



int main(void)
{
    int i;
    int glob_max;
    int case_num;
    int num;
    fib[0] = 1;
    fib[1] = 2;
    for (i = 2;; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] > 100000000)
            break;
    }
    glob_max = i;
    scanf("%d", &case_num);
    while (case_num--) {
        int max;
        scanf("%d", &num);
        printf("%d = ", num);
        for (i = 0; i < glob_max; i++) {
            if (fib[i] > num)
                break;
        }
        max = i - 1;
        for (i = max; i >= 0; i--) {
            if (num >= fib[i]) {
                printf("1");
                num -= fib[i];
            } else {
                printf("0");
            }
        }
        printf(" (fib)\n");
    }
    return 0;
}
