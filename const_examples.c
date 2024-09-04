#include <stdint.h>

int main()
{
    const int val = 42;
    int var = 13;
    printf("val=%d; var=%d\n", val, var);

    const int *pointer_to_const = &val;
    // *pointer_to_const = 42; // compilation error - cannot change the value it points to
    printf("pointer_to_const=%p\n", pointer_to_const);
    pointer_to_const = &var; // can reasign pointer to different address.
    printf("pointer_to_const=%p\n", pointer_to_const);

    int *const const_pointer = &val;
    *const_pointer = 777; // can change the value it points to.
    // const_pointer = &var; // compilation error - cannot reasign to different address
    printf("val was change to %d\n", val);

    // neither value can be changeg nor pointer address reasigned
    const int *const const_pointer_to_const = &val;

    return 0;
}
