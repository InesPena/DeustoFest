#include "entrada.h"

void imprimirEntrada(Entrada e)
{


}

/* REVISAR */

/*
 * Recupera los datos de la tabla entrada de la bd y crea devuleve una estructura
 * afroro formada por un array con las entradas y el número de entradas
 */

Aforo selectEntradas(sqlite3 *db)
{
	Aforo a;
	a.numEntradas = 0;

	sqlite3_stmt *stmt;
	int result;

	char sql[] = "SELECT * FROM entrada";
	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{

			a.entradas[result].cod = sqlite3_column_int(stmt, 0);
			strcpy(a.entradas[result].dni, (char*)sqlite3_column_text(stmt, 1));
			a.entradas[result].camping = sqlite3_column_int(stmt, 2);
			a.entradas[result].bus = sqlite3_column_int(stmt, 3);
			//a.entradas[result].precio = (float)sqlite3_column__int(stmt, 4);

			a.numEntradas ++;
		}

	} while (result == SQLITE_ROW);

	sqlite3_finalize(stmt);

	return a;
}

/*
 * Calcula el porcentaje de asistencia al festival
 */

float calcularAsistencia(Aforo a)
{

}

/*
 * Calcula el total de ingresos recaudados por el festival
 */

float calcularIngersos(Aforo a)
{
	float ingresos = 0;

	for (int i = 0; i < a.numEntradas; i++)
	{

	}

	return ingresos;
}
