//
// Created by trist on 17/07/2020.
//
// Implementation de certain algorithmes de tris.
//

#include "../Headers/Sort.h"
#include <stdio.h>
#include <stdlib.h>

void buble_sort(int A[], int len) {
    // Temps d'execution est Thêta(n^2)
    for (int i = len - 1; i > 0; i--)
        for (int j = 0; j < i; i++)
            if (A[j + 1] < A[j]) {
                int data = A[j];
                A[j] = A[j + 1];
                A[j + 1] = data;
            }
}

void insertion_sort_increase(int A[], int len) {
    // Temps d'execution est Thêta(n^2)
    for (int j = 1; j < len; j++) {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

void insertion_sort_decrease(int A[], int len) {
    // Temps d'execution est Thêta(n^2)
    for (int j = 1; j < len; j++) {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] < key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

void selection_sort_increase(int A[], int len) {
    // Temps d'execution est Thêta(n^2)
    for (size_t i = 0; i < (len - 1); i++) {
        int min = i;
        for (size_t i2 = (i + 1); i2 < len; i2++) {
            if (A[i2] < A[min]) {
                min = i2;
            }
        }
        int val_i = A[i];
        A[i] = A[min];
        A[min] = val_i;
    }
}

// Tri par fusion

void merge(int A[], int s, int m, int e) {
    // Fonction fusionnant deux partie de tableau trié en une seul
    int n_1 = m - s + 1, n_2 = e - m;
    int left[n_1], right[n_2];
    for (size_t i = 0; i < n_1; i++)
        left[i] = A[s + i];
    for (size_t i = 0; i < n_2; i++)
        right[i] = A[m + i + 1];
    int i = 0, j = 0;
    for (size_t k = s; k <= e; k++) {
        if (j >= n_2) {
            A[k] = left[i];
            i++;
        } else if (i >= n_1) {
            A[k] = right[j];
            j++;
        } else if (left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }
    }
}

void merge_sort(int A[], int s, int e) {
    // Temps d'execution est Thêta(n lg n)
    if (s < e) {
        int m = (s + e) / 2;
        merge_sort(A, s, m);
        merge_sort(A, m + 1, e);
        merge(A, s, m, e);
    }
}

// Tri par tas

void entasser_max(struct tas *A, int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int max = (l <= A->taille && A->data[l - 1] > A->data[i - 1]) ? l : i;
    if (r <= A->taille && A->data[r - 1] > A->data[max - 1])
        max = r;
    if (max != i) {
        int swap = A->data[i - 1];
        A->data[i - 1] = A->data[max - 1];
        A->data[max - 1] = swap;
        entasser_max(A, max);
    }
}

void construire_tas_max(struct tas *A) {
    A->taille = A->longueur;
    for (int i = (A->longueur / 2); i >= 1; i--) {
        entasser_max(A, i);
    }
}

void tri_par_tas(struct tas *A) {
    construire_tas_max(A);
    for (int i = A->longueur; i >= 2; i--) {
        int swap = A->data[0];
        A->data[0] = A->data[i - 1];
        A->data[i - 1] = swap;
        A->taille--;
        entasser_max(A, 1);
    }
}

// Quicksort

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            int data = A[i];
            A[i] = A[j];
            A[j] = data;
        }
    }
    int data = A[i + 1];
    A[i + 1] = A[r];
    A[r] = data;
    return i + 1;
}

void quick_sort(int A[], int p, int r) {
    // Temps d'execution (cas moyen) est Thêta(n lg n)
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q, r);
    }
}

// Tri par dénombrement

void counting_sort(int A[], int B[], int len) {
    // Temps d'execution est Thêta(n)
    int max;
    for (int i = 0; i < len; ++i) {
        if (A[i] > max) max = A[i];
    }
    max++;
    int *C = malloc(sizeof(int) * max);
    for (int i = 0; i <= max; i++) C[i] = 0;
    for (int i = 0; i < len; i++)
        C[A[i]]++;
    for (int i = 1; i <= max; i++)
        C[i] += C[i - 1];
    for (int i = (len - 1); i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}