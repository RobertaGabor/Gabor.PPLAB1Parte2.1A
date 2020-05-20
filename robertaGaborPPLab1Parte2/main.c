#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMSERVICIOS 4
#define TAMCOLORES 5
#define TAMSMARCAS 5
#define TAMAUTOS 1000
#define TAMCLIENTES 10
#define TAMTRABAJOS 1000
#include "validaciones.h"
#include "eAuto.h"
#include "eColor.h"
#include "eMarca.h"
#include "eServicio.h"
#include "eTrabajo.h"
#include "informes.h"


int menu(void);

int main()
{
    eServicio servicios[TAMSERVICIOS]={{20000,"Lavado",250},{20001,"Pulido",300},{20002,"Encerado",400},{20003,"Completo",600}};
    eMarca marcas[TAMSMARCAS]={{1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"}};
    eColor colores[TAMCOLORES]={{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eCliente clientes[TAMCLIENTES]={{10010,'f',"Juana"},{10011,'f',"Susana"},{10012,'m',"Elon"},{10013,'m',"Pedro"},{10014,'f',"Perla"},{10015,'f',"Daria"},{10016,'m',"Marcos"},{10017,'m',"Dorian"},{10018,'f',"Loise"},{10019,'m',"Clark"}};

    eAuto autos1[TAMAUTOS]={{1,"dias12",1000,5000,1989,10010,0},{2,"pepe4",1000,5003,2001,10011,0},{3,"totof4",1002,5004,2010,10012,0},{4,"lui89o0",1004,5000,1975,10016,0}};
    eTrabajo trabajos[TAMTRABAJOS]={{10,"dias12",20000,{1,9,1997},0},{11,"pepe4",20001,{2,12,2001},0},{12,"totof4",20002,{11,3,2012},0}};

    char seguir='s';
    int opcionMenuMain;
    int opcionInformes;
    int proximoIdTrabajo=10;
    int flag=0;
    int flagb=0;

    inicializarAutos(autos1,TAMAUTOS);
    inicializarTrabajos(trabajos,TAMTRABAJOS);
    proximoIdTrabajo=proximoIdTrabajo+3;

    do
    {
        opcionMenuMain=menu();
        switch(opcionMenuMain)
        {
        case 1:
            if(altaAuto(autos1,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS,clientes,TAMCLIENTES))
            {
                printf("\n****Dado de alta exitosamente\n");
                flag=1;
            }
            else
            {
                printf("\n****No se pudo dar de alta****\n");
            }
            break;
        case 2:
            if(flag==1)
            {
                modificarDatosAuto(autos1,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS,clientes,TAMCLIENTES);
            }
            else
            {
                printf("\n*****Primero ingrese al menos un auto*****\n");
            }


            break;
        case 3:
            if(flag==1)
            {
               bajaAuto(autos1,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS,clientes,TAMCLIENTES);
               if(!buscarUnaCarga(autos1,TAMAUTOS))
               {
                   flag=0;
               }
            }
            else
            {
                printf("\n*****Primero ingrese al menos un auto*****\n");;
            }
            break;
        case 4:
            if(flag==1)
            {
                    ordenarAutos(autos1,TAMAUTOS,marcas,TAMSMARCAS);
                    mostrarAutos(autos1,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS,clientes,TAMCLIENTES);

            }
            else
            {
                printf("\n*****Primero ingrese al menos un auto*****\n");
            }

            break;
        case 5:
            mostrarMarcas(marcas,TAMSMARCAS);
            break;
        case 6:
            mostrarColores(colores,TAMCOLORES);
            break;
        case 7:
            mostrarServicios(servicios,TAMSERVICIOS);
            break;
        case 8:
            if((flag==1)&&altaTrabajo(proximoIdTrabajo,autos1,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS,servicios,TAMSERVICIOS,trabajos,TAMTRABAJOS,clientes,TAMCLIENTES))
            {
                printf("\n****Dado de alta exitosamente\n");
                proximoIdTrabajo++;
                flagb=1;
            }
            else
            {
                printf("\n****No se pudo dar de alta o no se ha ingresado ningun auto****\n");
            }
            break;
        case 9:
            if(flagb==1)
            {
                mostrartrabajos(trabajos,TAMTRABAJOS,servicios,TAMSERVICIOS);
            }
            else
            {
                printf("\n*****No hay trabajos que listar*****\n");
            }
            break;
        case 10:

            do
            {   opcionInformes=menuInformes();
                switch(opcionInformes)
                {
                case 1:
                    mostrarAutosSegunColor(autos1,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS,clientes,TAMCLIENTES);
                    break;
                case 2:
                    mostrarAutosSegunMarca(autos1,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS,clientes,TAMCLIENTES);
                    break;
                case 3:
                    autoMasViejo(autos1,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS,clientes,TAMCLIENTES);
                    break;
                case 4:
                    mostrarAutoMarcas(autos1,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS,clientes,TAMCLIENTES);
                    break;
                case 5:
                    cantidadSegunMarcayColor(autos1,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS,clientes,TAMCLIENTES);
                    break;
                case 6:
                    marcaMasAtendida(autos1,TAMAUTOS,marcas,TAMSMARCAS);
                    break;
                case 0:
                    break;
                default:
                    printf("*****Opcion invalida*****\n");
                    break;
                }
                system("pause");
            }while(opcionInformes!=0);
            break;
        case 0:
            seguir='n';
            break;
        default:
            printf("\n*****Opcion invalida*****\n");
            break;
        }
        system("pause");
    } while(seguir=='s');

    return 0;
}

int menu(void)
{

    int opcion;
    system("cls");
    printf("********Menu de opciones**********\n");

    printf("1-Alta de auto\n");
    printf("2-Modificar Auto\n");
    printf("3-Baja de auto\n");
    printf("4-Listar autos\n");
    printf("5-Listar marcas\n");
    printf("6-Listar colores\n");
    printf("7-Listar servicios\n");
    printf("8-Alta trabajo\n");
    printf("9-Listar trabajos\n");
    printf("10-Informes\n");
    printf("0-salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}































