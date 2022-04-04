#include "cliente.h"
#include "../sqlite3/sqlite3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Recupera los datos del un cliente determinado de la bd
 */

Cliente* selectCliente(char *dni)
{
	Cliente *c;

	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;

	sqlite3_open("sqlite3/deustoFest.sqlite", &db);

	char sql[] = "SELECT * FROM cliente WHERE dni=?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);

	do {
		result = sqlite3_step(stmt);

		if (result == SQLITE_ROW)
		{
			//c->dni = (char *) sqlite3_column_text(stmt, 0);
			c->edad = (int) sqlite3_column_text(stmt, 1);
			c->mail = (char*) sqlite3_column_text(stmt, 2);
			c->nom = (char*)sqlite3_column_text(stmt, 0);
		}

	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);
	sqlite3_close(db);

	return &c;
}

/**
 * Imprime los datos de un cliente
 */

void imprimirCliente(Cliente c)
{

}

