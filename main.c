#include "entrada/entrada.h"
#include "cliente/cliente.h"
#include "menu/menu.h"
#include "baseDatos/gestorBD.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_LINE 20
#define MAX_ENTRADAS 100

void buclePrincipal();
void bucleSecundario();

/**
* Main
*/

int main()
{
	setlocale(LC_ALL, "spanish");

    buclePrincipal();

    return 0;
}

/**
 * Bucle que contiene el menú principal
 */

void buclePrincipal()
{
	int op;

	do {
		system("cls");
	    op = menu();

	     switch (op) {

	     	 case 1:
	     		bucleSecundario();
	     		break;

	         case 2:
	        	 break;

	         case 3:
	             break;

	         case 4:
	             break;

	         default:
	        	printf("Error. La opción seleccionada no existe.\n");
				break;
	    }
	} while (op != 5);
}

void bucleSecundario()
{
	int op;

	do {
		system("cls");
		op = subMenu();

		switch (op) {

			case 1:
				break;

		    case 2:
		    	break;

		    case 3:
		         break;

		    default:
		    	printf("Error. La opción seleccionada no existe.\n");
				break;
		}
	} while (op != 3);
}







