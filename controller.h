#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_bienvenida();
int controller_leeDesdeTexto(char* ruta, LinkedList* lista);
int controller_ordenaAlfabeticamente(LinkedList* lista);
int controller_muestraLista(LinkedList* lista);
int controller_calculaSueldos(LinkedList* lista);
int controller_guardaArchivoTexto(char* ruta, LinkedList* lista);

#endif // CONTROLLER_H_INCLUDED
