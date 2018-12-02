#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ordenamiento.h"
#include "validaciones.h"


/** \brief Ubica mayúsculas y minúsculas en una cadena de caracteres
 *
 * \param cadena char* Puntero a la cadena a ordenar
 * \return int [0] si el puntero es nulo y [1] si se ordeno correctamente la cadena
 *
 */
int ubicaMayusculasYMinusculas(char* cadena)
{
    int retorno = 0;
    if(cadena != NULL)
    {
        retorno = 1;
        strlwr(cadena);
        cadena[0] = toupper(cadena[0]);

        int i;
        for(i = strlen(cadena); i > 1; i--)
        {
            if(cadena[i - 1] == ' ')
            {
                cadena[i] = toupper(cadena[i]);
            }
        }
    }
    return retorno;
}


/** \brief Ordena de menor a mayor los elementos de un vector numerico
 *
 * \param int* vector Puntero al vector
 * \param tam int Tamano del vector
 * \return int [0]
 *
 */
int ordenaVectorNumerico_Burbujeo(int* vector, int tam)
{
    int i;
    int j;
    int auxiliar;

    for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if(vector[j] < vector[i])
            {
                auxiliar = vector[j];
                vector[j] = vector[i];
                vector[i] = auxiliar;
            }
        }
    }
    return 0;
}




/** \brief Ordena de menor a mayor los elementos de un vector numerico
 *
 * \param int* vector Puntero al vector
 * \param tam int Tamano del vector
 * \return int [0]
 *
 */
int ordenaVectorNumerico_Insertion(int* vector, int tam)
{
    int i;
    int j;
    int auxiliar;

    for(i = 1; i < tam; i++)
    {
        auxiliar = vector[i];
        j = i - 1;
        while(j >= 0 && auxiliar < vector[j])
        {
            vector[j+1] = vector[j];
            j--;
        }
        vector[j+1] = auxiliar;
    }
    return 0;
}


/** \brief Ordena alfabeticamente las cadenas de una matriz de cadenas
 *
 * \param char* vector Puntero al inicio de la matriz
 * \param filas int Numero de filas de la matriz
 * \return int [0]
 *
 */
int ordenaMatrizAlfabeticamente_Burbujeo(char arrayCadenas[][50], int filas)
{
    int i;
    int j;
    char auxiliar[50];

    for(i = 0; i < filas - 1; i++)
    {
        for(j = i + 1; j < filas; j++)
        {
            if(stricmp(arrayCadenas[i], arrayCadenas[j]) > 0)
            {
                strcpy(auxiliar, arrayCadenas[j]);
                strcpy(arrayCadenas[j], arrayCadenas[i]);
                strcpy(arrayCadenas[i], auxiliar);
            }
        }
    }
    return 0;
}
