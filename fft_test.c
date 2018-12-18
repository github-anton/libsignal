/*
 * fft_test.c
 *
 *  Created on: 30 нояб. 2018 г.
 *      Author: anton
 */
#include "fft.h"
#include "vector.h"


#define WORK_DIR	"Data/"
#define LEN			128

int main(void) {
	FP_TYPE x[LEN] ;					// The time domain signal
	FP_TYPE complex cx[LEN] ;		// The time domain signal converted to complex
	FP_TYPE complex Z[LEN] ;			// The frequency domain signal

	//load_complex(WORK_DIR "OctaveConv2.mat", y, 0, LEN ) ;
	//load_complex(WORK_DIR "x012.mat", cx, 0, 8) ;
	load_vector(WORK_DIR "sin128.mat", x, 0, 128) ;
	//load_vector(WORK_DIR "100sin128.mat", x, 0, 128) ;
	//load_vector(WORK_DIR "sin8192.mat", x, 0, LEN) ;
	//load_vector(WORK_DIR "x0-127.mat", x, 0, LEN) ;

	// Convert x[] to complex cx[]
	for(int i = 0; i < LEN; i++) {
		cx[i] = x[i] ;
	}

	fft(cx, LEN, Z) ;

	//save_complex(WORK_DIR "Z3.mat", "fft_test", VERSION, "Z3", Z, LEN) ;
	//save_complex(WORK_DIR "Z012_2.mat", "fft_test", VERSION, "Z012_2", Z, 8) ;
	save_complex(WORK_DIR "SIN128_2.mat", "fft_test", VERSION, "Z2", Z, 128) ;
	//save_complex(WORK_DIR "100SIN128_3.mat", "fft_test", VERSION, "Z3", Z, 128) ;
	//save_complex(WORK_DIR "SIN8192_2.mat", "fft_test", VERSION, "Z2", Z, LEN) ;
	//save_complex(WORK_DIR "SORT.mat", "fft_test", VERSION, "SORT", Z, LEN) ;

	return 0 ;
}
