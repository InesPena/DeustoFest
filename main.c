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
 * Men� principal
 */

void menu ()
{
	int op;

	do {
		printf("\n\n\tDEUSTOFEST\n");
		printf("--------------------------------\n\n");
		printf("1. Modificar Cartelera\n");
		printf("2. Consultar lista de clientes\n");
		printf("3. Consultar lista de artistas\n");
		printf("4. Estad�sticas\n");
		printf("5. Salir\n");

		printf("\nOpci�n: ");
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
	        	 printf("\n�ERROR! La opci�n seleccionada no existe");
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
		printf("\n\n     MODIFICAR CARTELERA \n");
		printf("--------------------------------\n\n");
		printf("1. Organizar nuevo concierto\n");
		printf("2. Cancelar concierto\n");
		printf("3. Volver al men� pincipal\n");

		printf("\nOpci�n: ");
		fflush(stdout);
		scanf("%i", &op);
		getchar();

		switch (op) {

			case 1:
				printf("\nInserte los siguientes datos...\n\n");
				pedirDatosConcierto(db, &c);
				insertarConcierto(db, &c);
				break;

		    case 2:
		    	imprimirCartelera(db);

		    	printf("\nInserte el c�digo del concierto...\n\n");
		    	eliminarConcierto(db, pedirCodigoConcierto());
		    	break;

		    case 3:
		    	break;

		    default:
		    	printf("\n�ERROR! La opci�n seleccionada no existe");
		    	break;
		}

	} while (op != 3);
}


