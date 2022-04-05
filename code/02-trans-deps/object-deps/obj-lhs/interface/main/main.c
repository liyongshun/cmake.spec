#include <stdio.h>
#include "bar.h"
#include "foo.h"

void main(int argc, char** argv)
{
   bar();
   foo();
    
   printf("main::PUBLIC_BAR=%d\n", PUBLIC_BAR);
   printf("main::INTERFACE_BAR=%d\n", INTERFACE_BAR);
   // printf("main::PRIVATE_BAR=%d\n", PRIVATE_BAR);   
}