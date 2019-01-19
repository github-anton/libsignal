/*
 * trig.h
 *
 *  Created on: Jan 17, 2019
 *      Author: anton
 */

#ifndef TRIG_H_
#define TRIG_H_

#include <signal/config.h>

#define TRIG_PRECISION		11

FP_TYPE sin1 (FP_TYPE rad) ;
FP_TYPE cos1 (FP_TYPE rad) ;

#define sin		sin1
#define cos		cos1

#define M_PI		3.14159265358979323846
#define M_PIf64x	3.141592653589793238462643383279502884

#endif /* INCLUDE_SIGNAL_TRIG_H_ */
