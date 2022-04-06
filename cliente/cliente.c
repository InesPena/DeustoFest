#include "cliente.h"
#include "../sqlite3/sqlite3.h"

#define MAX_LINE 20

/*
 * Imprime los datos de un cliente
 */

void imprimirCliente(Cliente c)
{

}

/*
 * Pide los datos de un cliente por pantalla
 */

void pedirDatosCliente(Cliente *c)
{
	char str[MAX_LINE];

	printf("DNI: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", str);
	strcpy(c->dni, str);

	printf("Nombre: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", str);
	c->nom = malloc((strlen(str) + 1) * sizeof(char));
	strcpy(c->nom, str);

	printf("E-Mail: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", str);
	c->mail = malloc((strlen(str) + 1) * sizeof(char));
	strcpy(c->mail, str);
}

/*
 * Inserta una nueva fila en la tabla cliente
 */

void insertCliente(sqlite3 *db, Cliente *c)
{
	sqlite3_stmt *stmt;
	int result;

	char sql[] = "INSERT INTO CLIENTE (dni, nombre, mail) VALUES (?, ?, ?)";

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_text(stmt, 1, c->dni, strlen(c->dni), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, c->nom, strlen(c->nom), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 3, c->mail, strlen(c->mail), SQLITE_STATIC);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
		printf("Error al realizar la compra \n");

	sqlite3_finalize(stmt);
}

