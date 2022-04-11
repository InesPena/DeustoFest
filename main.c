#include "entrada/entrada.h"
#include "cliente/cliente.h"
#include "concierto/concierto.h"
#include "puesto/puesto.h"

#include "properties/properties.h"
#include "logger/logger.h"
#include "sqlite3/sqlite3.h"

#include <stdio.h>
#include <stdlib.h>

void menu();
void menuAdmin();
void menuPlan();

void menuCliente();

int elegirOpcion();
int costes();
int beneficio(sqlite3 *db, ListaEntradas l);
void properties();

sqlite3 *db;
Properties prop;

Cartelera *pCart;
Cartelera cart;

ListaEntradas lEntradas[MAX_ENTRADAS];


/* ==================================================
 * 						MAIN
 * ==================================================
 */

int main()
{
	sqlite3_open("sqlite3/deustoFest.sqlite", &db);

	pCart = &cart;
	obtenerCartelera(db, pCart);

	properties();

	menu();

    return 0;
}


void menu()
{
	int op;

	do {
		printf("\n\n\tDEUSTOFEST\n");
		printf("--------------------------------\n\n");
		printf("1. Acceder como Cliente\n");
		printf("2. Acceder como Administrador\n");
		printf("3. Salir\n");

		op = elegirOpcion();

		switch (op) {

			case 1:
				menuCliente();
				break;

			case 2:
				menuAdmin();
				break;

			case 3:
				sqlite3_close(db);
				free(pCart);
				free(db);

				printf("\nSaliendo del programa...");
				break;
		}

	} while (op != 3);

}

/* ==================================================
 * 						ADMINISTRADOR
 * ==================================================
 */

void menuAdmin()
{
	int op;

	Cliente *pCl;
	Cliente cl;
	pCl = &cl;

	do {
		printf("\n\n\tADMINISTRADOR\n");
		printf("--------------------------------\n\n");
		printf("1. Planificar Festival\n");
		printf("2. Consultar programa\n");
		printf("3. Ver lista de puestos de comida/bebida\n");
		printf("4. Consultar datos de cliente\n");
		printf("5. Ver Estadísticas\n");
		printf("6. Volver atrás\n");

		op = elegirOpcion();

	    switch (op) {

	     	 case 1:
	     		menuPlan();
	     		break;

	         case 2:
	        	 imprimirCartelera(db, pCart, 2);
	        	 break;

	         case 3:
	        	 imprimirPuesto(db);
	             break;

	         case 4:
	        	 consultarDatosCliente(db, pCl);
	        	 break;

	         case 5:
	        	 printf("\tESTADÍSTICAS\n");
	        	 printf("--------------------------------\n\n");
				 printf("Asistencia = \t\t%.2f%% \n", porcentajeAsistencia(db));
				 printf("Ingreso total = \t%i\n", ingresos(lEntradas));
				 printf("Coste total = \t\t%i\n", costes(db));
				 printf("Beneficio total = \t%i\n", beneficio(db, *lEntradas));
				 break;

	         case 6:
	        	 free(pCl->nombre);
	        	 free(pCl->mail);
	        	 free(pCl);
	         	 break;

	         default:
	        	 printf("\n¡ERROR! La opción seleccionada no existe\n");
	        	 break;
	    }

	} while (op != 6);
}

/**
 * Menú Planifificación
 */

void menuPlan()
{
	int op;

	Concierto *pCon;
	Concierto con;
	pCon = &con;

	Puesto *pPu;
	Puesto pu;
	pPu = &pu;

	do {
		printf("\n\tPLANIFICAR FESTIVAL\n");
		printf("--------------------------------\n\n");
		printf("1. Organizar nuevo concierto\n");
		printf("2. Cancelar concierto\n");
		printf("3. Añadir puesto\n");
		printf("4. Eliminar puesto\n");
		printf("5. Volver atrás\n");

		op = elegirOpcion();

		switch (op) {

			case 1:
				printf("\nInserte los siguientes datos...\n\n");
				pedirDatosConcierto(db, pCon);
				insertarConcierto(db, pCon);
				break;

		    case 2:
		    	printf("\nInserte el código del concierto...\n\n");
		    	eliminarConcierto(db, pedirCodigoConcierto());
		    	break;

		    case 3:
		    	printf("\nInserte los siguientes datos...\n\n");
		    	pedirDatosPuesto(db, pPu);
		    	insertarPuesto(db, pPu);
		    	break;

		    case 4:
		    	printf("\nInserte el código del puesto...\n\n");
		    	imprimirPuesto(db);
		    	eliminarPuesto(db, pedirCodigoPuesto());
		    	break;

		    case 5:
		    	free(pCon->artista);
		    	free(pCon);
		    	free(pPu->marca);
		    	free(pPu);
		    	break;

		    default:
		    	printf("\n¡ERROR! La opción seleccionada no existe\n");
		    	break;
		}

	} while (op != 5);
}

