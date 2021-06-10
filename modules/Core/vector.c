#include <stdlib.h>

#include <sinatra/vector.h>


static size_t calculate_vector_index(size_t ndim, const size_t *const dims, const size_t *const indicies)
{
  //-2 as last dimension is the vector size so ignore it.
  size_t dimension_index = ndim - 2;

  size_t index = *(indicies + dimension_index);

  size_t jump = 1;

  while (dimension_index != 0)
  {
    jump *= *(dims + dimension_index);

    dimension_index--;

    index += *(indicies + dimension_index) * jump;
  }

  return index;
}

//ignore final dimension, use get_vector and then add to get elem
void get_element(vector_array_t *vector, size_t *indicies, void **data, size_t data_size)
{
  char **vector_ptr;
  get_vector(vector, indicies, &vector_ptr);

  size_t last_index = *(indicies + vector->ndim - 1);
  *data = (*vector_ptr) + (last_index * data_size);
}

void get_vector(vector_array_t *vector, size_t *indicies, void ***data)
{
  size_t index = calculate_vector_index(vector->ndim, vector->dimensions, indicies);

  *data = (vector->data) + index;
}

