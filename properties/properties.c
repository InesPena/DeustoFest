
#include "properties.h"
#include "../sqlite3/sqlite3.h"


void crearProperties(Properties *properties, char name[]) {
	FILE *f = fopen(name, "w");

	for (int i = 0; i < sizeof(properties->clave); i++) {
		fprintf(f, "-%s: ", properties->clave[i]);
		fprintf(f, "%s\n", properties->valor[i]);
	}
	fclose(f);

}

void cargarProperties(Properties *properties, char name[]) {
	FILE *f = fopen(name, "r");

	char buffer[2000];
	char *linea;
	while (fgets(buffer, 2000, f)) {
		linea = strtok(buffer, ":");
		printf("%s", linea);
		for(int i = 0; i < sizeof(linea)-2 ; i++)
			{
				printf("%i \n",i);
				if(i % 2 == 0){
					//meter en array clave
					printf( "Clave: %s\n", linea );
				}
				else{
					//meter en array valor.
					printf( "Valor: %s\n", linea );
				}
				linea = strtok(NULL, ":");
			}
	}

	fclose(f);

}




