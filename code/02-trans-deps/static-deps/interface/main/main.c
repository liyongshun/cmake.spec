#include <stdio.h>
#include "foo.h"
#include "bar.h"
#include "foo_def.h"

int main(int argc, char** argv)
{
    printf("%d\n", FOO_TIMES * bar_times(foo_add(2, 3)));
}