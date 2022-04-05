#include "concierto.h"
#include "../sqlite3/sqlite3.h"

#define MAX_LINE 20

void selectDias(sqlite3 *db);
void selectEscenarios(sqlite3 *db);

/*
 * Pide el código de un concierto por consola
 */

int pedirCodigoConcierto()
{
	int cod;
	char str[MAX_LINE];

	printf("Cod. Concierto: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &cod);

	return cod;
}

/*
 *Pide los datos relativos a un concierto por consola
 */

void pedirDatosConcierto(sqlite3 *db,Concierto *c)
{
	char str[MAX_LINE];

	printf("Nombre del artista: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", str);
	c->artista = malloc((strlen(str) + 1) * sizeof(char));
	strcpy(c->artista, str);

	selectEscenarios(db);

	printf("Cod. Escenario: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &c->escenario);

	selectDias(db);

	printf("Cod. Día: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &c->dia);
}

/*
 * Recupera los datos de la tabla escenarios de la bd
 */

void selectEscenarios(sqlite3 *db)
{
	sqlite3_stmt *stmt;
	int result;

	char sql[] = "SELECT * FROM escenario";
	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

	printf("\n\tESCENARIOS\n");

	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
			printf("\t%s -  %s\n", (char*) sqlite3_column_text(stmt, 0), (char*) sqlite3_column_text(stmt, 1));

	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);
}

/*
 * Recupera los datos de la tabla dias de la bd
 */

void selectDias(sqlite3 *db)
{

	sqlite3_stmt *stmt;
	int result;

	char sql[] = "SELECT * FROM dia";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

	printf("\n\tDÍAS\n");

	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
			printf("\t%s -  %s\n", (char*) sqlite3_column_text(stmt, 0), (char*) sqlite3_column_text(stmt, 1));

	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);
}


/*
 * Inserta una nueva fila en la tabla concierto de la bd
 */

void insertarConcierto(sqlite3 *db, Concierto *c)
{

	sqlite3_stmt *stmt;
	int result;

	char sql[] = "INSERT INTO concierto (artista, cod_esc, cod_dia) VALUES (?, ?, ?)";

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_text(stmt, 1, c->artista, strlen(c->artista), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 2, c->escenario);
	sqlite3_bind_int(stmt, 3, c->dia);

	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE)
		printf("Error añadiendo concierto\n");
	else
		printf("Concierto añadido correctamente\n");

	sqlite3_finalize(stmt);
}

/*
 * Elimina uns concierto de la bd
 */

void eliminarConcierto(sqlite3 *db, int cod)
{
	sqlite3_stmt *stmt;
	int result;

	char sql[] = "DELETE FROM concierto WHERE cod = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, cod);

	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE)
		printf("Error cancelando concierto\n");
	else
		printf("Concierto cancelado correctamente\n");

	sqlite3_finalize(stmt);
}

/*
 * Imprime todos los datos de los coniertos por pantalla
 */

void imprimirCartelera(sqlite3 *db)
{
	sqlite3_stmt *stmt;
	int result;

	char sql[] = "SELECT c.cod, c.artista, e.nombre, d.fecha "
				"FROM concierto c, escenario e, dia d "
				"WHERE c.COD_DIA = d.cod and c.COD_ESC = e.cod;";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

	printf("\n\tCARTELERA\n");

	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{
			printf("Cod.%i\t", sqlite3_column_int(stmt, 0));
			printf("%s\t", (char*)sqlite3_column_text(stmt, 1));
			printf("%s\t", (char*)sqlite3_column_text(stmt, 2));
			printf("%s\n", (char*)sqlite3_column_text(stmt, 3));
		}


	} while (result == SQLITE_ROW);
		printf("\n");

		sqlite3_finalize(stmt);
}

