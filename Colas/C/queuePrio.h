#include <stdio.h>
#include <stdlib.h>

#define N 7

typedef struct Node {
    int valor;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *root;
} Queue;

void init(Queue *);

Node *createNode(int);

int push(Queue *, Node *);

int pop(Queue *, int *);

void displayData(Queue *);

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
        if(n->valor <= q->root->valor){
            n->next = q->root;
            q->root = n;
        }else {
            for(Node *i = q->root; ; i = i->next){
                if(i->next == NULL){
                    i->next = n;
                    break;
                }else{
                    if(n->valor <= i->next->valor){
                        n->next = i->next;
                        i->next = n;
                        break;
                    }
                }
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

void displayData(Queue *q){
    if(q == NULL){
        printf("La cola es nula\n");
        exit(-1);
    }
    for(Node *n = q->root;; n = n->next){
        if(n == NULL) break;
        printf("Valor: %d\n", n->valor);
    }
}