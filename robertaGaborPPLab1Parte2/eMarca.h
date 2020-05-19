#ifndef EMARCA_H_INCLUDED
#define EMARCA_H_INCLUDED


typedef struct{

int idMarca;
char descripcionMarca[20];

}eMarca;

/** \brief se carga un array de caracteres con una descripcion segun el Id pasado por parametro
 *
 * \param descripcion[] char puntero que guarda la descripcion correspondiente
 * \param id int Id de marca buscada
 * \param marcas[] eMarca vector de tipo eMarca para buscar la coincidencia
 * \param tamMar int tamaño del vector de marcas
 * \return int devuelve 1 si lo encontro sino 0
 *
 */
int cargarDescripcionMarca(char descripcion[],int id,eMarca marcas[],int tamMar);
/** \brief Muestra todas las marcas con sus descripciones y el encabezado de informacion
 *
 * \param vector de tipo eMarca a recorrer
 * \param tamaño del vector marcas
 * \return void
 *
 */
void mostrarMarcas (eMarca marca[],int tamMar);
/** \brief Muestra solo la informacion de una marca con su descripcion
 *
 * \param marcas eMarca vector de eMarca en un indice
 * \return void
 *
 */
void mostrarMarca(eMarca marcas);

#endif // EMARCA_H_INCLUDED
