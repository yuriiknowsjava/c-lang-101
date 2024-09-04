#include <stdio.h>

typedef struct point
{
    int x;
    int y;
} Point;

typedef struct localdate
{
    int day;
    int month;
    int year
} LocalDate;

void print_date(LocalDate local_date)
{
    printf("%d-%d-%d\n", local_date.year, local_date.month, local_date.day);
}

Point add_points(Point a, Point b)
{
    Point c = { .x = a.x + b.x, .y = a.y + b.y };
    return c;
}

// You've go to use a pointer, remember about shallow copy!
void increment_point(Point *p)
{
    (*p).x += 1;
    (*p).y += 1;
}

int main()
{
    struct point p1;
    p1.x = 10;
    p1.y = 40;

    LocalDate local_date = {.year = 2024, .month = 9, .day = 2};
    print_date(local_date);

    Point a;
    Point b = {.x = 100, .y = 200};
    a = b;
    printf("{a.x=%d, a.y=%d} {b.x=%d, b.y=%d}\n", a.x, a.y, b.x, b.y);
    a.x = 999;
    printf("{a.x=%d, a.y=%d} {b.x=%d, b.y=%d}\n", a.x, a.y, b.x, b.y);
    if (a.x != b.x)
    {
        puts("assignment operation of structs create a shallow copy!!!");
    }
    increment_point(&a);
    printf("After increment {a.x=%d, a.y=%d}\n", a.x, a.y);
    Point c = add_points(a, b);
    printf("{c.x=%d, c.y=%d}\n", c.x, c.y);
    return 0;
}
