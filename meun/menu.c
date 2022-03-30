#include <stdio.h>

/**
 * Men� que muestra las principales funciones del programa
 */

int menuDF()
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
 * Men� que muestra los tipos de entradas disponibles a comprar
 */

int menuEntrada()
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
