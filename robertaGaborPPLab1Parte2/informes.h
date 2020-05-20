#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
typedef struct{

int idMarca;
int cantidad;

}cantidadPorMarca;

int menuInformes (void);
void mostrarAutosSegunColor(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);
void mostrarAutosSegunMarca(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);
void autoMasViejo (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);
void mostrarAutoMarcas(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);
void cantidadSegunMarcayColor(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eCliente clientes[],int tamCli);
void marcaMasAtendida(eAuto autos[],int tamAu,eMarca marcas[],int tamMar);


#endif // INFORMES_H_INCLUDED
