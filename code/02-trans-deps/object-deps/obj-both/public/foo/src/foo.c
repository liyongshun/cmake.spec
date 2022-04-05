#include <stdio.h>

void foo(void)
{
    printf("foo::PUBLIC_BAR=%d\n", PUBLIC_BAR);
    printf("foo::INTERFACE_BAR=%d\n", INTERFACE_BAR);
    // printf("foo::PRIVATE_BAR=%d\n", PRIVATE_BAR);    
}