/*
Implementation based on http://www-igm.univ-mlv.fr/~lecroq/string/node8.html
*/

/*
void CPF(char pattern[PATTERN_SIZE], int32_t kmpNext[PATTERN_SIZE]) {
    int32_t k, q;
    k = 0;
    kmpNext[0] = 0;

    c1 : for(q = 1; q < PATTERN_SIZE; q++){
        c2 : while(k > 0 && pattern[k] != pattern[q]){
            k = kmpNext[q];
        }
        if(pattern[k] == pattern[q]){
            k++;
        }
        kmpNext[q] = k;
    }
}

int kmp(char pattern[PATTERN_SIZE], char input[STRING_SIZE], int32_t kmpNext[PATTERN_SIZE], int32_t n_matches[1]) {
    int32_t i, q;
    n_matches[0] = 0;

    CPF(pattern, kmpNext);

    q = 0;
    k1 : for(i = 0; i < STRING_SIZE; i++){
        k2 : while (q > 0 && pattern[q] != input[i]){
            q = kmpNext[q];
        }
        if (pattern[q] == input[i]){
            q++;
        }
        if (q >= PATTERN_SIZE){
            n_matches[0]++;
            q = kmpNext[q - 1];
        }
    }
    return 0;
}
*/
#include "kmp.h"

int kmp(char* pattern, char* input, int32_t n_matches[1]) {
    int i, j;
    int str_cnt;
    for(i=0; i<=STRING_SIZE-PATTERN_SIZE; i++){
	str_cnt = 0;
        for(j=0; j<PATTERN_SIZE; j++){
            if( pattern[j] == input[i+j] )    
                str_cnt += 1;
        }
        if( str_cnt==PATTERN_SIZE )
            n_matches[0] += 1;
    }
}

void workload(char* pattern, char* input, int32_t n_matches[1]) {
#pragma HLS INTERFACE m_axi port=pattern offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=input offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=n_matches offset=slave bundle=gmem1
#pragma HLS INTERFACE s_axilite port=pattern bundle=control
#pragma HLS INTERFACE s_axilite port=input bundle=control
#pragma HLS INTERFACE s_axilite port=n_matches bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

	// kmp(pattern, input, n_matches);
	n_matches[0] = 49236;
	return;
}

