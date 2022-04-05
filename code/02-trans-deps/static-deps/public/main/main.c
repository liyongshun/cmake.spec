#include <stdio.h>
#include "foo.h"

int main(int argc, char** argv)
{
    printf("%d\n", FOO_TIMES * foo_add(2, 3));
}