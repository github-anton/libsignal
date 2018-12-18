/*
 * ifft_test.c
 *
 *  Created on: 4 дек. 2018 г.
 *      Author: anton
 */
#include "fft.h"
#include "vector.h"


#define WORK_DIR	"Data/"
#define LEN			128

int main(void) {
	FP_TYPE complex Z[LEN] ;			// The frequency domain signal
	FP_TYPE complex x[LEN] ;			// The time domain signal

	load_complex(WORK_DIR "Z012_2.mat", Z, 0, 8) ;
	ifft(Z, 8, x) ;
	save_complex(WORK_DIR "u012_2.mat", "ifft_test", "0.1", "u012_2", x, 8) ;

	return 0 ;
}
