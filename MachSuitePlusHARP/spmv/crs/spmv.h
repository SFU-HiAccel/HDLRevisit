/*
Based on algorithm described here:
http://www.cs.berkeley.edu/~mhoemmen/matrix-seminar/slides/UCB_sparse_tutorial_1.pdf
*/


// These constants valid for the IEEE 494 bus interconnect matrix
#define NNZ 1666
#define N 494

#define TYPE double

void spmv(TYPE val[NNZ], int cols[NNZ], int rowDelimiters[N + 1],
          TYPE vec[N], TYPE out[N]);
////////////////////////////////////////////////////////////////////////////////
// Test harness interface code.

struct bench_args_t {
  TYPE val[NNZ];
  int cols[NNZ];
  int rowDelimiters[N+1];
  TYPE vec[N];
  TYPE out[N];
};
