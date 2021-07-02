#include <stdio.h>

void swap_numbers(int *x, int *y);

int main(void)
{
  int x,y;
  printf("x: ");
  scanf("%i", &x);
  printf("y: ");
  scanf("%i", &y);
  swap_numbers(&x, &y);
  printf("x: %i\ny: %i\n", x, y);
}

void swap_numbers(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
