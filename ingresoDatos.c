#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresoDatos.h"
#include "validaciones.h"


/** \brief pide un numero al usuario, valida que no haya caracteres que no sean numericos, que se haya introducido
 *         al menos un caracter y que el numero entre dentro de un rango establecido por el usuario
 *
 * \param mensaje[] char mensaje que será mostrado al usuario
 * \param max int Numero maximo que puede aceptar la funcion
 * \param min int Numero minimo que acepta la funcion
 * \return int número ingresado por el usuario
 *
 */
int pideYValidaEntero(char mensaje[], int max, int min)
{
    int numero;
    char buffer[12];

    puts(mensaje);
    fflush(stdin);
    gets(buffer);

    while(validaSoloNumeros(buffer) == 0 || strlen(buffer) == 0 || validaRangoEntero(atoi(buffer), max, min) == 0)
    {
        if(validaSoloNumeros(buffer) == 0)
        {
            puts("Error. Ingreso caracteres invalidos.");
        }

        if(strlen(buffer) == 0)
        {
            puts("Error. No se introdujo ningun digito.");
        }

        if(validaSoloNumeros(buffer) == 1 && strlen(buffer) != 0 && validaRangoEntero(atoi(buffer), max, min) == 0)
        {
            puts("Error. Numero fuera de rango.");
        }

        puts("Ingrese el numero nuevamente: ");
        fflush(stdin);
        gets(buffer);
    }

    numero = atoi(buffer);
    return numero;
}


/** \brief pide un numero flotante al usuario, valida que todos los caracteres sean numericos, que se haya introducido
 *         al menos un caracter y que el numero esté dentro de un rango establecido por el usuario
 *
 * \param mensaje[] char Mensaje que será mostrado al usuario
 * \param max float Numero maximo que puede aceptar la funcion
 * \param min float Numero minimo que acepta la funcion
 * \return float Número ingresado por el usuario
 *
 */
float pideYValidaFlotante (char mensaje[], float max, float min)
{
    float numero;
    char buffer[15];

    puts(mensaje);
    fflush(stdin);
    gets(buffer);

    while(validaSoloNumeros(buffer) == 0 || strlen(buffer) == 0 || validaRangoFlotante(atof(buffer), max, min) == 0)
    {
        if(validaSoloNumeros(buffer) == 0)
        {
            puts("Error. Ingreso caracteres invalidos.");
        }

        if(strlen(buffer) == 0)
        {
            puts("Error. No se introdujo ningun digito.");
        }

        if(validaSoloNumeros(buffer) == 1 && validaSoloNumeros(buffer) != 0 && validaRangoFlotante(atof(buffer), max, min) == 0)
        {
            puts("Error. Numero fuera de rango.");
        }

        puts("Ingrese el numero nuevamente: ");
        fflush(stdin);
        gets(buffer);
    }

    numero = atof(buffer);
    return numero;
}


/** \brief Recibe el ingreso de 's' o 'n' por parte del usuario y lo valida
 *
 * \return char Caracter ingresado por el usuario
 *
 */
char pideYValidaSiNo()
{
    char letra;

    fflush(stdin);
    letra = getchar();

    while(letra != 's' && letra != 'n')
    {
        puts("Error. Ingrese una opcion correcta: s/n");
        fflush(stdin);
        letra = getchar();
    }
    return letra;
}


/** \brief Pide un carcater al usuario y lo retorna
 *
 * \param mensaje[] char Mensaje que será mostrado al usuario
 * \return char Caracter ingresado por el usuario
 *
 */
char pideUnCaracter(char mensaje[])
{
    char caracter;
    puts(mensaje);
    fflush(stdin);
    scanf("%c", &caracter);
    return caracter;
}


/** \brief Pide secuencialmente el ingreso de numeros enteros hasta completar el vector
 *
 * \param int[] Puntero al vector a ser  cargado
 * \param char[] Mensaje que se mostrara al usuario
 * \param int Tamano del vector
 * \return void
 *
 */
void cargaSecuencialVectorEnteros(char mensaje[], int* vector, int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        printf(mensaje);
        scanf("%d", &vector[i]);
    }
}


/** \brief Permite cargar valores en un vector en una posicion a eleccion del usuario, mientras este lo desee
 *
 * \param int[] Vector a completar
 * \param char[] Mensaje de pedido de valor
 * \param int Tamano del vector
 * \param int Valor ilogico en relacion a la informacion que llenara el vector
 * \return void
 *
 */
void cargaAleatoriaVectorEnteros(char mensaje[], int* vector, int tam, int valorIlogico)
{
    int i;
    for(i =0; i < tam; i++)
    {
        vector[i] = valorIlogico;
    }

    int posicion;
    char reemplazo;
    char seguir;

    do
    {
        printf("Eliga una posicion entre 0 y %d: ", tam-1);
        scanf("%d", &posicion);
        posicion = validaRangoEntero(posicion, tam-1, 0);

        if(vector[posicion] != valorIlogico)
        {
            printf("Ya se ha guardado un valor en esta posicion. Desea reemplazarlo? s/n");
            fflush(stdin);
            scanf("%c", &reemplazo);
            reemplazo = validaSiNo(reemplazo);

            if(reemplazo == 's')
            {
                puts(mensaje);
                scanf("%d", &vector[posicion]);
            }
        }
        else
        {
            puts(mensaje);
            scanf("%d", &vector[posicion]);
        }

        puts("Desea ingresar otro valor? s/n");
        fflush(stdin);
        scanf("%c", &seguir);
        validaSiNo(seguir);

    }
    while(seguir == 's');
}


