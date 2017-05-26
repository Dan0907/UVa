#include <stdio.h>
#include <string.h>

typedef char bool;


char str[1000];

bool is_alph(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}
int main(void)
{
    while (fgets(str, 1000, stdin) != NULL) {
        int i;
        int len = strlen(str);
        int count = 0;
        bool pre_alph = 0;
        for (i = 0; i < len; i++) {
            if (is_alph(str[i])) {
                if (pre_alph == 0)
                    count++;
                pre_alph = 1;
            } else {
                pre_alph = 0;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
