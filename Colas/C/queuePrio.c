#include "queuePrio.h"
#include <time.h>

int main(){
    Queue q;
    srand(time(NULL));
    init(&q);

    for(int i = 0; i < N; i++){
        int r = (int) rand() % 1000;
        int c = push(&q, createNode(r));
        c ? 
            printf("Valor: %i insertado\n", r)
        :
            printf("Ha ocurrido un error al insertar el valor\n");
    }
    
    printf("Mostrando valores...\n");
    displayData(&q);
    printf("Sacando valores...\n");

    int v;

    for(int i=0; i < N; i++){
        int c = pop(&q, &v);
        c == 1 ? printf("Valor eliminado: %i\n", v) : printf("Ha ocurrido un error al eliminar el valor\n");
    }

    return 0;
}