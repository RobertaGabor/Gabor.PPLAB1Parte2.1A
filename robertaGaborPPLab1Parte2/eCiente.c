#include "eCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrarCliente(eCliente cliente)
{
    printf("\n%d    %c  %10s\n",cliente.id,cliente.sexo,cliente.nombre);
}

void mostrarClientes (eCliente clientes[],int tamCli)
{
    system("cls");
    printf("**********Listado de Clientes*********\n");
    printf(" ID       SEXO     CLIENTE\n");
    for(int i=0;i<tamCli;i++)
    {
            mostrarCliente(clientes[i]);
    }
}

int cargarDescripcionCliente(char descripcion[],int id,eCliente clientes[],int tamCli)
{
    int retorno=0;

    for(int i=0;i<tamCli;i++)
    {
        if(clientes[i].id==id)
        {
            strcpy(descripcion,clientes[i].nombre);
            retorno=1;
        }
    }

    return retorno;
}