/** \brief Pide al usuario una cadena de caracteres; valida que se haya ingresado al menos un caracter y que el largo
 *         no exceda al permitido
 *
 * \param mensaje[] char Mensaje que se mostrará al usuario
 * \param cadena char* Puntero al lugar donde se guardará la cadena
 * \param largo int Largo máximo permitido
 * \return int [0]
 *
 */
int ingresaCadena(char mensaje[], char* cadena, int largo)
{
    char buffer[1024];

    puts(mensaje);
    gets(buffer);

    while(validaLargoCadena(buffer, largo) != 1)
    {
        if(validaLargoCadena(buffer, largo) == 0)
        {
            puts("Demasiados carcateres. Ingrese nuevamente");
        }

        if(validaLargoCadena(buffer, largo) == -1)
        {
            puts("No ingreso ningun caracter. Ingrese nuevamente");

        }

        fflush(stdin);
        gets(buffer);
    }

    strcpy(cadena, buffer);
    return 0;
}



/** \brief Permite ingresar secuencialmente cadenas de caracteres
 *
 * \param char[][50] vector en que se alojaran las cadenas
 * \param int cantidad de filas del vector
 * \return void
 *
 */
void ingresaArrayDeCadenas(char mensaje[], char listadoCadenas[][50], int filas)
{
    char buffer[1024];

    int i;
    for(i = 0; i < filas; i++)
    {
        puts(mensaje);
        gets(buffer);

        while(strlen(buffer) > 49)
        {
            puts("Error: la cadena desborda el espacio disponible. ");
            puts(mensaje);
            gets(buffer);
        }
        strcpy(listadoCadenas[i], buffer);
    }
}


/** \brief Pide al usuario una cadena de caracteres; valida que se haya ingresado al menos un caracter, que el largo de la cadena
 *         no exceda al permitido y que se haya introducido solamente caracterers alfabeticos
 *
 * \param mensaje[] char Mensaje que se mostrará al usuario
 * \param cadena char* Puntero al lugar donde se guardará la cadena
 * \param largo int Largo máximo permitido
 * \return int [0]
 *
 */
int ingresaCadenaSoloLetras(char mensaje[], char* cadena, int largo)
{
    char buffer[1024];

    puts(mensaje);
    fflush(stdin);
    gets(buffer);

    while(validaLargoCadena(buffer, largo) != 1 || validaSoloLetras(buffer) != 1)
    {
        if(validaLargoCadena(buffer, largo) == 0)
        {
            puts("Demasiados caracteres");
        }

        if(validaLargoCadena(buffer, largo) == -1)
        {
            puts("No ingreso ningun caracter");
        }

        if(validaSoloLetras(buffer) == 0)
        {
            puts("Ingreso caracteres invalidos");
        }

        puts("Ingrese nuevamente: ");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(cadena, buffer);
    return 0;
}


/** \brief Pide al usuario una cadena de caracteres; valida que se haya ingresado al menos un caracter, que el largo de la cadena
 *         no exceda al permitido y que se haya introducido únicamente caracteres numéricos
 *
 * \param mensaje[] char Mensaje que se mostrará al usuario
 * \param cadena char* Puntero al lugar donde se guardará la cadena
 * \param largo int Largo máximo permitido
 * \return int [0]
 *
 */
int ingresaCadenaSoloNumeros(char mensaje[], char* cadena, int largo)
{
    char buffer[1024];

    puts(mensaje);
    fflush(stdin);
    gets(buffer);

    while(validaLargoCadena(buffer, largo) != 1 || validaSoloNumeros(buffer) != 1)
    {
        if(validaLargoCadena(buffer, largo) == 0)
        {
            puts("Demasiados caracteres");
        }

        if(validaLargoCadena(buffer, largo) == -1)
        {
            puts("No ingreso ningun caracter");
        }

        if(validaSoloNumeros(buffer) == 0)
        {
            puts("Ingreso caracteres invalidos");
        }

        puts("Ingrese nuevamente: ");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(cadena, buffer);
    return 0;
}


/** \brief Pide al usuario una cadena de caracteres; valida que se haya ingresado al menos un caracter, que el largo de la cadena
 *         no exceda al permitido y que se haya introducido solamente caracterers alfanuméricos
 *
 * \param mensaje[] char Mensaje que se mostrará al usuario
 * \param cadena char* Puntero al lugar donde se guardará la cadena
 * \param largo int Largo máximo permitido
 * \return int [0]
 *
 */
int ingresaCadenaAlfanumerica(char mensaje[], char* cadena, int largo)
{
    char buffer[1024];

    puts(mensaje);
    fflush(stdin);
    gets(buffer);

    while(validaLargoCadena(buffer, largo) != 1 || validaSoloAlfanumericos(buffer) != 1)
    {
        if(validaLargoCadena(buffer, largo) == 0)
        {
            puts("Demasiados caracteres");
        }

        if(validaLargoCadena(buffer, largo) == -1)
        {
            puts("No ingreso ningun caracter");
        }

        if(validaSoloAlfanumericos(buffer) == 0)
        {
            puts("Ingreso caracteres invalidos");
        }

        puts("Ingrese nuevamente: ");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(cadena, buffer);
    return 0;
}
