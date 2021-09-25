#include "stackS.h"

int main(){
    Stack s;

    init(&s);

    for(int i = 0; i < N; i++)
        printf("%i\n", push(&s, i));

    int v;
    for(int i = 0; i < N; i++){
        int cd = pop(&s, &v);
        printf("Status: %i\n", cd);
        cd != 0 ? printf("Popped Value: %i\n", v) : printf("Empty Stack\n");
    }

    return 0;
}