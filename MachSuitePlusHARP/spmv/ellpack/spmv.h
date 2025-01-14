/*
Based on algorithm described here:
http://www.cs.berkeley.edu/~mhoemmen/matrix-seminar/slides/UCB_sparse_tutorial_1.pdf
*/


// These constants valid for the IEEE 494 bus interconnect matrix
// #define NNZ 1666
#define N 494
#define L 10

// #define N 64
// #define L 4

#define TYPE double

void ellpack(TYPE nzval[N*L], int cols[N*L], TYPE vec[N], TYPE out[N]);
////////////////////////////////////////////////////////////////////////////////
// Test harness interface code.

struct bench_args_t {
  TYPE nzval[N*L];
  int cols[N*L];
  TYPE vec[N];
  TYPE out[N];
};
