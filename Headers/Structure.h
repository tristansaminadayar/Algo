//
// Created by trist on 17/07/2020.
//

#ifndef ALGO_STRUCTURE_H
#define ALGO_STRUCTURE_H
#define TAILLE 4

// Implementation des piles (LIFO)

struct pile {
    int data[TAILLE];
    int top;
    int len;
};

struct pile create_pile();

void stack(struct pile *P, int x);

int depilate(struct pile *P);

// Implementation de la file (FIFO)

struct queue {
    int data[TAILLE];
    int top;
    int bottom;
    int len;
};

void enqueue(struct queue *Q, int x);

int dequeue(struct queue *Q);

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

struct link *chained_list_search(struct chained_list *L, int k);

void chained_list_insert(struct chained_list *L, struct link *x);

void chained_list_delete(struct link *x);

// Implementation des arbres rouge-noir

struct node {
    char color;
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *nil;
    struct node *root;
};

struct tree create_tree();

void left_rotate(struct tree T, struct node *x);

void right_rotate(struct tree T, struct node *x);

struct node *minimum(struct node *x);

struct node *maximum(struct node *x);

void tree_insert(struct tree T, struct node *z);

void correct_insert(struct tree T, struct node *z);

void transplant(struct tree T, struct node *u, struct node *v);

void delete(struct tree T, struct node *z);

void correct_delete(struct tree T, struct node *x);

struct node *search(struct node *x, int k);

#endif //ALGO_STRUCTURE_H
