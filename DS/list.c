//Adele PATAROT

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// constructs a new (empty) list
List *list_create(void) {
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const List *list) {
    size_t count = 0;

    ListNode *p=list->first;
    while(p!=NULL) {
        count++;
        p=p->next;
    }

    return count;
}

// inserts item_data at *end* of a list
void list_addlast(List *list, data_t item_data) {
    ListNode* new=malloc(sizeof(ListNode));

    new->data=item_data;
    new->next=NULL; //sera le nouveau dernier element

    new->prev=list->last;
    // list->last->next=new; // le dernier pointe maintenant vers le nouveau dernier element 
    free(new);
}

// removes the item from *end* of the list and returns its value
data_t list_rmlast(List *list) {

    return -1;
}

void list_print(List *list){
    for(int i=0; i<list_count(list); i++){
        printf("hello world\n");
    }
}



int main(void) {

    List *l = list_create();

    assert(list_count(l)==0);

list_print(l);
    list_addlast(l,10);
    list_addlast(l,20);
    list_addlast(l,30);
    list_addlast(l,40);

    // assert(list_count(l)==4);

    list_print(l);

    // data_t t =  list_rmlast(l);

    // assert(t==40);
    // list_print(l);

    return 0;
}