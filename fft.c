/*
 * fft.c
 *
 *  Created on: 29 нояб. 2018 г.
 *      Author: anton
 */
#include "fft.h"
#include <math.h>

unsigned revbit(unsigned num, int wide) {
    unsigned rnum = 0 ;
    unsigned i ;

    for (i = 0; i < wide; i++)
    {
        if( num & (1 << i) ) {
            rnum |= (1 << ((wide - 1) - i)) ;
        }
    }

    return rnum;
}

// INPUT: x[] - The time domain signal. N should be a power of 2.
// OOTPUT: Z[] - The frequency domain signal, has the same length
int fft(FP_TYPE complex x[], size_t N, FP_TYPE complex Z[]) {

	// Calculate log2(N) and put it into m
	int log2N ;
	for(log2N = 0; (N >> log2N) > 1; log2N++) ;

	// Copy reverse x[] into Z[]
	for(int i = 0; i < N; i++) {
		Z[i] = x[revbit(i, log2N)] ;
	}

	// 2. Butterfly
	for (int l = 1; l <= log2N; l++) {	// Loop fo each stage
		int le = 1 << l ;				// = 2^l
		FP_TYPE complex Wn = 1 + I*0 ;		// W0
		FP_TYPE complex W1 = cos(2*M_PI/le) - I*sin(2*M_PI/le) ; // Calculate sine & cosine values
		for(int n = 0; n < le/2 ; n++) {		// Loop for each sub DFT
			for (int k = n; k < N; k += le) {	// Loop for each butterfly
				FP_TYPE complex G = Z[k + le/2] * Wn ;
				Z[k + le/2] = Z[k] - G ;
				Z[k] = Z[k] + G ;
			}
			Wn = Wn * W1 ;	// Calculate Wn
		}
	}

	return 0 ;
}

int ifft(FP_TYPE complex Z[], size_t N, FP_TYPE complex x[]) {

	// Initialize x[]
	for(int i = 0; i < N; i++) {
		x[i] = conj(Z[i]) ;		// Change sign if imag(Z[])
	}

	fft(x, N, x) ;		// Calculate forward FFT

	for (int  i = 0; i < N; i++) {
		x[i] = conj(x[i]) / N ;		// Divide time domain by N and
									// change the sign of imag(x[])
	}

	return 0 ;
}

