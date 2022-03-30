#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "entrada/entrada.h"
#include "cliente/cliente.h"
#include "artista/artista.h"
#include "meun/menu.h"

#define MAX_LINE 20
#define MAX_ENTRADAS 100

/**
* Main
*/

int main()
{
	setlocale(LC_ALL, "spanish");
	
	Entrada entrada[100];
	int numEntrada = 0;
	
	Cliente listaClientes[100];
	int numCliente = 0;
    


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
	        op = menuDF();

	        switch (op) {

	            case 1:
	                system("pause>nul");
	                break;

	            case 2:
	            	comprarEntrada();
	                system("pause>nul");
	                break;

	            case 3:
	                system("pause>nul");
	                break;

	            case 4:
	                system("pause>nul");
	                break;

	            default:
	            	printf("Error. La opción seleccionada no existe.\n");
	            	system("pause>nul");
					break;
	        }
	    } while (op != 4);
}

void comprarEntradas()
{
	int op;
	op = menuEntrada();

	pedirDatosCliente();
}





