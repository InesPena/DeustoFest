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
void imprimirClientes(sqlite3 *db)
{
	sqlite3_stmt *stmt;
	int result;

	char sql[] = "SELECT DNI, NOMBRE FROM CLIENTE";
	sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,NULL);

	printf("\n\tPUESTOS\n");
	do{
		result = sqlite3_step(stmt);
		if(result == SQLITE_ROW){
			printf("\t%s - %s\n", (char*)sqlite3_column_text(stmt,0), (char*)sqlite3_column_text(stmt,1));
		}
	}while(result == SQLITE_ROW);

	printf("\n");

	sqlite3_finalize(stmt);
}
void consultarDatosCliente(sqlite3 *db, Cliente *c){

	imprimirClientes(db);

	char dni;
	char str [MAX_LINE];
	printf ("DNI:\n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", &dni);
	strcpy(c->dni, &dni);

	sqlite3_stmt *stmt;
	int result;



	char sql[] = "SELECT CL.DNI, CL.NOMBRE, CL.MAIL, E.COD, E.CAMPING, E.BUS "
				"FROM CLIENTE CL, ENTRADA E "
				"WHERE CL.DNI=E.DNI AND CL.DNI = '11111111A'";

	sqlite3_prepare_v2(db, sql, strlen(sql)+1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, c->dni, strlen(c->dni), SQLITE_STATIC);

	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{
			printf("ENTRA");
			printf("\n\nDNI: \t%s", (char*)sqlite3_column_text(stmt, 0));
			printf("\nNOMBRE: \t%s", (char*)sqlite3_column_text(stmt, 1));
			printf("\nMAIL: \t%s\n", (char*)sqlite3_column_text(stmt, 2));
			printf("COD_E: \t%i", sqlite3_column_int(stmt, 3));

			printf("\nCAMPING: \t");
			if (sqlite3_column_int(stmt, 4) == 1) printf("SI");
			else printf("NO");

			printf("\nBUS: \t");
			if (sqlite3_column_int(stmt, 5) == 1) printf("SI");
			else printf("NO");
		}
	} while (result == SQLITE_ROW);
	printf("\n");

	char buffer[100];

	sprintf(buffer, "SELECT CL.DNI, CL.NOMBRE, CL.MAIL, E.COD, E.CAMPING, E.BUS "
			"FROM CLIENTE CL, ENTRADA E "
			"WHERE CLIENTE.DNI=ENTRADA.DNI AND CLIENTE.DNI = '%s'", c->dni);

	if (result != SQLITE_DONE) log(buffer, ERROR);
	else  log(buffer, INFO);

	sqlite3_finalize(stmt);


}


