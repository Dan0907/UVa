#include <stdio.h>
#include <stdlib.h>

int n_arr[10001];
int q_arr[10001];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int n, q;
    int i;
    int round = 1;
    while (scanf("%d%d", &n, &q) && !(n == 0 && q == 0)) {
        printf("CASE# %d:\n", round++);
        for (i = 0; i < n; i++)
            scanf("%d", n_arr + i);
        for (i = 0; i < q; i++)
            scanf("%d", q_arr + i);
        qsort(n_arr, n, sizeof(int), cmp);
        for (i = 0; i < q; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (q_arr[i] == n_arr[j])
                    break;
            }
            if (j != n)
                printf("%d found at %d\n", q_arr[i], j + 1);
            else
                printf("%d not found\n", q_arr[i]);
        }
    }
    return 0;
}
