#include "signal/conv.h"

// x - signal
// h - system response
// y - the result signal
void conv(FP_TYPE x[], size_t x_len, FP_TYPE h[], size_t h_len, FP_TYPE y[]) {
	size_t y_len ;

	y_len = x_len + h_len - 1 ;		// Calculate the result signal len

	for (int i = 0; i < y_len ; i++) {	// Loop each point in y[]
		y[i] = 0 ;
		for (int j = 0; j < h_len; j++) {	// Loop each point in h
			if ( i - j < 0 ) continue ;
			if ( i - j > x_len ) continue ;
			y[i] += h[j]*x[i-j] ;
		}
	}
}
