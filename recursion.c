#include <stdio.h>

void sum_digits(int n, int *res)
{
    if (n == 0)
    {
        return;
    }
    *res += n % 10;
    sum_digits(n / 10, res);
}

int count_digits(int n)
{
    if (n < 10)
    {
        return 1;
    }
    return 1 + count_digits(n / 10);
}

// 2, 1, 3, 4, 7, 11, 18, 29, 47, 76, 123, 199, 322, 521, 843, 1364, 2207, 3571, 5778, 9349
int lucas(int n)
{
    if (n == 0)
    {
        return 2;
    }
    if (n == 1)
    {
        return 1;
    }
    return lucas(n - 1) + lucas(n - 2);
}

int lucas_loop(int n)
{
    int prev = 2;
    int curr = 1;
    for (int i = 2; i <= n; i++)
    {
        int tmp = prev;
        prev = curr;
        curr = tmp + curr;
    }
    return curr;
}

// 0, 1, 2, 5, 12, 29, 70, 169, 408, 985, 2378, 5741, 13860
int pell(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return 2 * pell(n - 1) + pell(n - 2);
}

int pell_loop(int n)
{
    int prev = 0;
    int curr = 1;
    for (int i = 2; i <= n; i++)
    {
        int tmp = prev;
        prev = curr;
        curr = 2 * curr + tmp;
    }
    return curr;
}

int _is_ordered(int *arr, int size, int prev, int idx, int flag)
{
    if (idx == size || flag == 0)
    {
        return flag;
    }
    if (flag == 1 && prev <= arr[idx])
    {
        flag = 1;
    }
    else if (flag == -1 && prev >= arr[idx])
    {
        flag = -1;
    }
    else
    {
        flag = 0;
    }
    return _is_ordered(arr, size, arr[idx], idx + 1, flag);
}

int is_ordered(int *arr, int size)
{
    if (size < 2)
    {
        return 1;
    }
    int flag;
    int first_idx = 0;
    int second_idx = 1;
    int third_idx = 2;
    if (arr[first_idx] <= arr[second_idx])
    {
        flag = 1;
    }
    else
    {
        flag = -1;
    }
    return _is_ordered(arr, size, arr[second_idx], third_idx, flag);
}

int main()
{
    int res = 0;
    int asc[] = {1, 3, 3, 4, 5};
    int desc[] = {5, 4, 3, 3, 1};
    int unord[] = {1, 3, 2, 4, 5};
    int all_same[5] = {2, 2, 2, 2, 2};
    printf("ascending is %d\n", is_ordered(asc, 5));
    printf("descending is %d\n", is_ordered(desc, 5));
    printf("unordered is %d\n", is_ordered(unord, 5));
    printf("all_same is %d\n", is_ordered(all_same, 5));
    return 0;
}
