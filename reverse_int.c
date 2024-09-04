#include <stdio.h>

// O(N) = logN
int count_digits(int n)
{
    int counter = 0;
    int tmp = n;
    while (tmp > 0)
    {
        counter++;
        tmp /= 10;
    }
    return counter;
}

// O(X) = X
int calc_digit_position(int digit_idx)
{
    int digit_multiplier = 1;
    for (int k = 1; k < digit_idx; k++)
    {
        digit_multiplier *= 10;
    }
    return digit_multiplier;
}

// O(X) = X
int calc_reverse_digit_position(int digit_count, int digit_idx)
{
    int reversed_digit_position = 1;
    for (int k = 1; k < (digit_count - digit_idx + 1); k++)
    {
        reversed_digit_position *= 10;
    }
    return reversed_digit_position;
}

// O(N) = logN + logN * 2logN ~= (logN)^2
int main()
{
    int n;
    printf("Enter an integer:\n");
    scanf("%d", &n);
    int reversed_n = 0;
    const int digit_count = count_digits(n); // logN
    int digit_idx = digit_count;
    while (digit_idx > 0) // logN
    {
        const int digit_multiplier = calc_digit_position(digit_idx); // logN
        const int current_digit = n / digit_multiplier;
        const int reversed_digit_multiplier = calc_reverse_digit_position(digit_count, digit_idx); // logN
        reversed_n += current_digit * reversed_digit_multiplier;
        n -= digit_multiplier * current_digit;
        digit_idx--;
    }
    printf("Reversed: %d\n", reversed_n);
    return 0;
}
