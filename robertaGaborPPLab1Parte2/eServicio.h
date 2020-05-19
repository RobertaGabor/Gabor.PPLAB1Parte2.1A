#ifndef ESERVICIO_H_INCLUDED
#define ESERVICIO_H_INCLUDED


typedef struct{

int idServicio;
char descripcionServicio[25];
float precio;

}eServicio;

/** \brief Muestra solo la informacion de un servicio con su descripcion
 *
 * \param servicios eServicio vector de eServicio en un indice
 * \return void
 *
 */
void mostrarServicio(eServicio servicios);
/** \brief Muestra todos los servicios con sus descripciones y el encabezado de informacion
 *
 * \param vector de tipo eServicio a recorrer
 * \param tamaño del vector servicios
 * \return void
 *
 */
void mostrarServicios (eServicio servicios[],int tamServ);
/** \brief se carga un array de caracteres con una descripcion segun el Id pasado por parametro
 *
 * \param descripcion[] char puntero que guarda la descripcion correspondiente
 * \param id int Id del servicio buscado
 * \param servicios[] eServicio vector de tipo eServicio para buscar la coincidencia
 * \param tamMar int tamaño del vector de servicios
 * \return int devuelve 1 si lo encontro sino 0
 *
 */
int cargarDescripcionServicio(char descripcion[],int id,eServicio servicio[],int tamSer);

#endif // ESERVICIO_H_INCLUDED
