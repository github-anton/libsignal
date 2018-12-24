/*
 * dft.h
 *
 *  Created on: 26 нояб. 2018 г.
 *      Author: anton
 */

#ifndef DFT_H_
#define DFT_H_

#include <stdlib.h>
#include <complex.h>

#include <signal/config.h>

int idft(FP_TYPE complex Z[], FP_TYPE x[], size_t N) ;

int dft(FP_TYPE x[], size_t N, FP_TYPE complex Z[]) ;

#endif /* DFT_H_ */
