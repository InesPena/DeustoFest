#include "entrada.h"
#include "../cliente/cliente.h"

#define PRECIO_CAMP 35
#define PRECIO_BUS 47

/*
 * Imprime los datos de una entrada por pantalla
 */

void imprimirEntrada(Entrada e)
{



}

/*
 * Calcula el precio de la entrada en función de el tipo de entrada,
 * si se ha elegido bus y si se ha elegido camping
 */

int calularPrecio(Entrada *e, int precioEnt)
{
	int precioTotal = 0;

	precioTotal += precioEnt;
	if (e->camping == 1)  precioTotal += PRECIO_CAMP;
	if (e->bus == 1) precioTotal += PRECIO_BUS;

	return precioTotal;
}

/*
 * Proceso para la compra de entradas
 */

void compraEntradas(Entrada *e, Cliente *c)
{
	int op;
	int precioEnt;

	e->camping = 0;
	e->bus = 0;

	printf("\n\n\tENTRADAS\n");
	printf("--------------------------------\n\n");
	printf("1. Entrada Día 22............75€\n");
	printf("2. Entrada Día 23............80€\n");
	printf("3. Abono completo...........142€\n");

	op = elegirOpcion();

	if (op == 1) precioEnt = 75;
	if (op == 2) precioEnt = 80;
	if (op == 3) precioEnt = 90;

	char op2;
	char op3;

	printf("¿Desa reservar una plaza de camping? (s/n) ");
	fflush(stdout);
	scanf("%c",&op2);
	getchar();
	if (op2 == 's') e->camping = 1;

	printf("¿Desa reservar una plaza de autobus? (s/n) ");
	fflush(stdout);
	scanf("%c",&op3);
	getchar();

	if (op3 == 's') e->bus = 1;

	e->precio = calularPrecio(&e, precioEnt);

	printf("\nIntroduzca sus datos personales...\n\n");

	pedirDatosCliente(c);
	strcpy(e->dni, c->dni);
}

/*
 * Inserta una fila en la tabla entrada
 */

void insertEntrada(sqlite3 *db, Entrada *e)
{
	sqlite3_stmt *stmt;
	int result;

	char sql[] = "INSERT INTO CLIENTE (dni, camping, bus, precio) VALUES (?, ?, ?, ?)";

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_text(stmt, 1, e->dni, strlen(e->dni), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 2, e->camping);
	sqlite3_bind_int(stmt, 3, e->bus);
	sqlite3_bind_int(stmt, 4, e->precio);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
		printf("Error al realizar la compra\n");
	else
		printf("Compra completada\n");

	sqlite3_finalize(stmt);
}
