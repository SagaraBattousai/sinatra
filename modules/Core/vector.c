#include <stdlib.h>

#include <sinatra/vector.h>

void get_element(vector_t *vector, size_t *indicies, void **data, size_t data_size)
{
  const size_t ndim = vector->ndim;
  const size_t *const dims = vector->dimensions;

  size_t index = *(indicies + (ndim - 1));
  if (ndim < 2)
  {
    return index;
  }

  size_t jump = 1;

  size_t i = ndim - 1;
  while (i != 0)
  {
    i--;
    jump *= *(dims + i + 1);
    index += *(indicies + i) * jump;
  }
  //data = (vector->data) + index;
  void * k = (vector->data) + (index * data_size);
  *data = k;// (vector->data) + index;
}

