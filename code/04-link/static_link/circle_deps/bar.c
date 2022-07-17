#include <stdio.h>

void foo1_f2(void);
void foo2_f1(void);

void bar_f1(void)
{
  printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
  foo1_f2();
  foo2_f1();
}

void bar_f2(void)
{
  printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
}