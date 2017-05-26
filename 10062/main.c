#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    char ascii;
    int freq;
};
char str[1005];

int cmp(const void *a, const void *b)
{
    return ((struct data *)a)->freq - ((struct data *)b)->freq;
}

int cmp2(const void *a, const void *b)
{
    return ((struct data *)b)->ascii - ((struct data *)a)->ascii;
}

int main(void)
{
    struct data arr[256];
    int i;
    int first = 1;
    while (fgets(str, 1005, stdin) != NULL) {
        int n = strlen(str);
        int temp = 0;
        int current;
        if (first == 1) {
            first = 0;
        } else {
            printf("\n");
        }
        for (i = 0; i < 256; i++)
            arr[i].ascii = i;
        for (i = 0; i < 256; i++)
            arr[i].freq = 0;
        for (i = 0; i < n; i++) {
            if (str[i] != '\n' && str[i] != '\r')
                arr[str[i]].freq++;
        }
        qsort(arr, 256, sizeof(struct data), cmp);
        current = arr[0].freq;
        for (i = 1; i < 256; i++) {
            if (arr[i].freq != current) {
                qsort(arr + temp, i - temp, sizeof(struct data), cmp2);
                current = arr[i].freq;
                temp = i;
            }
        }
        qsort(arr + temp, i - temp, sizeof(struct data), cmp2);
        for (i = 0; i < 256; i++) {
            if (arr[i].freq != 0) {
                printf("%d %d\n", arr[i].ascii, arr[i].freq);
            }
        }
    }
    return 0;
}
