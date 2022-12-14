#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 * TP 5 -- Listes chaînées
 */

struct list{
    struct cell* first;
};

struct file_pile{
    struct cell* first;
    struct file_pile (*add)(struct list, int);
    struct file_pile (*remove)(struct list, int);
};

struct cell{
    double value;
    struct cell *next;
};

struct list *create_list(){
    struct list *l = malloc(sizeof(struct list));
    l->first = NULL;
    if ()
    return l;
}

struct file_pile *create_file_pile(int type){
    /* create file or pile given the type wanted (0 for file, 1 for pile) */
    struct file_pile *fp = malloc(sizeof(struct file_pile));
    fp->first = NULL;
    if (type){
        fp->add = add_pile;
        fp->remove = remove_pile;
    } else{
        fp->add = add_file;
        fp->remove = remove_file;
    }
    return fp;
}

/*
 * Functions for files and piles
 */

struct file_pile *add_file(struct file_pile *fp, double value) {
    /* add a value to the end of the file */
    struct cell *c = malloc(sizeof(struct cell));
    c->value = value;
    c->next = NULL;
    if (fp->first == NULL) {
        fp->first = c;
    } else {
        struct cell *current = fp->first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = c;
    }
    return fp;
}

struct file_pile *remove_file(struct file_pile *fp) {
    /* remove the first value of the file */
    if (fp->first == NULL) {
        printf("Error: file is empty");
        exit(1);
    } else {
        struct cell *c = fp->first;
        fp->first = c->next;
        free(c);
    }
    return fp;
}

struct file_pile *add_pile(struct file_pile *fp, double value) {
    /* add a value to the beginning of the pile */
    struct cell *c = malloc(sizeof(struct cell));
    c->value = value;
    c->next = fp->first;
    fp->first = c;
    return fp;
}

struct file_pile *remove_pile(struct file_pile *fp) {
    /* remove the first value of the pile */
    if (fp->first == NULL) {
        printf("Error: pile is empty");
        exit(1);
    } else {
        struct cell *c = fp->first;
        fp->first = c->next;
        free(c);
    }
    return fp;
}
/*******/

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

struct list *collect(struct list *l, double (*f)(double)){
    /* return a new list containing the result of applying f to each cell */
    struct list *collected = create_list();
    struct cell *c = l->first;
    while (c != NULL){
        struct cell *new_cell = malloc(sizeof(struct cell));
        new_cell->value = f(c->value);
        new_cell->next = NULL;
        struct cell *c2 = collected->first;
        if (c2 == NULL){
            collected->first = new_cell;
        } else {
            while (c2->next != NULL){
                c2 = c2->next;
            }
            c2->next = new_cell;
        }
        c = c->next;
    }
    return collected;
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
    print_list(collect(&l, square));
    printf("size: %d\n", size(&l));
    pop(&l);
    print_list(&l);
    printf("size: %d\n", size(&l));
    printf("get: %f\n", get(&l, 1));
    return 0;

}