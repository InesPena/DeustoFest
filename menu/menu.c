#include "../menu/menu.h"

#include <stdio.h>

int menu()
{
	int op;

	fflush(stdout);
	printf("\n\tDEUSTOFEST\n\n");
    printf("1. Modificar Cartelera\n");
    printf("2. Consultar datos de cliente\n");
    printf("3. Consultar datos de artista\n");
    printf("4. Estadísticas\n");
    printf("5. Salir\n");

    printf("\nOpción: ");
    fflush(stdout);
    scanf("%i", &op);

    return op;
}

int subMenu()
{
	int op;

	printf("\n\tDEUSTOFEST\n\n");
	printf("1. Añadir Artista\n");
	printf("2. Eliminar Artista\n");
	printf("3. Volver al menú rpincipal\n");

	printf("\nOpción: ");
	fflush(stdout);
	scanf("%i", &op);

	return op;
}


