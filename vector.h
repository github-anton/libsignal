/*
 * vector.h
 *
 *  Created on: 26 нояб. 2018 г.
 *      Author: anton
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <complex.h>

#include "config.h"

int load_vector(char *path, FP_TYPE array[], size_t off, size_t len) ;
int save_vector(char *path, char *app, char *ver, char *name, FP_TYPE array[], size_t len) ;
int load_complex(char *path, FP_TYPE complex array[], size_t off, size_t len) ;
int save_complex(char *path, char *app, char *ver, char *name, FP_TYPE complex array[], size_t len) ;

#endif /* VECTOR_H_ */
