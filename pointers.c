#include <stdio.h>

void findMinMax(int a, int b, int *min, int *max)
{
    if (a > b)
    {
        *max = a;
        *min = b;
    }
    else
    {
        *max = b;
        *min = a;
    }
}

int main()
{
    int num1 = 5;
    int num2 = 7;
    int *ptrA = &num1;
    int *ptrB = &num2;
    printf("num1 = %d, num2 = %d\n", num1, num2); // num1 = 5, num2 = 7
    printf("ptrA = %p, ptrB = %p\n", ptrA, ptrB); // ptrA = 0x7fffe43586f0, ptrB = 0x7fffe43586f4
    printf("\n");

    *ptrA = *ptrA + 1;
    *ptrB = *ptrB + 3;
    printf("num1 = %d, num2 = %d\n", num1, num2);     // num1 = 6, num2 = 10
    printf("*ptrA = %d, *ptrB = %d\n", *ptrA, *ptrB); // *ptrA = 6, *ptrB = 10
    printf("ptrA = %p, ptrB = %p\n", ptrA, ptrB);     // ptrA = 0x7fffe43586f0, ptrB = 0x7fffe43586f4
    printf("\n");

    ptrA = ptrB;
    ptrB = ptrA;
    printf("num1 = %d, num2 = %d\n", num1, num2);     // num1 = 6, num2 = 10
    printf("*ptrA = %d, *ptrB = %d\n", *ptrA, *ptrB); // *ptrA = 10, *ptrB = 10
    printf("ptrA = %p, ptrB = %p\n", ptrA, ptrB);     // ptrA = 0x7fffe43586f4, ptrB = 0x7fffe43586f4
    printf("\n");

    int a = 43;
    int b = 53;
    int min;
    int max;
    findMinMax(a, b, &min, &max);
    printf("min is %d, max is %d\n", min, max);
}
