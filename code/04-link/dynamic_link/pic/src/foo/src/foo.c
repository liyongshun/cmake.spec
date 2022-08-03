#include "foo/foo.h"
#include "bar/bar.h"
#include <stdio.h>

void foo(void)
{
    bar();
    printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
}