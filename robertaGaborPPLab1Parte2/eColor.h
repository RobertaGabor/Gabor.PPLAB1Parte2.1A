#ifndef ECOLOR_H_INCLUDED
#define ECOLOR_H_INCLUDED


typedef struct{

int idColor;
char descripcionColor[20];
}eColor;

/** \brief Muestra solo la informacion de un color con su descripcion
 *
 * \param colores eColor vector de eColor en un indice
 * \return void
 *
 */
void mostrarColor(eColor colores);
/** \brief Muestra todos los colores con sus descripciones y el encabezado de informacion
 *
 * \param vector de tipo eColor a recorrer
 * \param tamaño del vector colores
 * \return void
 *
 */
void mostrarColores (eColor color[],int tamCol);
/** \brief se carga un array de caracteres con una descripcion segun el Id pasado por parametro
 *
 * \param descripcion[] char puntero que guarda la descripcion correspondiente
 * \param id int Id del color buscado
 * \param colores[] eColor vector de tipo eColor para buscar la coincidencia
 * \param tamMar int tamaño del vector de colores
 * \return int devuelve 1 si lo encontro sino 0
 *
 */
int cargarDescripcionColor(char descripcion[],int id,eColor colores[],int tamCol);

#endif // ECOLOR_H_INCLUDED
