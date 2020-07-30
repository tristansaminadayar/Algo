//
// Created by trist on 17/07/2020.
//

#include <stdio.h>
#include "..\Headers\Sort.h"
#include "..\Headers\Structure.h"
#include <stdlib.h>
#include <time.h>

int verif(const int A[], int len) {
    for (int i = 0; i < (len - 1); i++) {
        if (A[i] > A[i + 1]) return 0;
    }
    return 1;
}

int generate_random_tabular(int A[], int len){
    for (int j = 0; j < len; ++j) {
        A[j] = rand() % 1000;
    }
}

void test_tris(){
    printf(">>> Debut des tests des fonctions de tris \n");
    srand(time(NULL));
    int sum = 0;
    long long int init = time(NULL);
    for (int i = 0; i < 100; ++i) {
        int A[1000];
        generate_random_tabular(A, 1000);
        insertion_sort_increase(A, 1000);
        sum += verif(A, 1000);
    }
    long long int end = time(NULL);
    printf("Test tri par insertion avec %d erreur(s) en %lld secondes \n", 100 - sum, end - init);
    sum = 0;
    init = time(NULL);
    for (int i = 0; i < 100; ++i) {
        int A[1000];
        generate_random_tabular(A, 1000);
        selection_sort_increase(A, 1000);
        sum += verif(A, 1000);
    }
    end = time(NULL);
    printf("Test tri par selection avec %d erreur(s) en %lld secondes \n", 100 - sum, end - init);
    sum = 0;
    init = time(NULL);
    for (int i = 0; i < 100; ++i) {
        int A[1000];
        generate_random_tabular(A, 1000);
        merge_sort(A, 0, 999);
        sum += verif(A, 1000);
    }
    end = time(NULL);
    printf("Test tri par fusion avec %d erreur(s) en %lld secondes \n", 100 - sum, end - init);
    sum = 0;
    init = time(NULL);
    for (int i = 0; i < 100; ++i) {
        int A[10000];
        generate_random_tabular(A, 1000);
        quick_sort(A, 0, 999);
        sum += verif(A, 1000);
    }
    end = time(NULL);
    printf("Test tri rapide avec %d erreur(s) en %lld secondes \n", 100 - sum, end - init);
    sum = 0;
    init = time(NULL);
    for (int i = 0; i < 100; ++i) {
        int A[1000];
        int B[1000] = {0};
        generate_random_tabular(A, 1000);
        counting_sort(A, B, 1000);
        sum += verif(B, 1000);
    }
    end = time(NULL);
    printf("Test tri par denombrement avec %d erreur(s) en %lld secondes \n", 100 - sum, end - init);
    sum = 0;
    init = time(NULL);
    for (int i = 0; i < 100; ++i) {
        struct tas A = {.longueur = 1000};
        generate_random_tabular(A.data, 1000);
        tri_par_tas(&A);
        sum += verif(A.data, 1000);
    }
    end = time(NULL);
    printf("Test tri par tas avec %d erreur(s) en %lld secondes \n", 100 - sum, end - init);
}

void test_structure() {

    // Test des piles
    /*
    struct pile P = create_pile();
    stack(&P, 100);
    stack(&P, 1000);
    stack(&P, 10000);
    printf("%d %d %d \n", P.data[0], P.data[1], P.data[2]);
    printf("%d \n", depilate(&P));
    printf("%d \n", depilate(&P));
    printf("%d \n", depilate(&P));
    */
    // Test des files
    /*
    struct queue Q = create_queue();
    enqueue(&Q, 10);
    enqueue(&Q, 100);
    enqueue(&Q, 1000);
    enqueue(&Q, 10000);
    printf("%d %d %d %d \n", Q.data[0], Q.data[1], Q.data[2], Q.data[3]);
    printf("%d \n", dequeue(&Q));
    printf("%d \n", dequeue(&Q));
    printf("%d \n", dequeue(&Q));
    printf("%d \n", dequeue(&Q));
    printf("%d \n", dequeue(&Q));
    */
    // Test des listes chainées

    struct chained_list L = create_chained_list();
    struct link item0 = {.key = 10};
    struct link item1 = {.key = 100};
    struct link item2 = {.key = 1000};
    struct link item3 = {.key = 10000};
    chained_list_insert(&L, item0);
    chained_list_insert(&L, item1);
    chained_list_insert(&L, item2);
    chained_list_insert(&L, item3);


}
int main(int argc, char *argv[]) {
    test_tris();
    test_structure();
    return 0;
}
