#include "entrada/entrada.h"
#include "cliente/cliente.h"
#include "artista/artista.h"

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

	do {
		system("cls");

		printf("\n\tDEUSTOFEST\n\n");
		printf("1. Modificar Cartelera\n");
		printf("2. Consultar datos de cliente\n");
		printf("3. Consultar datos de artista\n");
		printf("4. Estadísticas\n");
		printf("5. Salir\n");

		printf("\nOpción: ");
		fflush(stdout);
		scanf("%i", &op);

	    switch (op) {

	     	 case 1:
	     		subMenu();
	     		break;

	         case 2:
	        	 selectCliente();
	        	 break;

	         case 3:
	        	 selectArtista();
	             break;

	         case 4:
	             break;

	         default:
	        	printf("Error. La opción seleccionada no existe.\n");
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

	Artista a;

	do {
		system("cls");

		printf("\n\tDEUSTOFEST\n\n");
		printf("1. Añadir Artista\n");
		printf("2. Eliminar Artista\n");
		printf("3. Volver al menú rpincipal\n");

		printf("\nOpción: ");
		fflush(stdout);
		scanf("%i", &op);

		switch (op) {

			case 1:
				pedirDatosArtista(&a);
				insertarArtsita(a);
				break;

		    case 2:
		    	eliminarArtista(a);
		    	break;

		    default:
		    	printf("Error. La opción seleccionada no existe.\n");
				break;
		}
	} while (op != 3);
}







