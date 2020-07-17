//
// Created by trist on 17/07/2020.
//

#ifndef ALGO_STRUCTURE_H
#define ALGO_STRUCTURE_H

// Implementation des piles (LIFO)

struct pile {
    int data[100];
    int top;
    int len;
};

struct pile create_pile();

void stack(struct pile P, int x);

int depilate(struct pile P);

// Implementation de la file (FIFO)

struct queue {
    int data[100];
    int top;
    int bottom;
    int len;
};

void enqueue(struct queue Q, int x);

int dequeue(struct queue Q);

struct queue create_queue();

// Implementation des listes chainées

struct link {
    struct link *prev;
    struct link *next;
    int key;
    // Possibilité d'inserer des données satélites.
};

struct chained_list {
    struct link nil;
};

struct chained_list create_chained_list();

struct link *chained_list_search(struct chained_list L, int k);

void chained_list_insert(struct chained_list L, struct link x);

void chained_list_delete(struct chained_list L, struct link x);

#endif //ALGO_STRUCTURE_H
