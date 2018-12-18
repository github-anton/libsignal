#include "vector.h"
#include <stdio.h>
#include <time.h>
#include <sys/param.h>

#if FP_TYPE_NO == 0x1

#define SCAN_NUM_FMT		"%f"
#define SCAN_COMPL_FMT		"(%f,%f) "
#define PRINT_NUM_FMT		"%f "
#define PRINT_COMPL_FMT 	"(%f,%f) "

#else	// 0x2

#define SCAN_NUM_FMT		"%lf"
#define SCAN_COMPL_FMT		"(%lf,%lf) "
#define PRINT_NUM_FMT		"%lf "
#define PRINT_COMPL_FMT 	"(%.16lf,%.16lf) "

#endif

int load_vector(char *path, FP_TYPE array[], size_t off, size_t len) {
	FILE *fp ;
	char who[16], ver[16], day[16], month[16], date[16], time[16], year[16], tz[16], eml[32] ;
	char name[32] ;
	char type[32] ;
	int rows ;
	int columns ;

	fp = fopen(path, "r") ;
	if ( fp == NULL )	return -1 ;

	fscanf(fp, "# Created by %s %s %s %s %s %s %s %s %s\n",
			who, ver, day, month, date, time, year, tz, eml) ;
	fscanf(fp, "# name: %s\n", name) ;
	fscanf(fp, "# type: %s\n", type) ;
	fscanf(fp, "# rows: %i\n", &rows) ;
	fscanf(fp, "# columns: %i\n", &columns) ;

	int i ;
	for (i = 0; i < MIN(off, columns); i++) {
		FP_TYPE skip ;
		fscanf(fp, SCAN_NUM_FMT, &skip) ;
	}
	for (i = 0; i < MIN(columns, len); i++) {
		fscanf(fp, SCAN_NUM_FMT, &array[i]) ;
	}

	return i ;
}

int save_vector(char *path, char *app, char *ver, char *name, FP_TYPE array[], size_t len) {
	FILE *fp ;
	char full_date[128], tz[16], eml[32] ;
	char type[32] ;

	fp = fopen(path, "w+") ;
	if ( fp == NULL )	return -1 ;

	{
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		strftime(full_date, sizeof(full_date), "%c", &tm) ;
		strftime(tz, sizeof(full_date), "%Z", &tm) ;
	}
	sprintf(eml, "%s", "<job.aermakov@gmail.com>") ;
	fprintf(fp, "# Created by %s %s %s %s %s\n", app, ver, full_date, tz, eml) ;

	fprintf(fp, "# name: %s\n", name) ;

	sprintf(type, "%s", "matrix") ;
	fprintf(fp, "# type: %s\n", type) ;

	fprintf(fp, "# rows: 1\n") ;

	fprintf(fp, "# columns: %lu\n", len) ;

	for(int i = 0; i < len; i++) {
		fprintf(fp, PRINT_NUM_FMT, array[i]) ;
	}

	return 0 ;
}

int load_complex(char *path, FP_TYPE complex array[], size_t off, size_t len) {
	FILE *fp ;
	char who[16], ver[16], day[16], month[16], date[16], time[16], year[16], tz[16], eml[32] ;
	char name[32] ;
	char type[32] ;
	int rows ;
	int columns ;

	fp = fopen(path, "r") ;
	if ( fp == NULL )	return -1 ;

	fscanf(fp, "# Created by %s %s %s %s %s %s %s %s %s\n",
			who, ver, day, month, date, time, year, tz, eml) ;
	fscanf(fp, "# name: %s\n", name) ;
	fscanf(fp, "# type: %[A-Za-z ]\n", type) ;
	fscanf(fp, "# rows: %i\n", &rows) ;
	fscanf(fp, "# columns: %i\n", &columns) ;

	int i ;
	for (i = 0; i < MIN(off, columns); i++) {
		FP_TYPE skip ;
		fscanf(fp, SCAN_COMPL_FMT, &skip, &skip) ;
	}
	for (i = 0; i < MIN(columns, len); i++) {
		FP_TYPE real, imag ;
		fscanf(fp, SCAN_COMPL_FMT, &real, &imag) ;
		array[i] = real + I*imag ;
	}

	return i ;
}

int save_complex(char *path, char *app, char *ver, char *name, FP_TYPE complex array[], size_t len) {
	FILE *fp ;
	char full_date[128], tz[16], eml[32] ;
	char type[32] ;

	fp = fopen(path, "w+") ;
	if ( fp == NULL )	return -1 ;

	{
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		strftime(full_date, sizeof(full_date), "%c", &tm) ;
		strftime(tz, sizeof(full_date), "%Z", &tm) ;
	}
	sprintf(eml, "%s", "<job.aermakov@gmail.com>") ;
	fprintf(fp, "# Created by %s %s %s %s %s\n", app, ver, full_date, tz, eml) ;

	fprintf(fp, "# name: %s\n", name) ;

	sprintf(type, "%s", "complex matrix") ;
	fprintf(fp, "# type: %s\n", type) ;

	fprintf(fp, "# rows: 1\n") ;

	fprintf(fp, "# columns: %lu\n", len) ;

	for(int i = 0; i < len; i++) {
		fprintf(fp, PRINT_COMPL_FMT, creal(array[i]), cimag(array[i])) ;
	}

	return 0 ;
}

