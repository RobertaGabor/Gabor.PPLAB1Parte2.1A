#include "eAuto.h"
#include "eColor.h"
#include "eMarca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMCOLORES 5
#define TAMSMARCAS 5
#define TAMAUTOS 1000
#include "validaciones.h"

int buscarPatenteAuto(char patente[],eAuto autos[],int tamAu)
{
    int indice=-1;
    for(int i=0;i<tamAu;i++)
    {
        if((strcmp(autos[i].patente,patente)==0)&&autos[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void ordenarAutos (eAuto autos[],int tamAu,eMarca marcas[],int tamMar)
{
    eAuto auxiliar;
    char marcaI[20];
    char marcaJ[20];

    for(int i=0;i<tamAu-1;i++)
    {
        cargarDescripcionMarca(marcaI,autos[i].idMarca,marcas,tamMar);
        for(int j=i+1;j<tamAu;j++)
        {
            cargarDescripcionMarca(marcaJ,autos[j].idMarca,marcas,tamMar);
            if(strcmp(marcaI,marcaJ)>0)
            {
                auxiliar=autos[i];
                autos[i]=autos[j];
                autos[j]=auxiliar;
            }
            else
            {
                 if((strcmp(marcaI,marcaJ)==0)&&(strcmp(autos[i].patente,autos[j].patente)>0))
                {
                    auxiliar=autos[i];
                    autos[i]=autos[j];
                    autos[j]=auxiliar;
                }
            }
        }
    }
}

void mostrarAutos (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    system("cls");
    printf("**********Listado de Autos*********\n");
    printf(" ID         COLOR       MARCA   MODELO    PATENTE     CLIENTE\n");
    for(int i=0;i<tamAu;i++)
    {
        if(autos[i].isEmpty==0)
        {
             mostrarAuto(autos[i],colores,tamCol,marcas,tamMar,clientes,tamCli);
        }

    }
}

void bajaAuto(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    int indiceID;
    char patente[20];
    char confirmacion='s';

    system("cls");
    printf("*********Baja de Auto********\n");

    if(getPatente(patente,20,"Ingrese patente: ","Error ingrese una cadena valida",1))
    {
        indiceID=buscarPatenteAuto(patente,autos,tamAu);
        if(indiceID==-1)
        {
            printf("\n*****No se encontro la patente o esta dado de baja*****\n");
        }
        else
        {
            printf("ID         COLOR      MARCA    MODELO     PATENTE\n");
            mostrarAuto(autos[indiceID],colores,tamCol,marcas,tamMar,clientes,tamCli);
            printf("\n\nDesea comfirmar baja?: \n");
            printf("s - para confirmar\n");
            fflush(stdin);
            scanf("%c",&confirmacion);

            if(confirmacion=='s')
            {
                autos[indiceID].isEmpty=1;
                printf("\n\n****Removido exitosamente***\n");
            }
            else
            {
                printf("\n*****Operacion cancelada*****\n");
            }
        }
    }

}

void mostrarAuto(eAuto autos,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    char marca[20];
    char color[20];
    char cliente[20];
    cargarDescripcionColor(color,autos.idColor,colores,tamCol);
    cargarDescripcionMarca(marca,autos.idMarca,marcas,tamMar);
    cargarDescripcionCliente(cliente,autos.idCliente,clientes,tamCli);

    printf("\n%2.d    %10s   %10s    %d  %10s  %10s\n\n",autos.idAuto,color,marca,autos.modelo,autos.patente,cliente);
}

int buscarAutoId(int id,eAuto autos[],int tamAu)
{
    int indice=-1;
    for(int i=0;i<tamAu;i++)
    {
        if(autos[i].idAuto==id&&autos[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
int modificarDatosAuto(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    char patente[20];
    int retorno=0;

    int indice;
    int opcionCambio;
    int flag;

    eAuto auxiliar;

    system("cls");
    if(autos!=NULL&&tamAu>0)
    {
        retorno=1;
        printf("\n*****Modificar datos de un auto*****\n");

        if(getPatente(patente,20,"\nIngrese Patente del auto: ","Error. Ingrese cadena valida:",0))
        {
            indice=buscarPatenteAuto(patente,autos,tamAu);
            if(indice==-1)
            {
                printf("\n*****No se encontro esa patente en la base de datos*****\n\n");
            }
            else
            {
            	flag=0;

                do
                {

                    system("cls");
                    printf("*****Auto seleccionado*****\n");
                    printf("ID         COLOR      MARCA    MODELO     PATENTE\n");
                    mostrarAuto(autos[indice],colores,tamCol,marcas,tamMar,clientes,tamCli);

                    printf("\n\n");
                    system("pause");
                    system("cls");

                    opcionCambio=menuDeCambiosAuto();

                    switch(opcionCambio)
                    {
                    case 1:
                        mostrarColores(colores,tamCol);
                        if(getInt(&auxiliar.idColor,"Ingrese color: ","Error debe ser un entero entre 5000 y 5004",5000,5004,1))
                        {
                            autos[indice].idColor=auxiliar.idColor;
                            flag=1;
                        }
                        break;
                    case 2:
                        if(getInt(&auxiliar.modelo,"Ingrese anio de fabricacion: ","Error ingrese un anio valido",1000,2020,1))
                        {
                            autos[indice].modelo=auxiliar.modelo;
                        }
                        break;
                    case 3:
                        break;
                    default:
                        printf("\n*****Error. Ingrese una opcion valida*****\n\n");
                        system("pause");
                        break;
                    }

                    system("cls");
                }while(opcionCambio!=3);

                if(flag==1)
                {
                    printf("\n******Los cambios se han cargado con exito!!!****\n");
                    system("pause");
                }
            }
        }
    }
    return retorno;
}
int buscarUnaCarga(eAuto autos[],int tamAu)
{
    int encontrado=0;
    for(int i=0;i<tamAu;i++)
    {
        if(autos[i].isEmpty==0)
        {
            encontrado=1;
            break;
        }
    }

    return encontrado;
}

int buscarLibre(eAuto autos[],int tamAu)
{
    int encontrado=-1;
    for(int i=0;i<tamAu;i++)
    {
        if(autos[i].isEmpty==1)
        {
            encontrado=i;
            break;
        }
    }

    return encontrado;
}

int altaAuto (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli)
{
    int indice=buscarLibre(autos,tamAu);

    int retorno=0;

    eAuto auxiliar;

    system("cls");
    printf("*****Alta de Auto*****\n");
    if(indice==-1)
    {
        printf("No hay lugar para agregar otro auto\n");
    }
    else
    {
        if(getInt(&auxiliar.idAuto,"Ingrese ID(de 0 a 10000): ","Error debe ser un entero numerico",0,10000,1)&&buscarAutoId(auxiliar.idAuto,autos,tamAu)==-1)
        {
            if(getPatente(auxiliar.patente,20,"Ingrese patente: ","Error Ingrese cadena valida",1)&&buscarPatenteAuto(auxiliar.patente,autos,tamAu)==-1)
            {
                if(getInt(&auxiliar.modelo,"Ingrese anio de fabricacion: ","Error ingrese un anio valido",1000,2020,1))
                {   mostrarClientes(clientes,tamCli);
                    if(getInt(&auxiliar.idCliente,"Ingrese ID del cliente: ","Error debe ingresar un ID entre 10010 y 10019",10010,10019,1))
                    {
                        mostrarColores(colores,tamCol);
                        if(getInt(&auxiliar.idColor,"Ingrese ID color: ","Error debe ser un entero entre 5000 y 5004",5000,5004,1))
                        {
                            mostrarMarcas(marcas,tamMar);
                            if(getInt(&auxiliar.idMarca,"Ingrese ID marca: ","Error debe ser un entero entre 1000 y 1004",1000,1004,1))
                            {
                                auxiliar.isEmpty=0;
                                autos[indice]=auxiliar;
                                retorno=1;
                            }

                        }
                    }
                }
            }
            else
            {
                printf("\nLa patente ya existe\n");
            }
        }
        else
        {
            printf("\nEl ID ya existe o no cumple los requisitos de IDs\n");
        }

    }

  return retorno;
}

void inicializarAutos(eAuto autos[],int tamAu)
{
    for(int i=0;i<tamAu;i++)
    {
      autos[i].isEmpty=1;
    }
}

int menuDeCambiosAuto(void)
{
    int opcion;
    printf("******Eleccion de dato a modificar*******\n");
    printf("1-Color\n");
    printf("2-Modelo\n");
    printf("3-Salir\n");

    printf("\nQue dato desea cambiar?: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
