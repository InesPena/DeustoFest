#include "entrada/entrada.h"
#include "cliente/cliente.h"
#include "artista/artista.h"
#include "concierto/concierto.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu();
void subMenu();

/**
* Main
*/

int main()
{
	setlocale(LC_ALL, "spanish");

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
		printf("2. Consultar datos de cliente\n");
		printf("3. Consultar datos de artista\n");
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

	Artista *a;
	Concierto *c;

	do {
		printf("\n\n      MODIFICAR CARTELERA \n");
		printf("--------------------------------\n\n");
		printf("1. Organizar nuevo concierto\n");
		printf("2. Cancelar concierto\n");
		printf("3. Volver al menú rpincipal\n");

		printf("\nOpción: ");
		fflush(stdout);
		scanf("%i", &op);
		getchar();

		switch (op) {

			case 1:
				printf("\nInserte los siguientes datos...\n\n");
				pedirDatosConcierto(&c, &a);

				break;

		    case 2:
		    	eliminarArtista();
		    	break;
		}

	} while (op != 3);
}







