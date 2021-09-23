#include <stdlib.h>
#include <stdio.h>

//Declaracion de nuestros nodos
typedef struct Nodo {
    /**
     * Campos necesarios aqui
     */
     int data;
} Nodo;

//Funcion para inicializar la pila
void init(Nodo *, int); 
/**
 * Funcion para ingresar un elemento a la pila
 * Regresa 1 si fue exitosa la operacion
 * Regresa 0 si hubo un error
 */
int push(Nodo *, Nodo);
/**
 * Funcion para eliminar un elemento a la pila
 * Regresa el valor del Nodo eliminado
 * Regresa NULL si no hay ningun valor en la pila
 */
Nodo pop(Nodo *); 
//Funcion para verificar si la pila esta vacia
int is_empty(Nodo *);

Nodo createNode(){
    Nodo toAdd;
    /**
    Implementacion de campos aqui
    **/
    return toAdd;
}

void init(Nodo *n, int size){
    n = (Nodo *) malloc(sizeof(Nodo) * size);
}

int push(Nodo *n, Nodo toAdd){
    int size = sizeof(n)/sizeof(n[0]);
    Nodo temp = n[0];
    n[0] = toAdd;
    for(int i = 1; i < size - 1; i++){
        n[i] = temp;
        temp = n[i];
    }
}

Nodo pop(Nodo *n){
    int size = sizeof(n)/sizeof(n[0]);
    Nodo toRemove = n[0];
    for(int i = 1; i < size; i++){
        n[i-1] = n[i];
    }
    return toRemove;
}

int is_empty(Nodo *n){
    int size = sizeof(n)/sizeof(n[0]);
    return size > 0;
}