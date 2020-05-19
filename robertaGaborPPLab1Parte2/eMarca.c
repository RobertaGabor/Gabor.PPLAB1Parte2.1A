#include "eMarca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarMarca(eMarca marcas)
{
    printf("\n%d    %10s\n",marcas.idMarca,marcas.descripcionMarca);

}
void mostrarMarcas (eMarca marca[],int tamMar)
{
    system("cls");
    printf("**********Listado de Marcas*********\n");
    printf(" ID         MARCA\n");
    for(int i=0;i<tamMar;i++)
    {
            mostrarMarca(marca[i]);
    }
}
int cargarDescripcionMarca(char descripcion[],int id,eMarca marcas[],int tamMar)
{
    int retorno=0;

    for(int i=0;i<tamMar;i++)
    {
        if(marcas[i].idMarca==id)
        {
            strcpy(descripcion,marcas[i].descripcionMarca);
            retorno=1;
        }
    }

    return retorno;
}
