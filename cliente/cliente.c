#include "cliente.h"
#include "../logger/logger.h"
#include "../sqlite3/sqlite3.h"

#define MAX_LINE 20

/*
 * Imprime los datos de un cliente
 */

void imprimirCliente(Cliente c)
{
	printf("Dni: %s, Nombre: %s, E-mail: %s", c.dni, c.nombre, c.mail);
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
	c->nombre = malloc((strlen(str) + 1) * sizeof(char));
	strcpy(c->nombre, str);

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
	sqlite3_bind_text(stmt, 2, c->nombre, strlen(c->nombre), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 3, c->mail, strlen(c->mail), SQLITE_STATIC);

	result = sqlite3_step(stmt);

	char buffer[100];
	sprintf(buffer, "INSERT INTO CLIENTE (DNI, NOMBRE, MAIL) VALUES ('%s', '%s', '%s')", c->nombre, c->nombre, c->mail);

	if (result != SQLITE_DONE) log(buffer, ERROR);
	else  log(buffer, INFO);

	sqlite3_finalize(stmt);
}

void consultarDatosCliente(sqlite3 *db, Cliente *c){

	char dni;
	char str [MAX_LINE];

	printf ("Introduce el dni del cliente:\n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", &dni);
	strcpy(c->dni, &dni);

	sqlite3_stmt *stmt;
	int result;

	char sql[] = "SELECT CLIENTE.DNI, CLIENTE.NOMBRE, CLIENTE.MAIL, ENTRADA.COD "
			"FROM CLIENTE, ENTRADA "
			"WHERE CLIENTE.DNI=ENTRADA.DNI AND CLIENTE.DNI = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql)+1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, c->dni, strlen(c->dni), SQLITE_STATIC);
	printf("DNI: \t\t\t");
	printf("NOMBRE: \t\t");
	printf("MAIL: \t\t\t");
	printf("COD_E: \t\t\t");
	printf("\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{

			printf("%s\t\t", (char*)sqlite3_column_text(stmt, 0));
			printf("%s\t\t", (char*)sqlite3_column_text(stmt, 1));
			printf("%s\t\t", (char*)sqlite3_column_text(stmt, 2));
			printf("%i\t\t", sqlite3_column_int(stmt, 3));

		}
		printf("\n");
	} while (result == SQLITE_ROW);


	sqlite3_finalize(stmt);
}
