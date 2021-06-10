#ifndef __SINATRA_VECTOR_H__
#define __SINATRA_VECTOR_H__

#ifdef _WIN32
#ifdef EXPORT_SINATRA_VECTOR
#define SINATRA_VECTOR_API __declspec(dllexport)
#else
#define SINATRA_VECTOR_API __declspec(dllimport)
#endif
#else
#define SINATRA_VECTOR_API 
#endif

#include <stdlib.h>

#define VECTOR_ARRAY_DATA(data) ( (char **) ((void *) data) )

typedef struct {
  char **data;
  size_t ndim;
  size_t *dimensions;
} vector_array_t;


SINATRA_VECTOR_API void get_vector(vector_array_t *vector, size_t *indicies, void ***data);

SINATRA_VECTOR_API void get_element(vector_array_t *vector, size_t *indicies, void **data, size_t data_size);






#endif