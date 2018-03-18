#include <stdlib.h>
#include "darray.h"

static int initial_capacity = 10;

DArray * darray_new() {
  int *values = calloc(initial_capacity, sizeof(*values));
  DArray *arr = malloc(sizeof(*arr));
  *arr = (DArray){ .length = 0, .values = values, .capacity = initial_capacity };
  return arr;
}

void darray_push(DArray *arr, int value) {
  if (arr->length == arr->capacity) {
    arr->capacity = arr->capacity * 2;
    arr->values = realloc(arr->values, arr->capacity * sizeof(*arr->values));
  }
  *(arr->values + arr->length++) = value;
}

Result darray_get(DArray arr, int index) {
  if (index >= arr.capacity) {
    return (Result){ .error = 1 };
  } else {
    return (Result){ .error = 0, .value = *(arr.values + index) };
  }
}
