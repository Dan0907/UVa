#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int arr[1000];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int n, m, case_num = 1;
    while (scanf("%d", &n) && n != 0) {
        int i;
        int target;
        printf("Case %d:\n", case_num++);
        for (i = 0; i < n; i++) {
            scanf("%d", arr + i);
        }
        qsort(arr, n, sizeof(int), cmp);
        scanf("%d", &m);
        for (i = 0; i < m; i++) {
            int j, k;
            int diff = 2147483647;
            int close;
            scanf("%d", &target);
            j = 0;
            k = n - 1;
            while (j != k) {
                int temp = arr[j] + arr[k];
                if (temp < target) {
                    j++;
                } else if (temp > target) {
                    k--;
                } else {
                    close = temp;
                    break;
                }
                if (abs(temp - target) < diff) {
                    diff = abs(temp - target);
                    close = temp;
                }
            }
            printf("Closest sum to %d is %d.\n", target, close);
        }
    }
    return 0;
}


