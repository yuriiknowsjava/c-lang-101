#include <stdio.h>

// O(N) = sqrt(N)
int main()
{
    int n;
    printf("Enter an integer: \n");
    scanf("%d", &n);
    printf("Divisors for %d:\n", n);
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("%d, %d, \n", i, n / i);
        }
    }
    printf("\n");
    return 0;
}
