#include <stdio.h>

int dna[10];

char encode(int num)
{
    switch (num) {
    case 0:
        return ' ';
    case 1:
        return '.';
    case 2:
        return 'x';
    case 3:
        return 'W';
    default:
        return 0;
    }
}

void print_str(int *arr)
{
    int i;
    for (i = 0; i < 40; i++)
        printf("%c", encode(arr[i]));
    printf("\n");
}

int main(void)
{
    int case_num;
    int i;
    scanf("%d", &case_num);
    while (case_num--) {
        int bact_seq[40] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1
        };
        int temp_seq[40];
        for (i = 0; i < 10; i++)
            scanf("%d", dna + i);
        print_str(bact_seq);
        for (i = 2; i <= 50; i++) {
            int j;

            temp_seq[0] = dna[bact_seq[0] + bact_seq[1]];
            for (j = 1; j < 39; j++)
                temp_seq[j] = dna[bact_seq[j - 1] + bact_seq[j]
                                  + bact_seq[j + 1]];
            temp_seq[39] = dna[bact_seq[38] + bact_seq[39]];

            for (j = 0; j < 40; j++)
                bact_seq[j] = temp_seq[j];
            print_str(bact_seq);
        }
        if (case_num != 0)
            printf("\n");
    }
    return 0;
}
