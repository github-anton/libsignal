/*
 * trig_test.c
 *
 *  Created on: Jan 17, 2019
 *      Author: anton
 */
#include "signal/trig.h"
#include "stdio.h"

int main(void) {

	printf("=====sin()======\n") ;
	printf("sin(0) = %f\n", sin(0)) ;
	printf("sin(PI/2) = %f\n", sin(M_PI/2)) ;
	printf("sin(8) = %f\n", sin(8)) ;
	printf("sin(100*PI) = %f\n", sin(100*M_PI)) ;

	printf("=====cos()======\n") ;
	printf("cos(0)=%f\n", cos(0)) ;
	printf("cos(PI/2)=%f\n", cos(M_PI/2)) ;

	return 0 ;
}
