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

/*Passar de To Do para Doing*/

typedef struct node{
    int data;
    struct node* next;
}Node;
void push(Node** headRef, int data){
    Node* newNode = (Node*) malloc(sizeof(newNode));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}
Node* pushtop(){
    Node* head = NULL;
    int i;
    for(i = 1; i<=3; i++){
        push(&head,i);}
return head;
}
Node* pushbottom(){
    Node* head = NULL;
    int i;
    for(i=7; i>=4; i--){
        push(&head,i);}
    return head;
}
void moveNode(Node** source,Node** dest){
    Node* ptr = NULL;
    Node* current = *source;
    while(current != NULL){
        ptr = current->next;
        current->next = dest;
        dest = current;
        current = ptr;}
    Node* test = *dest;
    printf("\nthe then moved list is\n\n");
    while(test!=NULL){
        printf("%d\n",test->data);
        test = test->next;}
}
int main(){
    Node* headA = pushtop();
    Node* headB = pushbottom();
    moveNode(&headA, &headB);
    return 0;
}
