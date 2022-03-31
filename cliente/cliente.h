#ifndef CLIENTE_CLIENTE_H_
#define CLIENTE_CLIENTE_H_

typedef struct{

	char dni[10];
	char *nom;
	char *mail;
	int edad;

} Cliente;

void selectCliente();

void imprimirCliente(Cliente c);

#endif /* CLIENTE_CLIENTE_H_ */
