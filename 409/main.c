#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char key_arr[21][22];
char sen_arr[21][72];
int count[21];
char str[50];

char is_alph(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else if (c == '\0')
        return -1;
    else
        return 0;
}

char my_strncmp(char *a, char *b, int num)
{
    int i = 0;
    char flag = 0;
    while (i < num) {
        if (*(a + i) == 0 || *(b + i) == 0 || tolower(*(a + i)) != tolower(*(b + i))) {
            flag = 1;
            break;
        }
        i++;
    }
    return flag;
}


int main(void)
{
    int k, e;
    int round;
    for (round = 1; fgets(str, 50, stdin); round++) {
        int i, j;
        int max_num = 0;
        sscanf(str, "%d%d", &k, &e);
        for (i = 0; i < k; i++) {
            fgets(key_arr[i], 22, stdin);
            key_arr[i][strlen(key_arr[i]) - 1] = 0;
        }
        for (i = 0; i < e; i++)
            fgets(sen_arr[i], 72, stdin);
        memset(count, 0, sizeof(int) * 21);
        for (i = 0; i < e; i++) {
            for (j = 0; j < k; j++) {
                char *temp;
                for (temp = sen_arr[i]; *temp != '\0';) {
                    while (!is_alph(*temp)) {
                        temp++;
                    }
                    if (my_strncmp(temp, key_arr[j], strlen(key_arr[j])) == 0
                        && is_alph(*(temp + strlen(key_arr[j]))) != 1)
                        count[i]++;
                    while (is_alph(*temp) == 1)
                        temp++;
                }
            }
            if (count[i] > max_num)
                max_num = count[i];
        }
        printf("Excuse Set #%d\n", round);
        for (i = 0; i < e; i++) {
            if (count[i] == max_num) {
                fputs(sen_arr[i], stdout);
            }
        }
        printf("\n");
    }
    return 0;
}
