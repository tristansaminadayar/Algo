//
// Created by trist on 17/07/2020.
//
// Implementation de certaines structures de données en c
//

#include <stdio.h>
#include "..\Headers\Structure.h"

// Implementation des piles (LIFO)

void stack(struct pile *P, int x) {
    if (P->top == P->len - 1) printf("Debordement positif \n");
    else {
        P->top++;
        P->data[P->top] = x;
    }
}

int depilate(struct pile *P) {
    if (P->top == -1) {
        printf("Debordement negatif \n");
        return P->top;
    } else {
        P->top--;
        return P->data[P->top + 1];
    }
}

struct pile create_pile() {
    struct pile P = {.top = -1, .len = TAILLE};
    return P;
}

// Implementation de la file (FIFO)

void enqueue(struct queue *Q, int x) {
    if (Q->top == Q->bottom - 1 || (Q->top == Q->len && Q->bottom == 0 )) printf("Debordement positif \n");
    else {
        Q->data[Q->top] = x;
        if (Q->top == Q->len) Q->top = 0;
        else Q->top++;
    }
}

int dequeue(struct queue *Q) {
    if (Q->bottom == Q->top ) printf("Debordement negatif \n");
    else {
        int x = Q->data[Q->bottom];
        if (Q->bottom == Q->len) Q->bottom = 0;
        else Q->bottom++;
        return x;
    }
}

struct queue create_queue() {
    struct queue Q = {.top = 0, .bottom = 0, .len = TAILLE};
    return Q;
}

// Implementation des listes chainées

struct chained_list create_chained_list() {
    struct chained_list result = {.nil = {.prev = result.nil.next, .next = result.nil.prev}};
    return result;
}

struct link *chained_list_search(struct chained_list *L, int k) {
    struct link *x = L->nil.next;
    while (x != NULL && x->key != k) x = x->next;
    return x;
}

void chained_list_insert(struct chained_list *L, struct link x) {
    x.next = L->nil.next;
    L->nil.next->prev = &x;
    L->nil.next = &x;
    x.prev = &(L->nil);
}

void chained_list_delete(struct chained_list *L, struct link *x) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
}

struct tree create_tree() {
    struct tree result = {NULL, NULL};
    return result;
}

void left_rotate(struct tree T, struct node *x) {
    struct node *y = x->right;
    x->right = y->left;
    if (y->left != T.nil) y->left->p = x;
    y->p = x->p;
    if (x->p == T.nil) T.root = y;
    else if (x == x->p->left) x->p->left = y;
    else x->p->right = y;
    y->left = x;
    x->p = y;
}

void right_rotate(struct tree T, struct node *x) {
    struct node *y = x->left;
    x->left = y->right;
    if (y->right != T.nil) y->right->p = x;
    y->p = x->p;
    if (x->p == T.nil) T.root = y;
    else if (x == x->p->right) x->p->right = y;
    else x->p->left = y;
    y->right = x;
    x->p = y;
}

void tree_insert(struct tree T, struct node *z) {
    struct node *y = T.nil;
    struct node *x = T.root;
    while (x != T.nil) {
        y = x;
        if (z->key <= x->key) x = x->left;
        else x = x->right;
    }
    z->p = y;
    if (y == T.nil) T.root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;
    z->left = T.nil;
    z->right = T.nil;
    z->color = 'r';
    correct_insert(T, z);
}

void correct_insert(struct tree T, struct node *z) {
    while (z->p->color == 'r') {
        if (z->p == z->p->p->left) {
            struct node *y = z->p->p->right;
            if (y->color == 'r') {
                z->p->color = 'n';
                y->color = 'n';
                z->p->p->color = 'r';
                z = z->p->p;
            } else if (z == z->p->right) {
                z = z->p;
                left_rotate(T, z);
            }
            z->p->color = 'n';
            z->p->p->color = 'r';
            right_rotate(T, z->p->p);
        } else {
            struct node *y = z->p->p->left;
            if (y->color == 'r') {
                z->p->color = 'n';
                y->color = 'n';
                z->p->p->color = 'r';
                z = z->p->p;
            } else if (z == z->p->left) {
                z = z->p;
                right_rotate(T, z);
            }
            z->p->color = 'n';
            z->p->p->color = 'r';
            left_rotate(T, z->p->p);
        }
    }
    T.root->color = 'n';
}

void transplant(struct tree T, struct node *u, struct node *v) {
    if (u->p == T.nil) T.root = v;
    else if (u == u->p->left) u->p->left = v;
    else u->p->right = v;
    v->p = u->p;
}

void delete(struct tree T, struct node *z) {
    struct node *y = z;
    struct node *x = NULL;
    char y_origin_color = y->color;
    if (z->left == T.nil) {
        x = z->right;
        transplant(T, z, z->right);
    } else if (z->right == T.nil) {
        x = z->left;
        transplant(T, z, z->left);
    } else {
        y = minimum(z->right);
        y_origin_color = y->color;
        x = y->right;
        if (y->p == z) x->p = y;
        else {
            transplant(T, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        transplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;
    }
    if (y_origin_color == 'n') correct_delete(T, x);
}

struct node *minimum(struct node *x) {
    while (x->left != NULL) x = x->left;
    return x;
}

struct node *maximum(struct node *x) {
    while (x->right != NULL) x = x->right;
    return x;
}

void correct_delete(struct tree T, struct node *x) {
    while (x != T.root && x->color == 'n') {
        if (x == x->p->left) {
            struct node *w = x->p->right;
            if (w->color == 'r') {
                w->color = 'n';
                x->p->color = 'r';
                left_rotate(T, x->p);
                w = x->p->right;
            }
            if (w->left->color == 'n' && w->right->color == 'n') {
                w->color = 'r';
                x = x->p;
            } else if (w->right->color == 'n') {
                w->left->color = 'n';
                w->color = 'r';
                right_rotate(T, w);
                w = x->p->right;
            }
            w->color = x->p->color;
            x->p->color = 'n';
            w->right->color = 'n';
            left_rotate(T, x->p);
            x = T.root;
        } else {
            struct node *w = x->p->left;
            if (w->color == 'r') {
                w->color = 'n';
                x->p->color = 'r';
                left_rotate(T, x->p);
                w = x->p->left;
            }
            if (w->right->color == 'n' && w->left->color == 'n') {
                w->color = 'r';
                x = x->p;
            } else if (w->left->color == 'n') {
                w->right->color = 'n';
                w->color = 'r';
                left_rotate(T, w);
                w = x->p->left;
            }
            w->color = x->p->color;
            x->p->color = 'n';
            w->left->color = 'n';
            right_rotate(T, x->p);
            x = T.root;
        }
    }
    x->color = 'n';
}

struct node *search(struct node *x, int k) {
    if (x == NULL || k == x->key) return x;
    if (k < x->key) return search(x->left, k);
    else return search(x->right, k);
}

