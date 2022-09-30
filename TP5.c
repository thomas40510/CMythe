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

/*
 * Random functions to test select
 */
int isOdd(double value){
    return (int)value % 2 == 1;
}

int isEven(double value){
    return (int)value % 2 == 0;
}

int supToTen(double value){
    return value > 10.0;
}

/****/

/*
 * Random functions to apply to list elements
 */

double doubleValue(double value){
    return value * 2;
}

int intValue(double value){
    return (int)value;
}

double square(double value){
    return value * value;
}

/*****/

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

int size(struct list *l){
    /* return the number of cells in the list */
    int size = 0;
    struct cell *c = l->first;
    while (c != NULL){
        size++;
        c = c->next;
    }
    return size;
}

double get(struct list *l, int index){
    /* return the value of the cell at the given index or -1 if out of list */
    struct cell *c = l->first;
    if (index >= size(l)){
        return -1;
    } else {
        for (int i = 0; i < index; i++) {
            c = c->next;
        }
        return c->value;
    }
}

struct list *sort(struct list *l){
    /* sort the list in ascending order */
    struct list *sorted = create_list();
    struct cell *c = l->first;
    while (c != NULL){
        struct cell *new_cell = malloc(sizeof(struct cell));
        new_cell->value = c->value;
        new_cell->next = NULL;
        struct cell *c2 = sorted->first;
        if (c2 == NULL){
            sorted->first = new_cell;
        } else {
            while (c2->next != NULL && c2->next->value < new_cell->value){
                c2 = c2->next;
            }
            new_cell->next = c2->next;
            c2->next = new_cell;
        }
        c = c->next;
    }
    return sorted;
}

struct list *select(struct list *l, int (*f)(double)){
    /* return a new list containing only the cells for which f is true */
    struct list *selected = create_list();
    struct cell *c = l->first;
    while (c != NULL){
        if (f(c->value)){
            struct cell *new_cell = malloc(sizeof(struct cell));
            new_cell->value = c->value;
            new_cell->next = NULL;
            struct cell *c2 = selected->first;
            if (c2 == NULL){
                selected->first = new_cell;
            } else {
                while (c2->next != NULL){
                    c2 = c2->next;
                }
                c2->next = new_cell;
            }
        }
        c = c->next;
    }
    return selected;
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
    print_list(sort(&l));
    print_list(select(&l, supToTen));
    printf("size: %d\n", size(&l));
    pop(&l);
    print_list(&l);
    printf("size: %d\n", size(&l));
    printf("get: %f\n", get(&l, 1));
    return 0;

}