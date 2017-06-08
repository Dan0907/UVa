#include <stdio.h>


char matrix[100][100];
int main(void)
{
    int case_num;
    int m, n, q;
    scanf("%d", &case_num);
    while (case_num--) {
        int i, j;
        int k;
        int x, y;
        scanf("%d%d%d", &m, &n, &q);
        printf("%d %d %d\n", m, n, q);
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                scanf(" %c", matrix[i] + j);
            }
        }
        for (k = 0; k < q; k++) {
            int count = 3;
            int z;
            char c;
            int flag = 1;
            scanf("%d%d", &x, &y);
            c = matrix[x][y];
            while (1) {
                i = x - count / 2;
                j = y - count / 2;
                if (i < 0 || j < 0) {
                    break;
                }
                for (z = 0; z < count; z++) {
                    if (j > n - 1 || matrix[i][j] != c) {
                        flag = 0;
                        break;
                    }
                    j++;
                }
                j--;
                for (z = 1; z < count; z++) {
                    i++;
                    if (i > m - 1 || matrix[i][j] != c) {
                        flag = 0;
                        break;
                    }
                }
                for (z = 1; z < count; z++) {
                    j--;
                    if (matrix[i][j] != c) {
                        flag = 0;
                        break;
                    }
                }
                for (z = 1; z < count - 1; z++) {
                    i--;
                    if (matrix[i][j] != c) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0)
                    break;
                count += 2;
            }
            count -= 2;
            printf("%d\n", count);
        }
    }
    return 0;
}
