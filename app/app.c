#include <stdio.h>
#include <stdlib.h>

#include <sinatra/vector.h>


int main(void)
{
  size_t ndim = 3;
  size_t dims[] = { 3,1,3 };
  int **data = (int **)malloc(sizeof(int *) * 3);
  if (!data)
  {
    return 1;
  }

  *data = (int *)malloc(sizeof(int) * 3);
  *(data + 1) = (int *)malloc(sizeof(int) * 3);
  *(data + 2) = (int *)malloc(sizeof(int) * 3);

  if (!(*data))
  {
    return 1;
  }

  int v1[] = { 0,1,2 };
  int v2[] = { 3,4,5 };
  int v3[] = { 6,7,8 };

  int *start = &(v1[0]);

  *(data + 0) = &(v1[0]);
  *(data + 1) = &(v2[0]);
  *(data + 2) = &(v3[0]);

  vector_array_t vec = { .data = VECTOR_ARRAY_DATA(data), .ndim = ndim, .dimensions = &dims[0] };

  int **x;
  int *i;
  size_t indicies[] = { 1, 0 };
  size_t indicies2[] = { 1, 0, 1 };

  get_vector(&vec, &(indicies[0]), &x);
  get_element(&vec, &(indicies2[0]), &i, sizeof(int));

  printf("%p, %p, %i, %i\n", *x, i - 1, (*x)[1], *i);

  free(data);

  return 0;
}