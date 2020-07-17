//
// Created by trist on 17/07/2020.
//
// Implementation de certaines structures de données en c
//

#include <stdio.h>
#include "..\Headers\Structure.h"

// Implementation des piles (LIFO)

void stack(struct pile P, int x) {
    if (P.top > 100) printf("Débordement positif");
    else {
        P.top++;
        P.data[P.top] = x;
    }
}

int depilate(struct pile P) {
    if (P.top == 0) {
        printf("Débordement négatif");
        return P.top;
    }
    else {
        P.top--;
        return P.data[P.top - 1];
    }
}