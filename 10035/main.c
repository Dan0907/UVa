#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;
    while (scanf("%d%d", &a, &b) && !(a == 0 && b == 0)) {
        int count = 0;
        int carry = 0;
        while (a != 0 || b != 0) {
            div_t result_a = div(a, 10);
            div_t result_b = div(b, 10);
            if (result_a.rem + result_b.rem + carry >= 10) {
                carry = 1;
                count++;
            } else {
                carry = 0;
            }
            a = result_a.quot;
            b = result_b.quot;
        }
        if (count == 0)
            printf("No carry operation.\n");
        else if (count == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", count);
    }
    return 0;
}
