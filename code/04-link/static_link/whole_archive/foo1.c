#include <stdio.h>

void bar_f1(void);

void foo1_f1(void)
{
  printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
  bar_f1();
}

void foo1_f2(void)
{
  printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
}