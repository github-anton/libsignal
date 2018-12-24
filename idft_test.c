/*
 * idft_test.c
 *
 *  Created on: 27 нояб. 2018 г.
 *      Author: anton
 */
#include "signal/vector.h"
#include "signal/dft.h"

#define WORK_DIR	"Data/"
#define FREQ_LEN	56
#define TIME_LEN	(FREQ_LEN - 1)*2

int main(void) {
	FP_TYPE complex Z[FREQ_LEN] ;		// The frequency domain signal
	FP_TYPE u[TIME_LEN] ;		// The time domain signal

	load_complex(WORK_DIR "Z.mat", Z, 0, FREQ_LEN) ;
	idft(Z, u, TIME_LEN) ;
	save_vector(WORK_DIR "u2.mat", "idft_test", "0.2", "u2", u, TIME_LEN ) ;

	return 0 ;
}
