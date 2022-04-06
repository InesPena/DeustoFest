#include "concierto.h"
#include "../sqlite3/sqlite3.h"

void selectDias(sqlite3 *db);
void selectEscenarios(sqlite3 *db);

#define MAX_LINE 20

/* ==================================================
 * 						CONCIERTO
 * ==================================================

/*
 * Pide el c�digo de un concierto por consola
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

	printf("Cod. D�a: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &c->dia);

	printf("Coste del concierto: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%f", &c->coste);

}




/*
 * Inserta una nueva fila en la tabla concierto de la bd
 */

//REVISAR

void insertarConcierto(sqlite3 *db, Concierto *c)
{
	sqlite3_stmt *stmt;
	int result;

	char sql[] = "INSERT INTO CONCIERTO(ARTISTA, COD_ESC, COD_DIA, COSTE) VALUES (?, ?, ?, ?)";

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_text(stmt, 1, c->artista, strlen(c->artista), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 2, c->escenario);
	sqlite3_bind_int(stmt, 3, c->dia);
	sqlite3_bind_int(stmt, 3, c->coste);

	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE)
		printf("Error a�adiendo concierto\n");
	else
		printf("Concierto a�adido correctamente\n");

	sqlite3_finalize(stmt);
}

/*
 * Elimina uns concierto de la bd
 */

void eliminarConcierto(sqlite3 *db, int cod)
{
	sqlite3_stmt *stmt;
	int result;

	char sql[] = "DELETE FROM CONCIERTO WHERE COD = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, cod);

	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE)
		printf("Error cancelando concierto\n");
	else
		printf("Concierto cancelado correctamente\n");

	sqlite3_finalize(stmt);
}

/* ==================================================
 * 					CARTELERA
 * ==================================================
 */

/*
 * Recupara los datos de todos los conciertos de la bd
 */

void obtenerCartelera(sqlite3 *db, Cartelera *cart)
{
	sqlite3_stmt *stmt;
	int result;

	char sql[] = "SELECT COUNT(*) FROM CONCIERTO";
	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	result = sqlite3_step(stmt);
	cart->numConciertos = sqlite3_column_int(stmt, 0);

	char sql2[] = "SELECT * FROM CONCIERTO";
	sqlite3_prepare_v2(db, sql2, strlen(sql2), &stmt, NULL);

	int pos = 0;
	cart->conciertos = (Concierto*)malloc(sizeof(Concierto) * cart->numConciertos);

	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{
			cart->conciertos[pos].cod = sqlite3_column_int(stmt, 0);
			cart->conciertos[pos].artista = malloc(sizeof(char) * sqlite3_column_bytes(stmt, 1));
			strcpy(cart->conciertos[pos].artista, (char*)sqlite3_column_text(stmt, 1));
			cart->conciertos[pos].escenario= sqlite3_column_int(stmt, 2);
			cart->conciertos[pos].dia = sqlite3_column_int(stmt, 3);
		}
		pos ++;

	} while (result == SQLITE_ROW);

	sqlite3_finalize(stmt);
}

/*
 * Imprime la cartelera del festival de dos formas diferentes
 */


void imprimirCartelera(sqlite3 *db,Cartelera *cart, int op)
{

	if (op == 1)
	{
		printf("\n\tCARTELERA\n");
		printf("--------------------------------\n\n");

		printf("  22 JULIO\n");
		for (int i = 0; i < cart->numConciertos; i++)
			if (cart->conciertos[i].dia == 1) printf("%s\n",cart->conciertos[i].artista );

		printf("\n  23 JULIO\n");
		for (int i = 0; i < cart->numConciertos; i++)
			if (cart->conciertos[i].dia == 2) printf("%s\n",cart->conciertos[i].artista );
	}

	if (op == 2)
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
}

/* ==================================================
 * 					OTROS
 * ==================================================
 */

/*
 * Recupera los datos de la tabla escenarios de la bd
 */

void selectEscenarios(sqlite3 *db)
{
	sqlite3_stmt *stmt;
	int result;

	char sql[] = "SELECT * FROM ESCENARIO";
	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

	printf("\n\tESCENARIOS\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
			printf("\t%i -  %s\n", sqlite3_column_int(stmt, 0), (char*) sqlite3_column_text(stmt, 1));

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

	char sql[] = "SELECT * FROM DIA";
	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

	printf("\n\tD�AS\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
			printf("\t%i -  %s\n", sqlite3_column_int(stmt, 0), (char*) sqlite3_column_text(stmt, 1));

	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);
}

