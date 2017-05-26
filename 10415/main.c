#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool char

char str[205];
bool table[14][10] = {
    {0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {0, 1, 1, 1, 0, 0, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 1, 1, 1, 0},
    {1, 1, 1, 1, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 1, 0, 0, 1, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}
};

int trans(char c)
{
    switch (c) {
    case 'c':
        return 0;
    case 'd':
        return 1;
    case 'e':
        return 2;
    case 'f':
        return 3;
    case 'g':
        return 4;
    case 'a':
        return 5;
    case 'b':
        return 6;
    case 'C':
        return 7;
    case 'D':
        return 8;
    case 'E':
        return 9;
    case 'F':
        return 10;
    case 'G':
        return 11;
    case 'A':
        return 12;
    case 'B':
        return 13;
    }
    return -1;
}

int main(void)
{
    int case_num, i, j;
    fgets(str, 10, stdin);
    case_num = atoi(str);
    while (case_num--) {
        int count[10] = {0};
        bool init[10] = {0};
        bool *temp = init;
        bool *current;
        int len;
        fgets(str, 205, stdin);
        str[strcspn(str, "\n")] = 0;
        len = strlen(str);
        for (i = 0; i < len; i++) {
            current = table[trans(str[i])];
            for (j = 0; j < 10; j++) {
                if (current[j] == 1 && temp[j] == 0)
                    count[j]++;
            }
            temp = current;
        }
        for (i = 0; i < 9; i++)
            printf("%d ", count[i]);
        printf("%d\n", count[9]);
    }
    return 0;
}
