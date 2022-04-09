#include "puesto.h"
#include "../sqlite3/sqlite3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 20

/*
 * Pide el c�digo de un puesto por consola
 */
int pedirCodigoPuesto(){
	int cod;
	char str[MAX_LINE];

	printf("Cod. Puesto: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &cod);

	return cod;
}

/*
 *Pide los datos relativos a un puesto por consola
 */
void pedirDatosPuesto(sqlite3 *db, Puesto *p){
	char str[MAX_LINE];

	printf("Nombre de la marca: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", str);
	p->marca = malloc((strlen(str) + 1)*sizeof(char));

	printf("Coste del puesto: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &p->coste);
}

/*
 * Inserta una nueva fila en la tabla puesto de la bd
 */
void insertarPuesto(sqlite3 *db, Puesto *p){

	sqlite3_stmt *stmt;
	int result;

	char sql[] = "INSERT INTO PUESTO(MARCA, COSTE) VALUES (?,?)";

	sqlite3_prepare_v2(db, sql,strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_text(stmt, 1, p->marca, strlen(p->marca), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 2, p->coste);

	result = sqlite3_step(stmt);

	if(result != SQLITE_DONE){
		printf("Error a�adiendo puesto\n");
	}else{
		printf("Puesto a�adido correctamente\n");
	}

	sqlite3_finalize(stmt);

}
/*
 * Elimina uns puesto de la bd
 */
void eliminarPuesto(sqlite3 *db, int cod){

	sqlite3_stmt *stmt;
	int result;

	char sql[] = "DELETE FROM PUESTO WHERE COD = ?";

	sqlite3_prepare_v2(db, sql,	strlen(sql), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, cod);

	result = sqlite3_step(stmt);

	if(result != SQLITE_DONE){
		printf("Error eliminando puesto\n");
	}else{
		printf("Puesto eliminado correctamente\n");
	}

	sqlite3_finalize(stmt);
}