#include "stackD.h"

#define N 15

int main(){
    Stack s;

    init(&s);

    for(int i = 0; i < N; i++)
        printf("%i\n", push(&s, createNode(i+1)));

    int v;
    for(int i = 0; i < N; i++){
        Nodo n = pop(&s);
        printf("Popped value: %i\n", n.v);
    }

    return 0;
}