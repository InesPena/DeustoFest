#ifndef CLIENTE_CLIENTE_H_
#define CLIENTE_CLIENTE_H_

typedef struct{

	char dni[10];
	char *nom;
	char *mail;
	int edad;

} Cliente;

void selectCliente(char dni[10]);

void imprimirCliente(Cliente c);

#endif /* CLIENTE_CLIENTE_H_ */
