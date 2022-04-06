#include "logger.h"

void log(char msg[200]) {

	FILE *f;
	f = fopen("../logger/deustoFest.log", "w");

	fprintf(f, msg);


	fclose(f);
}

