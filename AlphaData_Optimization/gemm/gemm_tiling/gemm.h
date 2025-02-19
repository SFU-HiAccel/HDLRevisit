//Standard Libraries
#include <stdio.h>
#include <stdlib.h>

//Define compute data type
#define TYPE double


#define MatrixSize 1024 
//Specify row/column sizes
#define row_size MatrixSize
#define col_size MatrixSize 
#define N row_size*col_size

//specify tile_size
#define tile_size 128 

//Define the input range to operate over
#define MIN 0.
#define MAX 1.0

//Set number of iterations to execute
#define MAX_ITERATION 1

void gemm(TYPE m1[N], TYPE m2[N], TYPE prod[N]);
////////////////////////////////////////////////////////////////////////////////
// Test harness interface code.

struct bench_args_t {
  TYPE m1[N];
  TYPE m2[N];
  TYPE prod[N];
};
