#include "logger.h"

void log(char msg[MAX_LOG], TIPO tipo)
{
	FILE *file;
	file = fopen("logger/deustoFest.log", "a+");

	time_t t;
	char *ch ;
	time(&t);
	ch = ctime(&t) ;
	fprintf(file, "\n[%s]", ch);

	if (tipo == INFO) fprintf(file, "INFO: ");
	if (tipo == ERROR) fprintf(file, "ERROR: ");

	fprintf(file, msg);

	fclose(file);
}
