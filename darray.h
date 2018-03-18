typedef struct {
  int length;
  int *values;
  int capacity;
} DArray;

typedef struct {
  int error;
  int value;
} Result;

DArray * darray_new();
Result darray_get(DArray, int);
void   darray_push(DArray*, int);
