#include <stdio.h>

/* FIXME */
long dp[1000001];
int main(void)
{
    long i;
    long pre1;
    long pre2;
    long ans;
    long n1, n2;
    for (i = 2; i <= 1000000; i++) {
        dp[i] = i * (i - 1);
    }
    while (scanf("%ld%ld", &n1, &n2) && !(n1 == 0 && n2 == 0)) {
        if (n1 > n2) {
            long temp = n1;
            n1 = n2;
            n2 = temp;
        }
        pre2 = 0;
        pre1 = dp[n2];
        for (i = 2; i <= n1; i++) {
            ans = pre1 * 2 + n2 * 2 - pre2;
            if (i <= n2)
                ans += (n2 - i + 1) * 4;
            pre2 = pre1;
            pre1 = ans;
        }
        printf("%ld\n", ans);
    }
    return 0;
}
