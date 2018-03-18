#include <stdio.h>

#include "minunit.h"
#include "darray.h"

int tests_run = 0;

static char * test_darray_new() {
  DArray *arr = darray_new();
  mu_assert("new dynamic array should have length 0", arr->length == 0);
  return 0;
}

static char * test_darray_get() {
  DArray *arr = darray_new();
  Result result = darray_get(*arr, 10);
  mu_assert("getting a value out of bounds is an error", result.error != 0);
  return 0;
}

static char * test_darray_push() {
  DArray *arr = darray_new();
  darray_push(arr, 42);
  mu_assert("increases array length", arr->length == 1);
  Result result = darray_get(*arr, 0);
  mu_assert("sets a value at a specific index", result.error == 0 && result.value == 42);
  return 0;
}

static char * test_darray_push_multiple() {
  DArray *arr = darray_new();
  for (int i = 0; i < 1000; i++) {
    darray_push(arr, i);
  }
  Result result;
  result = darray_get(*arr, 42);
  mu_assert("stores up to 1000 values", result.error == 0 && result.value == 42);
  return 0;
}

static char * all_tests() {
  mu_run_test(test_darray_new);
  mu_run_test(test_darray_get);
  mu_run_test(test_darray_push);
  mu_run_test(test_darray_push_multiple);
  return 0;
}

int main() {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("All %d tests passed", tests_run);
  }
  return result != 0;
}