/* ==================================================
 * 					CLIENTE
 * ==================================================
 */

void menuCliente()
{
	int op;

	Entrada *pEnt;
	Entrada ent;
	pEnt = &ent;

	Cliente *pCl;
	Cliente cl;
	pCl = &cl;

	do {
		printf("\n\n\tCLIENTE\n");
		printf("--------------------------------\n\n");
		printf("1. Consultar Cartelera\n");
		printf("2. Comprar Entradas\n");
		printf("3. Volver atrás\n");

		op = elegirOpcion();

		switch (op) {

			case 1:
				imprimirCartelera(db, pCart, 1);
				break;

			case 2:
				compraEntradas(pEnt, pCl);
				//insertCliente(db, &c);
				//insertEntrada(db, &e);

				break;

			case 3:
				free(pEnt);
				free(pCl->nombre);
				free(pCl->mail);
				free(pCl);
				break;

			default:
				printf("\n¡ERROR! La opción seleccionada no existe\n");
				break;
		}

	} while (op != 3);
}



/* ==================================================
 * 						OTRAS FUNCIONES
 * ==================================================
 */


int elegirOpcion()
{
	int op;

	printf("\nOpción: ");
	fflush(stdout);
	scanf("%i", &op);
	getchar();

	return op;
}

int ingresos()
{
	int ingresos=0;

	//for(int i=0; i<pEntradas.numEntradas;i++){
	//	ingresos += pEntradas.entradas[i].precio;
	//}

	return ingresos;
}

int costes(sqlite3 *db)
{
	return costesConciertos(db) - costesPuestos(db);


	/*sqlite3_stmt *stmt;
	int result;
	int costeEntradas = 0;
	int costePuestos = 0;

	char sql[] = "SELECT SUM(COSTE) FROM CONCIERTO";
	sqlite3_prepare_v2(db, sql, strlen(sql)+1, &stmt, NULL);
	result = sqlite3_step(stmt);
	if(result == SQLITE_ROW){
		costeEntradas = sqlite3_column_int(stmt, 0);
		sqlite3_finalize(stmt);
	}

	char sql2[] = "SELECT SUM(COSTE) FROM PUESTO";
	sqlite3_prepare_v2(db, sql2, strlen(sql2)+1, &stmt, NULL);
	result = sqlite3_step(stmt);
	if(result == SQLITE_ROW){
		costePuestos = sqlite3_column_int(stmt, 0);
		sqlite3_finalize(stmt);
	}

	int costeTotal = costeEntradas+costePuestos;

	return costeTotal;*/
}

int beneficio(sqlite3 *db, ListaEntradas l)
{
	return ingresos(l) - costes(db);
}

void properties()
{
	char **clave = malloc(sizeof(char*) * prop.num);
	clave[0] = "Ultima Conexión";
	clave[1] = "Opción seleccionada";
	prop.clave = clave;


	char **valor = malloc(sizeof(char*) * prop.num);
	valor[0] = "2022-03-12 18:30";
	valor[1] = "2";
	prop.valor = valor;

	crearProperties(&prop);

	/*Properties prop;
		FILE *file;
		if ((file = fopen("config.properties", "r"))) {
			fclose(file);
			cargarProperties(&prop, "config.properties");
		} else {
			int num = 2;
			char **clave = malloc(sizeof(char*) * num);
			clave[0] = "Ultima Conexión";
			clave[1] = "Opción seleccionada";


			char **valor = malloc(sizeof(char*) * num);
			valor[0] = "2022-03-12 18:30";
			valor[1] = "2";

			crearProperties(&prop, "config.properties");
		}*/
}
