#include "entrada/entrada.h"
#include "cliente/cliente.h"
#include "concierto/concierto.h"
#include "sqlite3/sqlite3.h"
#include "logger/logger.h"
#include "puesto/puesto.h"

#include <stdio.h>
#include <stdlib.h>

void menu();
void menuAdmin();
void menuPlan();

void menuCliente();

int elegirOpcion();
float porcentajeAsistencia(ListaEntradas l);

sqlite3 *db;
Cartelera *cart;



/* ==================================================
 * 						MAIN
 * ==================================================
 */

int main()
{
	sqlite3_open("sqlite3/deustoFest.sqlite", &db);

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

	do {
		printf("\n\n\tADMINISTRADOR\n");
		printf("--------------------------------\n\n");
		printf("1. Planificar Festival\n");
		printf("2. Consultar programa\n");
		printf("3. Ver lista de puestos de comida/bebida\n");
		printf("4. Consultar datos de cliente\n");
		printf("5. Ver Estadísticas\n");
		printf("6. Volver atrás\n");

		op = elegirOpcion();

	    switch (op) {

	     	 case 1:
	     		menuPlan();
	     		break;

	         case 2:
	        	 imprimirCartelera(db, &cart, 2);
	        	 break;

	         case 3:
	             break;

	         case 4:
	        	 break;

	         case 5:
	        	 printf("  ESTADÍSTICAS\n");
	        	 printf("Asistencia (%%) = \n");
	        	 printf("Reacudación total = \n");
	             break;

	         case 6:
	         	 break;

	         default:
	        	 printf("\n¡ERROR! La opción seleccionada no existe\n");
	        	 break;
	    }

	} while (op != 6);
}

/**
 * Menú Planifificación
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
		printf("3. Añadir puesto\n");
		printf("4. Eliminar puesto\n");
		printf("5. Volver atrás\n");

		op = elegirOpcion();

		switch (op) {

			case 1:
				printf("\nInserte los siguientes datos...\n\n");
				pedirDatosConcierto(db, &c);
				insertarConcierto(db, &c);
				break;

		    case 2:
		    	printf("\nInserte el código del concierto...\n\n");
		    	eliminarConcierto(db, pedirCodigoConcierto());
		    	break;

		    case 3:
		    	break;

		    case 4:
		    	break;

		    case 5:
		    	break;

		    default:
		    	printf("\n¡ERROR! La opción seleccionada no existe\n");
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
		printf("3. Volver atrás\n");

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
				printf("\n¡ERROR! La opción seleccionada no existe\n");
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

	printf("\nOpción: ");
	fflush(stdout);
	scanf("%i", &op);
	getchar();

	return op;
}

float porcentajeAsistencia(ListaEntradas l)
{

}

int ingresos(ListaEntradas l)
{

}



int beneficio()
{

}



