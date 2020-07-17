//
// Created by trist on 17/07/2020.
//

#ifndef ALGO_STRUCTURE_H
#define ALGO_STRUCTURE_H

struct pile{
    int data[100];
    int top;
};

void stack(struct pile P, int x);

int depilate(struct pile P);

#endif //ALGO_STRUCTURE_H
