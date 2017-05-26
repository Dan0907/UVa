#include <stdio.h>
#include <string.h>

char up_alph[26];
char low_alph[26];
char str[1000];

char is_up_alph(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

char is_low_alph(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    else
        return 0;
}

int main(void)
{
    while (fgets(str, 1000, stdin) != NULL) {
        int len = strlen(str);
        int i;
        int max = 0;
        str[len - 1] = 0;
        memset(up_alph, 0, 26);
        memset(low_alph, 0, 26);
        for (i = 0; i < len; i++) {
            if (is_up_alph(str[i])) {
                if (++up_alph[str[i] - 'A'] > max)
                    max = up_alph[str[i] - 'A'];
            } else if (is_low_alph(str[i])) {
                if (++low_alph[str[i] - 'a'] > max)
                    max = low_alph[str[i] - 'a'];
            }
        }
        for (i = 0; i < 26; i++)
            if (up_alph[i] == max)
                printf("%c", i + 'A');
        for (i = 0; i < 26; i++)
            if (low_alph[i] == max)
                printf("%c", i + 'a');
        printf(" %d\n",max);
    }
    return 0;
}
