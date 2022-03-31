#ifndef ARTISTA_H_
#define ARTISTA_H_

typedef struct{
	int cod[4];
	char *nomb;

} Artista;

void pedirDatosArtista(Artista *a);

void insertarArtsita(Artista a);

void eliminarArtsita(char *cod);

void selectArtsita(char *cod)

void imprimirArtista(Artista a);

#endif
