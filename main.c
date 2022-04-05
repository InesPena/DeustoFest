#include "entrada/entrada.h"
#include "cliente/cliente.h"
#include "concierto/concierto.h"
#include "sqlite3/sqlite3.h"

#include <stdio.h>
#include <stdlib.h>

void menu();
void subMenu();

sqlite3 *db;

/**
* Main
*/

int main()
{
	sqlite3_open("sqlite3/deustoFest.sqlite", &db);

    menu();

    return 0;
}

/**
 * Menú principal
 */

void menu ()
{
	int op;

	char *dni;

	do {
		printf("\n\n\tDEUSTOFEST\n");
		printf("--------------------------------\n\n");
		printf("1. Modificar Cartelera\n");
		printf("2. Consultar lista de clientes\n");
		printf("3. Consultar lista de artistas\n");
		printf("4. Estadísticas\n");
		printf("5. Salir\n");

		printf("\nOpción: ");
		fflush(stdout);
		scanf("%i", &op);
		getchar();

	    switch (op) {

	     	 case 1:
	     		subMenu();
	     		break;

	         case 2:
	        	 break;

	         case 3:
	        	 selectArtista(&dni);
	             break;

	         case 4:
	        	 printf("  ESTADÍSTICAS\n");
	        	 printf("Asistencia (%) = \n");
	        	 printf("Reacudación total = \n");
	             break;

	         case 5:
	         	 printf("\nSaliendo del programa...");
	         	 break;

	         default:
	        	 printf("\n¡ERROR! La opción seleccionada no existe");
	        	 break;
	    }

	} while (op != 5);
}

/**
 * SubMenu
 */

void subMenu()
{
	int op;

	Concierto *c;

	do {
		printf("\n\n      MODIFICAR CARTELERA \n");
		printf("--------------------------------\n\n");
		printf("1. Organizar nuevo concierto\n");
		printf("2. Cancelar concierto\n");
		printf("3. Volver al menú pincipal\n");

		printf("\nOpción: ");
		fflush(stdout);
		scanf("%i", &op);
		getchar();

		switch (op) {

			case 1:
				printf("\nInserte los siguientes datos...\n\n");
				pedirDatosConcierto(&c);
				insertarConcierto(&db, *c);
				break;

		    case 2:

		    	break;

		    default:
		    	printf("\n¡ERROR! La opción seleccionada no existe");
		    	break;
		}

	} while (op != 3);
}


