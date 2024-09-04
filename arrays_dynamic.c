#include <stdio.h>

int *generate_arr(int size)
{
    int *arr = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = i * i;
    }
    return arr;
}

// we use void as param type, since we work with addresses
// ** - a pointer to a pointer
void swap_arrays_o1(void **arr1, void **arr2)
{
    void *tmp = arr1;
    *arr1 = *arr2;
    *arr2 = tmp;
}

int main()
{
    int arr[] = {7, 8, 9, 10, 11};
    int *ptr = arr;
    printf("Access element by pointer arithmatics: %d\n", *ptr + 2);
    int length = sizeof(arr) / sizeof(arr[0]);
    printf("Calc array length: %d\n", length);

    int *arr2 = generate_arr(5);
    return 0;
}
