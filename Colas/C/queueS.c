#include "queueS.h"

int main(){
    Queue q;
    init(&q);

    for(int i = 0; i < N; i++)
        printf("%i\n", push(&q, (i+1)*20));

    int v;
    for(int i = 0; i < N; i++){
        int c = pop(&q, &v);
        c == 1 ? printf("Se ha eliminado el valor: %i\n", v) : printf("Cola vacia\n");
    }

    return 0;
}