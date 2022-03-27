#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "entrada/entrada.h"
#include "cliente/cliente.h"
#include "artista/artista.h"

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

    int op;
    int op2;
    
    TIPO_ENTRADA tipoEntrada;

    do {
    	system("cls");
        op = menuPrincipal();
        
        switch (op) {
        	
            case 1:
            	mostrarCartelera();
                system("pause>nul"); 
                break;
                
            case 2:
        		system("cls");
        		
        		if (numEntrada < 100) {
        			op2 = elegirEntrada();
        			
        			if (op2 == 1) tipoEntrada = TIPO_A;
        			if (op2 == 2) tipoEntrada = TIPO_B;
        			if (op2 == 3) tipoEntrada = TIPO_O;



        			system("cls");
        			
        			pedirDatos();
        			
				} else {
					printf("No quedan entradas disponibles");
				}
				
                system("pause>nul"); 
                break;
                
            case 3:
                system("pause>nul");           
                break;
                
            case 4:
                system("pause>nul");              
                break;
            
            default:
            	printf("Error. La opci�n seleccionada no existe.\n");
            	system("pause>nul"); 
				break;   
        }        
    } while (op != 4);
	 
    return 0;
}

/**
* Pedir datos personales para realizar la compra
*/

void pedirDatos(Cliente *cliente)
{
	char str[MAX_LINE];

	char *nom;
	char dni[10];
	char *mail;

	printf("Iniciando proceso de compra...\n\n");

	printf("Nombre: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", &nom);
	cliente->nom = nom;

	printf("DNI: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", &dni);
	cliente->dni = dni;

	printf("E-mail: ");

}

/**
* Muestra el men� principal y devuleve la opci�n elegida
*/

int menuPrincipal()
{
	int op;
	
	printf("\n\tDEUSTOFEST\n\n");
    printf("1. Consultar Cartelera\n");
    printf("2. Comprar Entradas\n");
    printf("3. Servicios Adicionales\n");
    printf("4. Salir\n");
        
    printf("\nOpci�n: ");
    scanf("%d", &op);
    
    return op;	
}

/**
* Muestra los tipos de entradas y devuelve el tipo elegido
*/

int elegirEntrada()
{
	int op;
	
	printf("\n\tCOMPRAR ENTRADAS\n\n");
    printf("1. D�a 21.............40�\n");
    printf("2. D�a 22.............38�\n");
    printf("3. D�a 21 y 22........72�\n\n");
    printf("(Pulsar 'x' para volver al men�)\n");
        
    printf("\nOpci�n: ");
    scanf("%d", &op);
    
    return op;	
}

/**
* Muestra un lsitado de los d�as que dura el festival y los cantantes que actuan cada d�a
*/

void mostrarCartelera() 
{
	
}





