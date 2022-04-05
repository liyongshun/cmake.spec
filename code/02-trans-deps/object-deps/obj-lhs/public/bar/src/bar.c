#include "bar.h"
#include <stdio.h>

void bar(void)
{
    printf("bar::PUBLIC_BAR=%d\n", PUBLIC_BAR);
    // printf("bar::INTERFACE_BAR=%d\n", INTERFACE_BAR);
    printf("bar::PRIVATE_BAR=%d\n", PRIVATE_BAR);
}