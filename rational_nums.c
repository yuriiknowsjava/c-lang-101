#include <stdio.h>

typedef struct rationalnumber
{
    int n;
    int d;
} RationalNumber;

const RationalNumber NEGATIVE_ONE = {.n = -1, .d = 1};

void increment(RationalNumber *rn)
{
    (*rn).n += 1;
    (*rn).d += 1;
}

void decrement(RationalNumber *rn)
{
    rn->n -= 1; // equivalent to (*rn).n
    rn->d -= 1;
}

RationalNumber multiplication(RationalNumber a, RationalNumber b)
{
    RationalNumber result = {
        .n = a.n * b.n,
        .d = a.d * b.d};
    return result;
}

RationalNumber division(RationalNumber a, RationalNumber b)
{
    RationalNumber reciprocal_b = {
        .n = b.d,
        .d = b.n};
    return multiplication(a, reciprocal_b);
}

RationalNumber addition(RationalNumber a, RationalNumber b)
{
    if (a.d != b.d)
    {
        RationalNumber result = {.n = a.n * b.d + b.n * a.d, .d = a.d * b.d};
        return result;
    }
    else
    {
        RationalNumber result = {.n = a.n + b.n, .d = a.d};
        return result;
    }
}

RationalNumber subtraction(RationalNumber a, RationalNumber b)
{
    RationalNumber result = {
        .n = a.n * b.d - b.n * a.d,
        .d = a.d * b.d};
    return addition(a, multiplication(NEGATIVE_ONE, b));
}

int equals(RationalNumber a, RationalNumber b)
{
    int a_n = a.n * b.d;
    int b_n = b.n * a.d;
    if (a_n == b_n)
    {
        return 1;
    }
    return 0;
}

int compare(RationalNumber a, RationalNumber b)
{
    if (equals(a, b))
    {
        return 0;
    } 
    RationalNumber diff = subtraction(a, b);
    double decimal_dff = diff.n / (double) diff.d;
    if (decimal_dff < 0)
    {
        return -1;
    }
    return 1;
}

void print_rational_num(RationalNumber rn)
{
    printf("%d/%d", rn.n, rn.d);
}

int main()
{
    RationalNumber two_third = {.n = 2, .d = 3};
    RationalNumber four_sixth = {.n = 4, .d = 6};
    if (equals(two_third, four_sixth))
    {
        print_rational_num(two_third);
        printf(" == ");
        print_rational_num(four_sixth);
        printf("\n");
    }
    RationalNumber four_third = addition(two_third, two_third);

    printf("2/3 + 2/3 == ");
    print_rational_num(four_third);
    printf("\n");
    return 0;
}
