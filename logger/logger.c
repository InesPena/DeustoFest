#include "logger.h"

void log(char msg[200]) {

	FILE *f;
	f = fopen("logger/deustoFest.log", "w");

	fprintf(f, msg);


	fclose(f);
}

void getFecha() {

	time_t t;
	struct tm *st ;
	char *ch ;
	time(&t);
	ch = ctime(&t) ;
	printf("ctime:%s\n", ch );
}

