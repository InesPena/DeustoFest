
#include "../sqlite3/sqlite3.h"

#include <stdio.h>
#include <string.h>

void insertarArtista(Artista a) {

	sqlite3 *db;
	sqlite3_stmt *st;
	int result;

	sqlite3_open("sqlite3/futbol.sqlite", &db);
}
