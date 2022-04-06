#ifndef PUESTO_PUESTO_H_
#define PUESTO_PUESTO_H_

#define MAX_PUESTOS 20

typedef struct
{
	int dod;
	char *marca;
	int coste;

} Puesto;

typedef struct
{
	int numnumPuestos;
	Puesto *puestos;

} ListaPuestos;


#endif /* PUESTO_PUESTO_H_ */
