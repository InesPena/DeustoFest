#include <stdio.h>

/**
 * Menú que muestra las principales funciones del programa
 */

int menuDF()
{
	int op;

	printf("\n\tDEUSTOFEST\n\n");
    printf("1. Consultar Cartelera\n");
    printf("2. Comprar Entradas\n");
    printf("3. Servicios Adicionales\n");
    printf("4. Salir\n");

    printf("\nOpción: ");
    scanf("%d", &op);

    return op;
}

/**
 * Menú que muestra los tipos de entradas disponibles a comprar
 */

int menuEntrada()
{
	int op;

	printf("\n\tCOMPRAR ENTRADAS\n\n");
    printf("1. Día 21.............40€\n");
    printf("2. Día 22.............38€\n");
    printf("3. Día 21 y 22........72€\n\n");
    printf("(Pulsar 'x' para volver al menú)\n");

    printf("\nOpción: ");
    scanf("%d", &op);

    return op;
}
