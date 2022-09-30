#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 * TP 5 -- Listes chaînées
 */

struct list{
    struct cell* first;
};

struct cell{
    double value;
    struct cell *next;
};

struct list *create_list(){
    struct list *l = malloc(sizeof(struct list));
    l->first = NULL;
    return l;
}

void push(struct list *l, struct cell *c){
    /* add a cell to the list */
    l->first = c;
}

double pop(struct list *l){
    /* remove the last cell of the list and return its value */
    struct cell *c = l->first;
    while (c->next->next != NULL){
        c = c->next;
    }
    double value = c->next->value;
    c->next = NULL;
    free(c->next);
    return value;
}


void print_list(struct list *l){
    struct cell *c = l->first;
    while (c != NULL){
        printf("%f ", c->value);
        c = c->next;
    }
    printf("\n");
}

int main() {
    struct list l;
    struct cell c1, c2, c3;
    c1.value = 3;
    c2.value = 15;
    c3.value = 7;
    c1.next = &c2;
    c2.next = &c3;
    c3.next = NULL;
    l.first = &c1;
    print_list(&l);
    pop(&l);
    print_list(&l);
    return 0;

}