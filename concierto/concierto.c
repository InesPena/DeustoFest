#include "concierto.h"
#include "../sqlite3/sqlite3.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 20

/*
 *Pide los datos relativos a un concierto por consola
 */

void pedirDatosConcierto(Concierto *c)
{
	char str[MAX_LINE];

	printf("Nombre del artista: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", str);
	c->artista = malloc((strlen(str) + 1) * sizeof(char));
	strcpy(c->artista, str);

	printf("Escenario: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &c->escenario);
}

/*
 * Recupera los datos de todos los escenarios del festival
 */

void selectEscenarios(sqlite3 *db)
{
	sqlite3_stmt *stmt;
	int result;

	char sql[] = "SELECT * FROM escenario";
	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW)
				printf("\t[%s:   %s]\n", (char*) sqlite3_column_text(stmt, 0), (char*) sqlite3_column_text(stmt, 1));

	} while (result == SQLITE_ROW);
}

/*
 * Inserta una nueva fila en la tabla concierto de la bd
 */

void insertarConcierto(sqlite3 *db, Concierto c)
{

	sqlite3_stmt *stmt;
	int result;

	char sql[] = "INSERT INTO concierto (artista, cod_esc, cod_dia) VALUES (?, ?, ?)";

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_text(stmt, 1, c.artista, strlen(c.artista), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 2, c.escenario);
	sqlite3_bind_int(stmt, 3, c.dia);

	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE)
		printf("Error añadiendo concierto\n");
	else
		printf("Concierto añadido correctamente\n");

	sqlite3_finalize(stmt);
}

