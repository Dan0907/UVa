#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ans_flag[26];
int guess_flag[26];
char ans_str[100];
char guess_str[100];

int main(void)
{
    int round;
    int guess_count;
    int ans_count;
    int i;
    while (scanf("%d", &round) && round != -1) {
        memset(ans_flag, 0, sizeof(int) * 26);
        memset(guess_flag, 0, sizeof(int) * 26);
        scanf("%s%s", ans_str, guess_str);
        guess_count = 7;
        ans_count = 0;
        i = 0;
        while (ans_str[i]) {
            int target = ans_str[i] - 'a';
            if (ans_flag[target] == 0) {
                ans_flag[target] = 1;
                ans_count++;
            }
            i++;
        }
        i = 0;
        while (guess_str[i] && ans_count != 0 && guess_count != 0) {
            int target = guess_str[i] - 'a';
            if (guess_flag[target] == 0) {
                guess_flag[target] = 1;
                if (ans_flag[target] == 1)
                    ans_count--;
                else
                    guess_count--;
            }
            i++;
        }
        printf("Round %d\n", round);
        if (ans_count == 0)
            printf("You win.\n");
        else if (guess_count == 0)
            printf("You lose.\n");
        else
            printf("You chickened out.\n");
    }
    return 0;
}
