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
