#include "entrada/entrada.h"
#include "cliente/cliente.h"
#include "concierto/concierto.h"
#include "sqlite3/sqlite3.h"
#include "logger/logger.h"
#include "puesto/puesto.h"
#include "properties/properties.h"

#include <stdio.h>
#include <stdlib.h>

void menu();
void menuAdmin();
void menuPlan();

void menuCliente();

int elegirOpcion();
int costes(sqlite3 *db);
int beneficio(sqlite3 *db, ListaEntradas l);

sqlite3 *db;
Cartelera *cart;

ListaEntradas lEntradas[MAX_ENTRADAS];
ListaPuestos lPuestos[MAX_PUESTOS];



/* ==================================================
 * 						MAIN
 * ==================================================
 */

int main()
{
	sqlite3_open("sqlite3/deustoFest.sqlite", &db);

	Properties prop;
	FILE *file;
	if ((file = fopen("config.properties", "r"))) {
		fclose(file);
		cargarProperties(&prop, "config.properties");
	} else {
		int num = 2;
		char **clave = malloc(sizeof(char*) * num);
		clave[0] = "Ultima Conexi�n";
		clave[1] = "Opci�n seleccionada";


		char **valor = malloc(sizeof(char*) * num);
		valor[0] = "2022-03-12 18:30";
		valor[1] = "2";

		crearProperties(&prop, "config.properties");
	}

	obtenerCartelera(db, &cart);

	menu();

    return 0;
}


void menu()
{
	int op;

	do {
		printf("\n\n\tDEUSTOFEST\n");
		printf("--------------------------------\n\n");
		printf("1. Acceder como Cliente\n");
		printf("2. Acceder como Administrador\n");
		printf("3. Salir\n");

		op = elegirOpcion();

		switch (op) {

			case 1:
				menuCliente();
				break;

			case 2:
				menuAdmin();
				break;

			case 3:
				sqlite3_close(db);
				free(cart);
				printf("\nSaliendo del programa...");
				break;
		}

	} while (op != 3);

}

/* ==================================================
 * 						ADMINISTRADOR
 * ==================================================
 */

void menuAdmin()
{
	int op;
	Cliente *cl;
	ListaEntradas l;

	do {
		printf("\n\n\tADMINISTRADOR\n");
		printf("--------------------------------\n\n");
		printf("1. Planificar Festival\n");
		printf("2. Consultar programa\n");
		printf("3. Ver lista de puestos de comida/bebida\n");
		printf("4. Consultar datos de cliente\n");
		printf("5. Ver Estad�sticas\n");
		printf("6. Volver atr�s\n");

		op = elegirOpcion();

	    switch (op) {

	     	 case 1:
	     		menuPlan();
	     		break;

	         case 2:
	        	 imprimirCartelera(db, &cart, 2);
	        	 break;

	         case 3:
	        	 imprimirPuesto(db);
	             break;

	         case 4:
	        	 consultarDatosCliente(db, &cl);
	        	 break;

	         case 5:
	        	 printf("  ESTAD�STICAS\n");
				 ;
				 float porcentaje = porcentajeAsistencia(db);
				 printf("Asistencia = %.2f%% \n", porcentaje);
				 printf("Ingreso total = \n");
				 int coste = costes(db);
				 printf("Coste total = %i\n", coste);
				 int benef = beneficio(db, l);
				 printf("Beneficio total = %i\n", benef);
				 break;

	         case 6:
	         	 break;

	         default:
	        	 printf("\n�ERROR! La opci�n seleccionada no existe\n");
	        	 break;
	    }

	} while (op != 6);
}

/**
 * Men� Planifificaci�n
 */

void menuPlan()
{
	int op;

	Concierto *c;
	Puesto *p;

	do {
		printf("\n\tPLANIFICAR FESTIVAL\n");
		printf("--------------------------------\n\n");
		printf("1. Organizar nuevo concierto\n");
		printf("2. Cancelar concierto\n");
		printf("3. A�adir puesto\n");
		printf("4. Eliminar puesto\n");
		printf("5. Volver atr�s\n");

		op = elegirOpcion();

		switch (op) {

			case 1:
				printf("\nInserte los siguientes datos...\n\n");
				pedirDatosConcierto(db, &c);
				insertarConcierto(db, &c);
				break;

		    case 2:
		    	printf("\nInserte el c�digo del concierto...\n\n");
		    	eliminarConcierto(db, pedirCodigoConcierto());
		    	break;

		    case 3:
		    	printf("\nInserte los siguientes datos...\n\n");
		    	pedirDatosPuesto(db, &p);
		    	insertarPuesto(db, &p);
		    	break;

		    case 4:
		    	printf("\nInserte el c�digo del puesto...\n\n");
		    	imprimirPuesto(db);
		    	eliminarPuesto(db, pedirCodigoPuesto());
		    	break;

		    case 5:
		    	break;

		    default:
		    	printf("\n�ERROR! La opci�n seleccionada no existe\n");
		    	break;
		}

	} while (op != 5);
}

/* ==================================================
 * 					CLIENTE
 * ==================================================
 */

void menuCliente()
{
	int op;

	Entrada *e;
	Cliente *c;

	do {
		printf("\n\n\tCLIENTE\n");
		printf("--------------------------------\n\n");
		printf("1. Consultar Cartelera\n");
		printf("2. Comprar Entradas\n");
		printf("3. Volver atr�s\n");

		op = elegirOpcion();

		switch (op) {

			case 1:
				imprimirCartelera(db, &cart, 1);
				break;

			case 2:
				compraEntradas(&e, &c);
				//insertCliente(db, &c);
				//insertEntrada(db, &e);
				break;

			case 3:
				break;

			default:
				printf("\n�ERROR! La opci�n seleccionada no existe\n");
				break;
		}

	} while (op != 3);
}



/* ==================================================
 * 						OTRAS FUNCIONES
 * ==================================================
 */


int elegirOpcion()
{
	int op;

	printf("\nOpci�n: ");
	fflush(stdout);
	scanf("%i", &op);
	getchar();

	return op;
}

int ingresos(ListaEntradas l)
{

}

int costes(sqlite3 *db)
{
	sqlite3_stmt *stmt;
	int result;
	int costeEntradas = 0;
	int costePuestos = 0;

	char sql[] = "SELECT SUM(COSTE) FROM CONCIERTO";
	sqlite3_prepare_v2(db, sql, strlen(sql)+1, &stmt, NULL);
	result = sqlite3_step(stmt);
	if(result == SQLITE_ROW){
		costeEntradas = sqlite3_column_int(stmt, 0);
		sqlite3_finalize(stmt);
	}

	char sql2[] = "SELECT SUM(COSTE) FROM PUESTO";
	sqlite3_prepare_v2(db, sql2, strlen(sql2)+1, &stmt, NULL);
	result = sqlite3_step(stmt);
	if(result == SQLITE_ROW){
		costePuestos = sqlite3_column_int(stmt, 0);
		sqlite3_finalize(stmt);
	}

	int costeTotal = costeEntradas+costePuestos;

	return costeTotal;
}

int beneficio(sqlite3 *db, ListaEntradas l)
{
	int ing = ingresos(l);
	int cost = costes(db);

	int beneficio = ing - cost;
	return beneficio;
}




