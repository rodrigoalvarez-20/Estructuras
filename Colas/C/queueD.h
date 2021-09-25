#include <stdio.h>
#include <stdlib.h>

#define N 10 //Constante para el limite de datos

//Defincion de nuestra estructura Nodo
typedef struct Node {
    /*
    * Implementacion de campos extras
    */
    int valor;
    struct Node *next; //Nodo siguiente
} Node;

//Estructura de nuestra cola de datos simple
typedef struct Queue {
    Node *root; //Inicio de nuestra cola
} Queue;

//Funcion que permite inicializar la cola
void init(Queue *);

//Funcion para crear un nodo
//Regresa un apuntador de Nodo si se ha creado correctamente
//Regresa Null si ha ocurrido un error
Node *createNode(int);

//Funcion para agregar al final de la cola
//Regresa 1 si la operacion fue exitosa
//Regresa 0 si ha ocurrido un error
int push(Queue *, Node *);

//Funcion para sacar el primer nodo en la cola
//Regresa 1 si se ha eliminado correctamente
//Regresa 0 si ha ocurrido un error
//Adicionalmente regresa el valor eliminado, por medio del apuntador
int pop(Queue *, int *);

void init(Queue *q){
    if(q == NULL){
        printf("La cola es nula\n");
        exit(-1);
    }
    q->root = NULL;
}

Node *createNode(int v){
    Node *n = (Node *) malloc(sizeof(Node));
    if(n == NULL){
        printf("Error al crear el nodo\n");
        return NULL;
    }

    n->valor = v;
    n->next = NULL;

    return n;

}

int push(Queue *q, Node *n){
    if(q == NULL){
        printf("La cola es nula\n");
        exit(-1);
    }

    if(q->root == NULL){
        q->root = n;
    }else{
        for(Node *i = q->root; ; i = i->next){
            if(i->next == NULL){
                i->next = n;
                break;
            }
        }
    }

    return 1;

}

int pop(Queue *q, int *v){
    if(q == NULL){
        printf("La cola es nula\n");
        exit(-1);
    }

    if(q->root != NULL){
        if(q->root->next == NULL){
            *v = q->root->valor;
            q->root = NULL;
        }else {
            for(Node *n = q->root; ; n = n->next){
                if(n->next->next == NULL){
                    *v = n->next->valor;
                    free(n->next);
                    n->next = NULL;
                    break;
                }
            }
        }
        return 1;
    }else 
        return -1;

}