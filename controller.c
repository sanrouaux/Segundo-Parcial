#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "Employee.h"


int controller_bienvenida()
{
    puts("--------------------------------");
    puts("SEGUNDO PARCIAL DE LABORATORIO I");
    puts("--------------UTN---------------");
    puts("");
    puts("Alumno: Santiago Rouaux");
    puts("");
    puts("");
    puts("Presione una tecla para continuar...");
    getchar();
    system("cls");

    return 0;
}


/** \brief
 *
 * \param ruta char*
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_leeDesdeTexto(char* ruta, LinkedList* lista)
{
    int retorno = -1;
    if(ruta != NULL && lista != NULL)
    {
        retorno = 0;
        FILE* pArchivo;
        pArchivo = fopen(ruta, "r");
        if(pArchivo != NULL)
        {
            retorno = 1;

            int datosParseados;
            char idStr[4];
            char nombre[128];
            char direccion[128];
            char horasTrabajadasStr[4];
            Employee* pEmployee;

            while(!feof(pArchivo))
            {
                datosParseados = fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, direccion, horasTrabajadasStr);
                if(datosParseados == 4)
                {
                    pEmployee = employee_newParametros(idStr, nombre, direccion, horasTrabajadasStr);
                    ll_add(lista, pEmployee);
                }
            }
            puts("DATOS CARGADOS EXITOSAMENTE\n");
        }
        else
        {
            puts("ERROR. NO SE LOGRO ABRIR EL ARCHIVO\n\n");
        }
    }
    return retorno;
}


/** \brief
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_ordenaAlfabeticamente(LinkedList* lista)
{
    int retorno = 0;
    if(lista != NULL)
    {
        retorno = 1;
        ll_sort(lista, comparaEmployees, 1);
    }
    return retorno;
}


/** \brief
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_muestraLista(LinkedList* lista)
{
    int retorno = 0;
    if(lista != NULL)
    {
        retorno = 1;
        Employee* pEmployee;

        puts("ID   NOMBRE    DIRECCION           HORAS");
        int i;
        for(i=0; i <ll_len(lista); i++)
        {
            pEmployee = (Employee*) ll_get(lista, i);
            printf("%-5d%-10s%-20s%d\n", pEmployee->id, pEmployee->nombre, pEmployee->direccion, pEmployee->horasTrabajadas);
        }
    }
    return retorno;
}


/** \brief
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_calculaSueldos(LinkedList* lista)
{
    int retorno = 0;
    if(lista != NULL)
    {
        retorno = 1;
        ll_map(lista, calculaSueldo);
        puts("SUELDOS CALCULADOS Y AGREGADOS A LOS DATOS\n");
    }
    else
    {
        puts("ERROR. NO SE PUDO CALCULAR LOS SUELDOS\n");
    }
    return retorno;
}


/** \brief
 *
 * \param ruta char*
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_guardaArchivoTexto(char* ruta, LinkedList* lista)
{
    int retorno = 0;
    if(lista != NULL && ruta != NULL)
    {
        retorno = 1;

        LinkedList* listaFiltrada = ll_filter(lista, filtraSueldoMayores);

        FILE* pArchivo;
        pArchivo = fopen(ruta, "w");

        if(pArchivo != NULL)
        {
            Employee* pEmployee;

            fprintf(pArchivo,"ID, NOMBRE, DIRECCION, HORAS, SUELDO\n");

            int i;
            for(i = 0; i < ll_len(listaFiltrada); i++)
            {
                pEmployee = (Employee*) ll_get(listaFiltrada, i);
                fprintf(pArchivo, "%d,%s,%s,%d,%d\n", pEmployee->id, pEmployee->nombre, pEmployee->direccion, pEmployee->horasTrabajadas,
                        pEmployee->sueldo);
            }
            fclose(pArchivo);
            puts("SE CARGARON LOS DATOS");
            puts("Para consultar el listado, busque el archivo 'dataSalida' en la carpeta en que se aloja el programa");
        }
        else
        {
            puts("ERROR. NO SE PUDO CREAR EL ARCHIVO\n");
        }

    }
    return retorno;
}
