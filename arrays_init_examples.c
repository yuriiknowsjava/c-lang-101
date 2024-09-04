#include <stdio.h>

// array size has to be static!
// Cannot use variable
#define SIZE 5
#define ROWS 4
#define COLUMNS 3

int main()
{
    printf("1D arrays:\n");
    int zero_arr[SIZE] = {0};
    int rest_zeros_arr[SIZE] = {1, 2};
    int values_arr[] = {1, 2, 3, 4, 5};
    printf("zero_arr | rest_zeros_arr | values_arr\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d,         %d,               %d\n", zero_arr[i], rest_zeros_arr[i], values_arr[i]);
    }
    printf("First element address: %d\n", zero_arr);
    printf("Same as '&zero_arr[0]': %d\n", &zero_arr[0]);

    printf("2D arrays: \n");
    printf("standart init: \n");
    int arr_2d[ROWS][COLUMNS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int incomplit_init[3][3] = {{5, 6}, {7}};      // rest will be set to 0
    int arr_2d_as_1d_list[2][3] = {5, 2, 1, 6, 5}; // and the last one is 0
    printf("First element of 2d array: %d == %d\n", arr_2d, &arr_2d[0]);
    printf("All elements of N-D arrays are stored one after another:\n");
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLUMNS; c++)
        {
            printf("Address of arr_2d[%d][%d] is %lu\n", r, c, &arr_2d[r][c]);
        }
    }
    return 0;
}
