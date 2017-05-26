#include <stdio.h>

int main(void)
{
    int case_num;
    int i;
    scanf("%d", &case_num);
    for (i = 1; i <= case_num; i++) {
        int j;
        int num;
        int temp;
        int now;
        int high = 0;
        int low = 0;
        scanf("%d", &num);
        scanf("%d", &temp);
        if (num == 1) {
            printf("Case %d: 0 0\n", i);
            continue;
        }
        for (j = 1; j < num; j++) {
            scanf("%d", &now);
            if (now - temp > 0)
                high++;
            else if (now - temp < 0)
                low++;
            temp = now;
        }
        printf("Case %d: %d %d\n", i, high, low);
    }
    return 0;
}
