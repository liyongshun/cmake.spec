#include "bar/bar.h"
#include <stdio.h>

void bar(void)
{
    printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
}