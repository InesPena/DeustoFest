
#ifndef PROPERTIES_PROPERTIES_H_
#define PROPERTIES_PROPERTIES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../sqlite3/sqlite3.h"

typedef struct {
	char** clave;
	char** valor;
} Properties;

void crearProperties(Properties* properties, char name[]);
void cargarProperties(Properties* properties, char name[]);

#endif /* PROPERTIES_PROPERTIES_H_ */
