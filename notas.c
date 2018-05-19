#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
    char info;
    struct node* next;
}node;

node* cria_lista(){
    node* aux=(node*)malloc(sizeof(node));
    assert(aux);
    aux->next=NULL;
    return aux;
