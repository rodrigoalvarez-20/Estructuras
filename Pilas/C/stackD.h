#include <stdlib.h>
#include <stdio.h>

//Declaracion de nuestros nodos
typedef struct Nodo {
    /**
     * Campos necesarios aqui
     */
    int v;
    struct Nodo *next; //Siempre es necesario tener el apuntador al nodo siguiente
} Nodo;

//Creacion de nuestra Pila
typedef struct Stack {
    Nodo *root; //Nodo inicial
    int size; //Contador de elementos
} Stack;

//Funcion para inicializar la pila
void init(Stack *); 
/**
 * Funcion para ingresar un elemento a la pila
 * Regresa 1 si fue exitosa la operacion
 * Regresa 0 si hubo un error
 */
int push(Stack *, Nodo *);
/**
 * Funcion para eliminar un elemento a la pila
 * Regresa el valor del Nodo eliminado
 */
Nodo pop(Stack *); 
//Funcion para verificar si la pila esta vacia
int is_empty(Stack *);

Nodo *createNode(int value){
    Nodo *toAdd = (Nodo *) malloc(sizeof(Nodo));
    if(toAdd == NULL){
        printf("Ha ocurrido un error al crear el nodo\n");
        exit(-1);
    }
    /*
    *Implementacion de valores aqui
    */
    toAdd->v = value;
    toAdd->next = NULL;
    return toAdd;
}

void init(Stack *s){
    if(s == NULL){
        printf("El apuntador es nulo\n");
        exit(-1);
    }
    s->root = NULL;
    s->size = 0;
}

int push(Stack *s, Nodo *n){
    if(s == NULL){
        printf("El apuntador de la pila es nulo\n");
        return 0;
    }
    n->next = s->root;
    s->root = n;
    return 1;
}

Nodo pop(Stack *s){
    if(s == NULL){
        printf("El apuntador de la pila es nulo\n");
        exit(-1);
    }
    Nodo toReturn;
    if(s->root != NULL){
        //Si hay elementos
        Nodo *toRemove = s->root;
        s->root = toRemove->next;
        toReturn = *toRemove;
        free(toRemove);
    }else {
        printf("No hay elementos\n");
    }
    return toReturn;
}

int is_empty(Stack *s){
    if(s == NULL){
        printf("El apuntador de la pila es nulo\n");
        exit(-1);
    }
    return s->size > 0;

}

O(1)...