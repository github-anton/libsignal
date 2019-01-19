/*
 * trig.c
 *
 *  Created on: Jan 17, 2019
 *      Author: anton
 */

#include "signal/trig.h"
#include "stdio.h"

FP_TYPE trim_arg(FP_TYPE x) {
	FP_TYPE nf = x / ( 2 * M_PIf64x ) ;
	return (nf - (int)nf) * 2 * M_PIf64x ;
}

FP_TYPE sin1(FP_TYPE x) {
	int n ;
	FP_TYPE sum, term ;

	x = trim_arg(x) ;

	sum = x ;
	term = x ;
	for (n = 1; n <= TRIG_PRECISION; n++) {
		term *= (-1) * (x*x) / ((2*n+1)*(2*n)) ;
		sum += term ;
	}
	return sum ;
}

FP_TYPE cos1(FP_TYPE x) {
	int n ;
	FP_TYPE sum, term, nf ;

	trim_arg(x) ;

	sum = 1 ;
	term = 1 ;
	for (n = 1; n <= TRIG_PRECISION; n++) {
		term *= (-1) * (x*x) / ((2*n)*(2*n-1)) ;
		sum += term ;
	}

	return sum ;
}
