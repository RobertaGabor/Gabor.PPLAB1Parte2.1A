#include "eColor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrarColor(eColor colores)
{
    printf("\n%d    %10s\n",colores.idColor,colores.descripcionColor);
}

void mostrarColores (eColor color[],int tamCol)
{
    system("cls");
    printf("**********Listado de Colores*********\n");
    printf(" ID          COLOR\n");
    for(int i=0;i<tamCol;i++)
    {
            mostrarColor(color[i]);
    }
}

int cargarDescripcionColor(char descripcion[],int id,eColor colores[],int tamCol)
{
    int retorno=0;

    for(int i=0;i<tamCol;i++)
    {
        if(colores[i].idColor==id)
        {
            strcpy(descripcion,colores[i].descripcionColor);
            retorno=1;
        }
    }

    return retorno;
}
