#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num[10][7] = {
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};

char n[11];

int main(void)
{
    int s;
    int k;
    while (scanf("%d%s", &s, n) && !(s == 0 && atoi(n) == 0)) {
        int i;
        int len = strlen(n);
        for (i = 0; i < len; i++) {
            int j;
            if (num[n[i] - '0'][0]) {
                printf(" ");
                for (j = 0; j < s; j++)
                    printf("-");
                printf(" ");
            } else {
                for (j = 0; j <= s + 1; j++)
                    printf(" ");
            }
            if (i != len - 1)
                printf(" ");
        }
        printf("\n");

        for (k = 0; k < s; k++) {
            for (i = 0; i < len; i++) {
                int j;
                if (num[n[i] - '0'][1])
                    printf("|");
                else
                    printf(" ");

                for (j = 0; j < s; j++)
                    printf(" ");

                if (num[n[i] - '0'][2])
                    printf("|");
                else
                    printf(" ");
                
                if (i != len - 1)
                    printf(" ");
            }
            printf("\n");
        }

        for (i = 0; i < len; i++) {
            int j;
            if (num[n[i] - '0'][3]) {
                printf(" ");
                for (j = 0; j < s; j++)
                    printf("-");
                printf(" ");
            } else {
                for (j = 0; j <= s + 1; j++)
                    printf(" ");
            }
            if (i != len - 1)
                printf(" ");
        }
        printf("\n");

        for (k = 0; k < s; k++) {
            for (i = 0; i < len; i++) {
                int j;
                if (num[n[i] - '0'][4])
                    printf("|");
                else
                    printf(" ");

                for (j = 0; j < s; j++)
                    printf(" ");

                if (num[n[i] - '0'][5])
                    printf("|");
                else
                    printf(" ");

                if (i != len - 1)
                    printf(" ");
            }
            printf("\n");
        }

        for (i = 0; i < len; i++) {
            int j;
            if (num[n[i] - '0'][6]) {
                printf(" ");
                for (j = 0; j < s; j++)
                    printf("-");
                printf(" ");
            } else {
                for (j = 0; j <= s + 1; j++)
                    printf(" ");
            }
            if (i != len - 1)
                printf(" ");
        }
        printf("\n\n");
    }
    return 0;
}
