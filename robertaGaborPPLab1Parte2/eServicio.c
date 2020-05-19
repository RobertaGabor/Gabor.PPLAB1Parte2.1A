#include "eServicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarServicio(eServicio servicios)
{
    printf("\n%d    %10s     $%2.f\n",servicios.idServicio,servicios.descripcionServicio,servicios.precio);
}

void mostrarServicios (eServicio servicios[],int tamServ)
{
    system("cls");
    printf("**********Listado de Servicios*********\n");
    printf(" ID         SERVICIO   PRECIO\n");
    for(int i=0;i<tamServ;i++)
    {
            mostrarServicio(servicios[i]);
    }
}

int cargarDescripcionServicio(char descripcion[],int id,eServicio servicio[],int tamSer)
{
    int retorno=0;

    for(int i=0;i<tamSer;i++)
    {
        if(servicio[i].idServicio==id)
        {
            strcpy(descripcion,servicio[i].descripcionServicio);
            retorno=1;
        }
    }
    return retorno;
}
