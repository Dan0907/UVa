#include <stdio.h>

int digit[36];

int main(void)
{
    int case_num, i, base, c, n;
    scanf("%d", &case_num);
    for (c = 1; c <= case_num; c++) {
        printf("Case %d:\n", c);
        for (i = 0; i < 36; i++)
            scanf("%d", digit + i);
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            int num;
            int last;
            int cost[37] = {0};
            int min = 2147483647;
            scanf("%d", &num);
            for (base = 2; base <= 36; base++) {
                int temp = num;
                while (temp != 0) {
                    cost[base] += digit[temp % base];
                    temp /= base;
                }
                if (cost[base] <= min) {
                    min = cost[base];
                    last = base;
                }
            }
            printf("Cheapest base(s) for number %d: ", num);
            for (base = 2; base <= 36; base++) {
                if (cost[base] == min) {
                    if (base != last)
                        printf("%d ", base);
                    else
                        printf("%d\n", last);
                }
            }
        }
        if (c != case_num)
            printf("\n");
    }
    return 0;
}
