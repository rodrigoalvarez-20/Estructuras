#include "queueD.h"

int main(){
    Queue q;
    init(&q);

    for(int i = 0; i < N; i++)
        printf("%i\n", push(&q, createNode((i+1)*30)));
    
    printf("Sacando valores...\n");

    int v;

    for(int i=0; i < N; i++){
        int c = pop(&q, &v);
        c == 1 ? printf("Valor eliminado: %i\n", v) : printf("Ha ocurrido un error al eliminar el valor\n");
    }

    return 0;
}