#include <stdio.h>
#define N 10 //Tamaño estatico de la cola

//Estructura de la Cola
typedef struct Queue {
    int items[N]; //Arreglo de items
    int idx; //Indice actual
} Queue;

//Funcion para inicializar la cola
void init(Queue *);

//Funcion para verificar si esta vacia
//Regresa 1 si lo esta
//Regresa diferente de 1 si no
int is_empty(Queue *);

//Funcion para verificar si esta llena
//Regresa 1 si lo esta
//Regresa diferente de 1 si no
int is_full(Queue *);

//Funcion para agregar un valor o "encolarlo"
//Regresa 1 si se agrego de manera correcta
//Regresa 0 si ha ocurrido un error
int push(Queue *, int);

//Funcion que permite eliminar un nodo
//Regresa 1 si se ha eliminado correctamente
//Regresa 0 si ha ocurrido un error
//Adicionalmente devuelve en el apuntador el valor eliminado
int pop(Queue *, int *);

void init(Queue *q){
    for(int i = 0; i < N; i++){
        q->items[i] = 0;
    }
    q->idx = -1;
}

int is_empty(Queue *q){
    return q->idx == -1;
}

int is_full(Queue *q){
    return q->idx == N-1;
}

int push(Queue *q, int v){
    if(!is_full(q)){
        (q->idx)++;
        q->items[q->idx] = v;
        return 1;
    }else 
        return 0;
}

int pop(Queue *q, int *v){
    if(!is_empty(q)){
        *v = q->items[q->idx];
        q->items[q->idx] = 0;
        (q->idx)--;
        return 1;
    }else
        return 0;
}
