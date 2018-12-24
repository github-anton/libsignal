/*
 * mk_src_signal.c
 *
 *  Created on: 11 дек. 2018 г.
 *      Author: anton
 */
#include "signal/vector.h"
#include <stdio.h>

#define WORK_DIR	"Data/"
#define LEN		1024

int main(void) {

	FP_TYPE x[1024] ;
	FILE *fp ;

	load_vector(WORK_DIR "x1024.mat", x, 0, LEN ) ;

	fp = fopen(WORK_DIR "x.h", "w+") ;
	fprintf(fp, "#ifndef X_H_\n"
				"#define X_H_\n"
				"\n"
				"#include <signal/config.h>\n"
				"\n"
				"extern FP_TYPE x[%i] ;\n"
				"\n"
				"#endif\n", LEN) ;
	fclose(fp) ;

	fp = fopen(WORK_DIR "x.c", "w+") ;
	fprintf(fp, "#include \"x.h\"\n"
				"\n"
			"FP_TYPE x[%i] = {", LEN) ;
	for (int i = 0; i < LEN; i++) {
		if ( i ) {
			fprintf(fp, ",") ;
		}
		fprintf(fp, " %f", x[i]) ;
	}
	fprintf(fp, " } ;\n") ;
	fclose(fp) ;

	return 0 ;
}
