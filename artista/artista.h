#ifndef ARTISTA_H_
#define ARTISTA_H_

typedef struct{
	int cod[4];
	char *nombre;

} Artista;

void pedirDatosArtista(Artista *a);

void insertarArtsita(Artista a);

void eliminarArtista();

void selectArtsita();

void imprimirArtista(Artista a);

#endif
