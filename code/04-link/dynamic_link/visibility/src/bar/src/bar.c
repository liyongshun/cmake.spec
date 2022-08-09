#include "bar/bar.h"
#include <stdio.h>

int bar_data = 20;

void bar(void)
{
    bar_data = 30;
    printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
}