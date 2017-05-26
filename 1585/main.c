#include <stdio.h>

char str[100];
int main(void)
{
    int round;
    int i;
    scanf("%d", &round);
    while (round--) {
        int correct = 0;
        int sum = 0;
        scanf("%s", str);
        for (i = 0; str[i]; i++) {
            if (str[i] == 'O') {
                sum += (++correct);
            } else {
                correct = 0;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
