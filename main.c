#include "entrada/entrada.h"
#include "cliente/cliente.h"
#include "concierto/concierto.h"
#include "sqlite3/sqlite3.h"
#include "logger/logger.h"

#include <stdio.h>
#include <stdlib.h>

void menu();
void menuAdmin();
void menuPlan();

void menuCliente();

int elegirOpcion();

sqlite3 *db;
Cartelera *cart;

/* ==================================================
 * 						MAIN
 * ==================================================
 */

int main()
{
	sqlite3_open("sqlite3/deustoFest.sqlite", &db);

	log("prueba");

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
		}

	}while (op != 3);

}

/* ==================================================
 * 						ADMINISTRADOR
 * ==================================================
 */

void menuAdmin()
{
	int op;

	do {
		printf("\n\n\tADMINISTRADOR\n");
		printf("--------------------------------\n\n");
		printf("1. Planificar Festival\n");
		printf("2. Consultar lista de clientes\n");
		printf("3. Consultar lista de artistas\n");
		printf("4. Estad�sticas\n");
		printf("5. Volver atr�s\n");

		op = elegirOpcion();

	    switch (op) {

	     	 case 1:
	     		menuPlan();
	     		break;

	         case 2:
	        	 break;

	         case 3:
	             break;

	         case 4:
	        	 printf("  ESTAD�STICAS\n");
	        	 printf("Asistencia (%%) = \n");
	        	 printf("Reacudaci�n total = \n");
	             break;

	         case 5:
	        	 sqlite3_close(db);
	         	 printf("\nSaliendo del programa...");
	         	 break;

	         default:
	        	 printf("\n�ERROR! La opci�n seleccionada no existe\n");
	        	 break;
	    }

	} while (op != 5);
}

/**
 * Men� Planifificaci�n
 */

void menuPlan()
{
	int op;

	Concierto *c;

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
		    	imprimirCartelera(db, &cart, 2);

		    	printf("\nInserte el c�digo del concierto...\n\n");
		    	eliminarConcierto(db, pedirCodigoConcierto());
		    	break;

		    case 3:
		    	break;

		    case 4:
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
				insertCliente(db, &c);
				insertEntrada(db, &e);
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


