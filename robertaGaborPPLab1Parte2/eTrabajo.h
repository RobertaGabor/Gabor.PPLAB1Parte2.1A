#ifndef ETRABAJO_H_INCLUDED
#define ETRABAJO_H_INCLUDED


typedef struct{

int dia;
int mes;
int anio;

}eFecha;
typedef struct{

int idTrabajo;
char patente[20];
int idServicio;
eFecha fecha;
int isEmpty;

}eTrabajo;

/** \brief Carga un vector de tipo eTrabajo en un indice
 *
 * \param Id autoincremental pasado por referencia desde main, solo se incrementa si se logra dar un trabajo de alta
 * \param vector de tipo eAuto
 * \param tamaño de vector autos
 * \param vector de tipo eColor
 * \param tamaño de vector Colores
 * \param vector de tipo eMarca
 * \param tamaño de vector marcas
 * \param vector de tipo eServicio
 * \param tamaño de vector servicios
 * \param vector a cargar eTrabajo
 * \param  tamaño de vector trabajos
 * \return devuelve 1 si se pudo dar de alta sino 0
 *
 */
int altaTrabajo (int id,eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eServicio servicio[],int tamServ,eTrabajo trabajo[], int tamTra,eCliente clientes[],int tamCli);
/** \brief Analiza un vector de tipo eTrabajo y busca el primer indice con isEmpty=1
 *
 * \param trabajos[] eTrabajo vector a analizar
 * \param tamTra int tamaño del vector
 * \return int devuelve -1 si no encontro, sino devuelve el indice
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[],int tamTra);
/** \brief Muestra una lista de todos los trabajos realizados
 *
 * \param vector de tipo eTrabajo a analizar
 * \param tamaño del vector trabajos
 * \param vector de tipo eServicio
 * \param tamaño de vector servicios
 * \return void
 *
 */
void mostrartrabajos (eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamServ);
/** \brief Muestra los datos de un vector eTrabajo en un solo indice
 *
 * \param trabajo eTrabajo variable eTrabajo
 * \param servicios[] eServicio vector de tipo eServicio
 * \param tamServ int tamaño de vector servicios
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tamServ);
/** \brief Inicializa todo un vector de tipo eTrabajo en la celda isEmpty en 1
 *
 * \param trabajos[] eTrabajo vector eTrabajo a inicializar
 * \param tamTra int tamaño del vector trabajos
 * \return void
 *
 */
void inicializarTrabajos(eTrabajo trabajos[],int tamTra);

#endif // ETRABAJO_H_INCLUDED
