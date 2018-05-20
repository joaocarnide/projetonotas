/*Estruturas*/
typedef struct node{
    int data;
    struct node* next;
}

/*Criar novo node*/
node* head;
node* create(int data,node* next){
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Error creating a new node.\n");
        exit(0);}
    new_node->data = data;
    new_node->next = next;
    return new_node;
}

/*Apontar o ponteiro next para o novo node para o ponteiro head e este ser o novo ponteiro*/
node* prepend(node* head,int data){
    node* new_node = create(data,head);
    head = new_node;
    return head;
}

/*Atravessar a lista ligada*/
typedef void (*callback)(node* data);
void traverse(node* head,callback f){
    node* cursor = head;
    while(cursor != NULL){
        f(cursor);
        cursor = cursor->next;}
}

/*Contar os elementos de uma lista ligada*/
int count(node *head){
    node *cursor = head;
    int c = 0;
    while(cursor != NULL){
        c++;
        cursor = cursor->next;}
    return c;
}

/*Adicionar um novo node ao fim de uma lista ligada*/
node *cursor = head;
while(cursor->next != NULL)
   cursor = cursor->next;
node* new_node =  create(data,NULL);
cursor->next = new_node;
node* append(node* head, int data){
    /*ir para o ultimo node*/
    node *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;
    /*criar um novo node*/
    node* new_node =  create(data,NULL);
    cursor->next = new_node;
    return head;
}

/*Inserir um novo node depois de um node particular*/
node *cursor = head;
while(cursor != prev)
   cursor = cursor->next;
node* new_node = create(data,cursor->next);
cursor->next = new_node;
/*inserir um novo node depois do node prev*/
node* insert_after(node *head, int data, node* prev){
    /*encontra o node prev, começando no primeiro node*/
    node *cursor = head;
    while(cursor != prev)
        cursor = cursor->next;
    if(cursor != NULL){
        node* new_node = create(data,cursor->next);
        cursor->next = new_node;
        return head;}
    else{
        return NULL;}
}

/*Inserir um novo node antes de um node particular*/
node* insert_before(node *head, int data, node* nxt){
    if(nxt == NULL || head == NULL)
        return NULL;
    if(head == nxt){
        head = prepend(head,data);
        return head;}
    /*encontra o node prev, começando no primeiro node*/
    node *cursor = head;
    while(cursor != NULL){
        if(cursor->next == nxt)
            break;
        cursor = cursor->next;}
    if(cursor != NULL){
        node* new_node = create(data,cursor->next);
        cursor->next = new_node;
        return head;}
    else{
        return NULL;}
}

/*Procurar por um node*/
node* search(node* head,int data){
    node *cursor = head;
    while(cursor!=NULL){
        if(cursor->data == data)
            return cursor;
        cursor = cursor->next;}
    return NULL;
}

/*Ordenar uma lista ligada*/
node* insertion_sort(node* head){
    node *x, *y, *e;
    x = head;
    head = NULL;
    while(x != NULL){
        e = x;
        x = x->next;
        if (head != NULL){
            if(e->data > head->data){
                y = head;
                while ((y->next != NULL) && (e->data> y->next->data)){
                    y = y->next;}
                e->next = y->next;
                y->next = e;}
            else{
                e->next = head;
                head = e ;}}
        else{
            e->next = NULL;
            head = e ;}}
    return head;
}

/*Inverter uma lista ligada*/
node* reverse(node* head){
    node* prev    = NULL;
    node* current = head;
    node* next;
    while (current != NULL){
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;}
    head = prev;
    return head;
}

/*Eliminar um node no inicio da lista ligada*/
node* remove_front(node* head)
{
    if(head == NULL)
        return NULL;
    node *front = head;
    head = head->next;
    front->next = NULL;
    /*se este é o ultimo node na lista*/
    if(front == head)
        head = NULL;
    free(front);
    return head;
}

/*Eliminar um node no fim da lista ligada*/
node* remove_back(node* head){
    if(head == NULL)
        return NULL;
    node *cursor = head;
    node *back = NULL;
    while(cursor->next != NULL){
        back = cursor;
        cursor = cursor->next;}
    if(back != NULL)
        back->next = NULL;
    /*se este é o ultimo node na lista*/
    if(cursor == head)
        head = NULL;
    free(cursor);
    return head;
}

/*Eliminar um node no meio da lista ligada*/
node* remove_any(node* head,node* nd){
    /*se o node é o primeiro node*/
    if(nd == head){
        head = remove_front(head);
        return head;}
    /*se o node é o ultimo node*/
    if(nd->next == NULL){
        head = remove_back(head);
        return head;}
    /*se o node é o node do meio*/
    node* cursor = head;
    while(cursor != NULL){
        if(cursor->next = nd)
            break;
        cursor = cursor->next;}
    if(cursor != NULL){
        node* tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
        free(tmp);}
    return head;
}

/*Apagar a toda a lista ligada*/
void dispose(node *head){
    node *cursor, *tmp;
      if(head != NULL){
        cursor = head->next;
        head->next = NULL;
        while(cursor != NULL){
            tmp = cursor->next;
            free(cursor);
            cursor = tmp;}}
}
