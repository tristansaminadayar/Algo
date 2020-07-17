//
// Created by trist on 17/07/2020.
//

#ifndef ALGO_STRUCTURE_H
#define ALGO_STRUCTURE_H

struct pile{
    int data[100];
    int top;
    int len;
};

struct pile create_pile();

void stack(struct pile P, int x);

int depilate(struct pile P);

struct queue{
    int data[100];
    int top;
    int bottom;
    int len;
};

void enqueue(struct queue Q, int x);

int dequeue(struct queue Q);

struct queue create_queue();

#endif //ALGO_STRUCTURE_H
