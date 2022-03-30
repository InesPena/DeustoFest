#ifndef ACTUACION_ACTUACION_H_
#define ACTUACION_ACTUACION_H_

#include "../artista/artista.h"

typedef enum {
	ESCENARIO_1,
	ESCENARIO_2,
	ESCENARIO_3,
	ESCENARIO_4,

}ESCENARIO;

typedef struct {
	int cod;
	char *fecha;
	ESCENARIO esc;
	Artista artista;


}Actuacion ;

#endif /* ACTUACION_ACTUACION_H_ */
