//
// Created by trist on 17/07/2020.
//
// Implementation de certaines structures de données en c
//

#include <stdio.h>
#include "..\Headers\Structure.h"

// Implementation des piles (LIFO)

void stack(struct pile P, int x) {
    if (P.top > P.len) printf("Débordement positif");
    else {
        P.top++;
        P.data[P.top] = x;
    }
}

int depilate(struct pile P) {
    if (P.top == 0) {
        printf("Débordement négatif");
        return P.top;
    } else {
        P.top--;
        return P.data[P.top - 1];
    }
}

struct pile create_pile() {
    struct pile P = {.top = 0, .len = 100};
    return P;
}

// Implementation de la file (FIFO)

void enqueue(struct queue Q, int x) {
    Q.data[Q.bottom] = x;
    if (Q.bottom == Q.len) Q.bottom = 1;
    else Q.bottom++;
}

int dequeue(struct queue Q) {
    int x = Q.data[Q.top];
    if (Q.top == Q.len) Q.top = 1;
    else Q.top++;
    return x;
}

struct queue create_queue() {
    struct queue Q = {.top = 0, .bottom = 0, .len = 100};
    return Q;
}

// Implementation des listes chainées

struct chained_list create_chained_list() {
    struct chained_list result = {.nil = {.prev = result.nil.next, .next = result.nil.prev}};
    return result;
}

struct link *chained_list_search(struct chained_list L, int k) {
    struct link *x = L.nil.next;
    while (x != NULL && x->key != k) x = x->next;
    return x;
}

void chained_list_insert(struct chained_list L, struct link x) {
    x.next = L.nil.next;
    L.nil.next->prev = &x;
    L.nil.next = &x;
    x.prev = &(L.nil);
}

void chained_list_delete(struct chained_list L, struct link x) {
    x.prev->next = x.next;
    x.next->prev = x.prev;
}


