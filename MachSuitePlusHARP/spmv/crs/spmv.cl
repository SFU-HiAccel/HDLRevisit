/*
Based on algorithm described here:
http://www.cs.berkeley.edu/~mhoemmen/matrix-seminar/slides/UCB_sparse_tutorial_1.pdf
*/

#include "spmv.h"

__kernel void 
__attribute__((task))
workload( __global TYPE * restrict val, __global int * restrict cols, __global int * restrict rowDelimiters, __global TYPE * restrict vec, __global TYPE * restrict out){
    int i, j;
    TYPE sum, Si;

    spmv_1 : for(i = 0; i < N; i++){
        sum = 0; Si = 0;
        int tmp_begin = rowDelimiters[i];
        int tmp_end = rowDelimiters[i+1];
        spmv_2 : for (j = tmp_begin; j < tmp_end; j++){
            Si = val[j] * vec[cols[j]];
            sum = sum + Si;
        }
        out[i] = sum;
    }
}
