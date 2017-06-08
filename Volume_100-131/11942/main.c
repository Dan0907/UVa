#include <stdio.h>

int main(void)
{
    int case_num;
    int t;
    printf("Lumberjacks:\n");
    scanf("%d", &case_num);
    while (case_num--) {
        int i;
        int temp1, temp2;
        char flag = 1;
        scanf("%d%d", &temp1, &temp2);
        t = temp2 - temp1;
        temp1 = temp2;
        for (i = 2; i < 10; i++) {
            scanf("%d", &temp2);
            if ((temp2 - temp1) * t < 0)
                flag = 0;
            t = temp2 - temp1;
            temp1 = temp2;
        }
        if (flag)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return 0;
}
