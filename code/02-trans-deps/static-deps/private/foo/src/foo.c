#include "foo.h"
#include "bar.h"

int foo_add(int m, int n)
{
    return bar_times(m + n);
}