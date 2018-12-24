/*
 * dft.c
 *
 *  Created on: 26 нояб. 2018 г.
 *      Author: anton
 */


#include "signal/dft.h"

#include <math.h>

// INPUT: Z[] - real and imaginary parts of the signal in the frequency domain
// OUTPUT: x[] - the signal we will get into the time domain
// NOTE: function also changes Z[]
int idft(FP_TYPE complex Z[], FP_TYPE x[], size_t N) {

	// Find sine and cosine amplitudes
	for(int k = 0; k < N/2 + 1; k++) {
		Z[k] = conj(Z[k]) / ( N / 2.0 ) ;
	}
	Z[0] = (Z[0] + conj(Z[0])) / 4.0 ;
	Z[N/2] = (Z[N/2] + conj(Z[N/2])) / 4.0 ;

	// Zero x so it can be used as accumulator
	for (int i = 0; i < N; i++) {
		x[i] = 0 ;
	}

	// SYNTHESIS METHOD #1. Loop through each
	// frequency generating the entire length of the sine and cosine
	// waves, and add them to the accumulator signal, x[ ]

	for(int k = 0; k < N/2 + 1; k++) {		// k loops through each sample ReX and ImX
		for(int i = 0; i < N; i++) {	// i loops through each sample of x[]
			x[i] = x[i] + creal(Z[k])*cos(2*M_PI*k*i/N) + cimag(Z[k])*sin(2*M_PI*k*i/N) ;
		}
	}
	return 0 ;
}

// INPUT: x[] - signal into the time domain
// OUTPUT: Z[] - signal into the frequency domain
int dft(FP_TYPE x[], size_t N, FP_TYPE complex Z[]) {

	// Zero ReX[] and ImX[] so they can be used as accumulators
	for(int k = 0; k < N / 2 + 1; k++) {
		Z[k] = 0 ;
	}

	for (int k = 0; k < N / 2 + 1; k++) {	// k loops through each sample ReX and ImX
		for (int i = 0; i < N; i++) {	// i loops through each sample of x[]
			Z[k] = Z[k] + x[i]*( cos(2*M_PI*k*i/N) - I*sin(2*M_PI*k*i/N) ) ;
		}
	}
	return 0 ;
}
