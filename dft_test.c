/*
 * dft_test.c
 *
 *  Created on: 28 нояб. 2018 г.
 *      Author: anton
 */
#include "signal/vector.h"
#include "signal/dft.h"

#define WORK_DIR	"Data/"
#define TIME_LEN	111
#define FREQ_LEN	(TIME_LEN / 2 + 1)

int main(void) {
	FP_TYPE y[TIME_LEN] ;					// The time domain signal
	FP_TYPE complex Z[FREQ_LEN] ;			// The frequency domain signal

	load_vector(WORK_DIR "OctaveConv.mat", y, 0, TIME_LEN ) ;
	dft(y, TIME_LEN, Z) ;
	save_complex(WORK_DIR "Z1.mat", "dft_test", "0.1", "Z1", Z, FREQ_LEN) ;

	return 0 ;
}
