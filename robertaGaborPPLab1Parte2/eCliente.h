#ifndef ECLIENTE_H_INCLUDED
#define ECLIENTE_H_INCLUDED

typedef struct{

int id;
char sexo;
char nombre[20];

}eCliente;

void mostrarCliente(eCliente cliente);
void mostrarClientes (eCliente clientes[],int tamCli);
int cargarDescripcionCliente(char descripcion[],int id,eCliente clientes[],int tamCli);

#endif // ECLIENTE_H_INCLUDED
