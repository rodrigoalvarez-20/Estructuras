#include <stdio.h>

#define N 5 //Tamaño estatico

//Declaracion de nuestra estructura
typedef struct Stack {
    int items[N]; //Arreglo de items de un solo tipo
    int idx; //Index actual
} Stack;

//Funcion que inicializa la estructura
void init(Stack *);

//Funcion para verificar si la pila está vacia
int is_empty(Stack *);

//Funcion para verificar si la pila está llena
int is_full(Stack *);

//Funcion para agregar un nuevo item
//Regresa 1 si se ha insertado correctamente
//Regresa 0 si ha ocurrido un error
int push(Stack *, int);

//Funcion que permite eliminar el ultimo valor de la estructura
//Regresa 0 si ha ocurrido un error al sacar el valor
//Regresa 1 si se ha eliminado correctamente
//Se regresa el valor eliminado mediante puntero
int pop(Stack *, int *);


void init(Stack *s){
    for(int i = 0; i < N; i++){
        s->items[i] = 0;
    }
    s->idx = N-1;
}

int is_empty(Stack *s){
    return s->idx == N-1;
}

int is_full(Stack *s){
    return s->idx == -1;
}

int push(Stack *s, int value){
    if(!is_full(s)){
        s->items[s->idx] = value;
        (s->idx)--;
        return 1;
    }else {
        return 0;
    }
}

int pop(Stack *s, int *popped_value){
    if(!is_empty(s)){
        (s->idx)++;
        *popped_value = s->items[s->idx];
        s->items[s->idx] = 0;
        return 1;
    }else
        return 0;
}

O(n)
O(1)
O(1)
O(1)
O(1)
O(n)