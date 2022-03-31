#include <stdio.h>

#include "artista.h"
#include "../sqlite3/sqlite3.h"

#define MAX_LINE 20

/**
 * Pide los datos de un artista por consola
 */

void pedirDatosArtista(Artista *a)
{
	char str[MAX_LINE];

	printf("Codigo: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", a->cod);
	free(str);

	printf("Nombre: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", str);
	a->nombre = malloc((strlen(str) + 1) * sizeof(char));
	strcpy(a->nombre, str);
	free(str);
}

/**
 * Inserta un artista en la base de datos
 */

void insertarArtsita(Artista a)
{

	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;

	sqlite3_open("sqlite3/deustoFest.sqlite", &db);

	char sql[] = "INSERT INTO artista (cod, nombre) VALUES (?, ?)";

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_text(stmt, 1, a.cod, strlen(a.cod), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, a.nombre, strlen(a.nombre), SQLITE_STATIC);

	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE)
		printf("Error añadiendo artista\n");
	else
		printf("Artista añadido correctamente\n");

	sqlite3_finalize(stmt);
}

/**
 * Pide el código de un artista y lo elimina de la base de datos
 */

void eliminarArtista()
{

}

/**
 * Recupera los datos del un artista determinado de la bd
 */

void selectArtista()
{

}

/**
 * Imprime los datos de una artista
 */

void imprimirArtista(Artista a)
{
	printf("Dni: %s\n, Nombre: %s\n%s\n", a.cod, a.nombre);
}

