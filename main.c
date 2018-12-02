#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "controller.h"
#include "Employee.h"

    /*
    1- Carga datos de empleados desde archivo CSV
    2- Ordena alfabeticamente la lista de empleados y los muestra (utiliza Sort de LL y la funcion de comparacion de Empleados)
    3- Calcula los sueldos de los empleados (utiliza la funcion map de LL y la funcion de Calculo de Empleados)
    4- Guarda en un archivo los empleados con sueldos superiores a 40000 (utiliza funcion Filter de LL y filer de Empleados)
    */

int main()
{
    LinkedList* lista = ll_newLinkedList();

    controller_bienvenida();

    puts("En primer lugar, se procedera a cargar datos desde un archivo de texto");
    puts("Presiones una tecla para continuar");
    getchar();
    controller_leeDesdeTexto("data.csv", lista);

    puts("A continuacion, se ordenara alfabeticamente la lista de empleados y se mostrara los datos por consola");
    puts("Presiones una tecla para continuar");
    getchar();
    controller_ordenaAlfabeticamente(lista);
    controller_muestraLista(lista);

    puts("\nEn tercer lugar, se procedera a calcular los sueldos de cada empleado");
    puts("Presiones una tecla para continuar");
    getchar();
    controller_calculaSueldos(lista);

    puts("Por ultimo, se guardara en un archivo de texto el listado de empleados con sueldos mayores a 40000");
    puts("Presiones una tecla para continuar");
    getchar();
    controller_guardaArchivoTexto("dataSalida.csv", lista);

    puts("\nHASTA PRONTO!");

    return 0;
}
