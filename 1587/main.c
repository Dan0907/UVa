#include <stdio.h>

int box[6][2];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int i, j, k, l;
    int x, y;
    int temp;
    while (scanf("%d%d", &x, &y) != EOF) {
        int flag = 1;
        int is_on[6] = {0};
        if (x > y)
            swap(&x, &y);
        box[0][0] = x;
        box[0][1] = y;
        for (i = 1; i <= 5; i++) {
            scanf("%d%d", &x, &y);
            if (x > y)
                swap(&x, &y);
            box[i][0] = x;
            box[i][1] = y;
        }
        for (k = 0; k < 3; k++) {
            int in = 0;
            for (l = k + 1; l < 6; l++) {
                if (is_on[l])
                    continue;
                if (box[k][0] == box[l][0] && box[k][1] == box[l][1]) {
                    in = 1;
                    swap(&box[l][0], &box[k + 3][0]);
                    swap(&box[l][1], &box[k + 3][1]);
                    is_on[k + 3] = 1;
                }
            }
            if (in == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                if (box[0][i] == box[1][j]) {
                    x = i;
                    y = j;
                    goto end;
                }
            }
        }
    end:
        if (i == 2 && j == 2) {
            printf("IMPOSSIBLE\n");
        } else {
            int temp1, temp2;
            temp1 = box[0][1 - x];
            temp2 = box[1][1 - y];
            if (temp1 > temp2)
                swap(&temp1, &temp2);
            if (temp1 == box[2][0] && temp2 == box[2][1])
                printf("POSSIBLE\n");
            else
                printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
