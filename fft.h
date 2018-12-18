/*
 * fft.h
 *
 *  Created on: 29 нояб. 2018 г.
 *      Author: anton
 */

#ifndef FFT_H_
#define FFT_H_

#include <complex.h>
#include <stdlib.h>

#include "config.h"

int fft(FP_TYPE complex x[], size_t N, FP_TYPE complex Z[]) ;

int ifft(FP_TYPE complex Z[], size_t N, FP_TYPE complex x[]) ;

#endif /* FFT_H_ */
