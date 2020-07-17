//
// Created by trist on 17/07/2020.
//

#include <stdio.h>
#include "..\Headers\Sort.h"
#include <stdlib.h>
#include <time.h>

int verif(const int A[], int len) {
    for (int i = 0; i < (len - 1); i++) {
        if (A[i] > A[i + 1]) return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    printf("Debut des tests des fonctions de tris \n");
    srand(time(NULL));
    int sum = 0;
    long long int init = time(NULL);
    /*for (int i = 0; i < 100; ++i) {
        int tab[10000];
        for (int j = 0; j < 10000; ++j) {
            tab[j] = rand() % 10000000;
        }
        insertion_sort_increase(tab, 10000);
        sum += verif(tab, 10000);
    } */
    long long int end = time(NULL);
    /*printf("Test tri par insertion avec %d erreur(s) en %lld secondes \n", 100 - sum, end - init);
    sum = 0;
    init = time(NULL);
    for (int i = 0; i < 100; ++i) {
        int tab[10000];
        for (int j = 0; j < 10000; ++j) {
            tab[j] = rand() % 10000000;
        }
        selection_sort_increase(tab, 10000);
        sum += verif(tab, 10000);
    }
    end = time(NULL);
    printf("Test tri par selection avec %d erreur(s) en %lld secondes \n", 100 - sum, end - init);
    sum = 0;
    init = time(NULL);
    for (int i = 0; i < 100; ++i) {
        int tab[10000];
        for (int j = 0; j < 10000; ++j) {
            tab[j] = rand() % 10000000;
        }
        merge_sort(tab, 0, 9999);
        sum += verif(tab, 10000);
    }
    end = time(NULL);
    printf("Test tri par fusion avec %d erreur(s) en %lld secondes \n", 100 - sum, end - init);
    sum = 0;
    init = time(NULL);
    for (int i = 0; i < 100; ++i) {
        int tab[10000];
        for (int j = 0; j < 10000; ++j) {
            tab[j] = rand() % 10000000;
        }
        quick_sort(tab, 0, 9999);
        sum += verif(tab, 10000);
    }
    end = time(NULL);
    printf("Test tri rapide avec %d erreur(s) en %lld secondes \n", 100 - sum, end - init); */
    sum = 0;
    init = time(NULL);
    for (int i = 0; i < 100; ++i) {
        int tab[100];
        for (int j = 0; j < 100; ++j) {
            tab[j] = (rand() % 100) + 3;
        }
        int tabB[100];
        counting_sort(tab, tabB, 100, 200);
        sum += verif(tabB, 100);
    }
    end = time(NULL);
    printf("Test tri par denombrement avec %d erreur(s) en %lld secondes \n", 100 - sum, end - init);
    return 0;
}
