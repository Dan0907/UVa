#include <stdio.h>

int main(void)
{
    int ori_a;
    int limit;
    int round = 1;
    while (scanf("%d%d", &ori_a, &limit) && ori_a > 0) {
        int count = 0;
        int a = ori_a;
        while (a <= limit) {
            long int temp;
            count++;
            if (a == 1)
                break;
            if (a % 2 == 0) {
                a = a / 2;
            } else {
                temp = a * 3L + 1;
                if (temp > 2147483647)
                    break;
                else
                    a = (int)temp;
            }
        }
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n",
               round, ori_a, limit, count);
        round++;
    }
    return 0;
}
