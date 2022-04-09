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
	if (result != SQLITE_DONE)
		printf("Error al realizar la compra \n");

	sqlite3_finalize(stmt);
}

void consultarDatosCliente(sqlite3 *db, Cliente *c){

	sqlite3_stmt *stmt;
	char result;
	char dni;
	char str [MAX_LINE];

	printf ("Introduce el dni del cliente:\n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", &dni);
	strcpy(c->dni, &dni);

	char sql[] = "SELECT CLIENTE.DNI, CLIENTE.NOMBRE, CLIENTE.MAIL, ENTRADA.COD FROM CLIENTE, ENTRADA WHERE CLIENTE.DNI=ENTRADA.DNI AND CLIENTE.DNI = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, c-> dni, strlen(c-> dni), SQLITE_STATIC);

	do {
			result = sqlite3_step(stmt);
			if (result == SQLITE_ROW)
			{
		printf("%s\t\t", (char*)sqlite3_column_text(stmt, 0));
		printf("%s\t\t", (char*)sqlite3_column_text(stmt, 1));
		printf("%s\t\t", (char*)sqlite3_column_text(stmt, 2));
		printf("%s\t\t", (char*)sqlite3_column_text(stmt, 3));

			}
				} while (result == SQLITE_ROW);
				printf("\n");

			sqlite3_finalize(stmt);
			}
	//char dnic = sqlite3_column_int(stmt, 0);
	//char nombre = sqlite3_column_int(stmt, 1);
	//char  mail = sqlite3_column_int(stmt, 2);
	//char codigo = sqlite3_column_int(stmt, 3);//

	//printf("%s", dnic);
	//printf("%s", nombre);
	//printf("%s", mail);
	//printf("%s", codigo);


	/*if (result != SQLITE_DONE)
			printf("Error al consultar datos. \n");
	else
			printf(result);

		sqlite3_finalize(stmt);
*/



