#include <stdio.h>

#define SIZE 9

int modular_arithmetics(int base, int value)
{
    if (base < 1)
    {
        printf("Modular base has to be great than 1\n");
        return -1;
    }
    if (value >= 0 && value < base)
    {
        return value;
    }
    if (value > base)
    {
        return value % base;
    }
    if (value % base == 0)
    {
        return 0;
    }
    return base + (value % base);
}

void shift_left(int data[], int size, int positions)
{
    if (size < 2)
    {
        return;
    }
    int K = modular_arithmetics(size, positions);
    for (int k = 0; k < K; k++)
    {
        int first = data[0];
        for (int i = 0; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        data[size - 1] = first;
    }
}

void shift_right(int data[], int size, int positions)
{
    if (size < 2)
    {
        return;
    }
    int K = modular_arithmetics(size, positions);
    for (int k = 0; k < K; k++)
    {
        int last = data[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            data[i] = data[i - 1];
        }
        data[0] = last;
    }
}

int main()
{
    int data[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    shift_right(data, SIZE, 2);
    shift_left(data, SIZE, 2);

    printf("test modular arithmatics:\n");
    for (int i = -18; i <= 18; i++)
    {
        printf("idx=%d, mod=%d \n", i, modular_arithmetics(SIZE, i));
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n");
    return 0;
}
