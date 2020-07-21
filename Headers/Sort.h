//
// Created by trist on 17/07/2020.
//

#ifndef ALGO_SORT_H
#define ALGO_SORT_H

void buble_sort(int A[], int len);

void insertion_sort_increase(int A[], int len);

void insertion_sort_decrease(int A[], int len);

void selection_sort_increase(int A[], int len);

// Tri par fusion

void merge(int A[], int s, int m, int e);

void merge_sort(int A[], int s, int e);

int partition(int A[], int p, int r);

void quick_sort(int A[], int p, int r);

void counting_sort(int A[], int B[], int len);

// Tri par tas

struct tas {
    int data[1000];
    int len;
    int longueur;
};

void tri_par_tas(struct tas *A);


#endif //ALGO_SORT_H
