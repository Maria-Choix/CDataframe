#ifndef COLUMN_H
#define COLUMN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// struct pour une colonne (entiers)
typedef struct {
    int *data;
    int size;
} IntCol;


// fonctions pour gérer la col
// 1: initialiser une col
void create_col(IntCol *col, int size){
    (*col).data = malloc(size * sizeof(int));
    (*col).size = size;
}

// 2: insérer une valeur dans une col
int insert_value_col(IntCol* col, int value) {
    if ((*col).size == (*col).physical_size) {
        int* new_data = realloc((*col).data, ((*col).physical_size + 256) * sizeof(int));
        if (new_data == NULL) {
            return 0;
        }
        (*col).data = new_data;
        (*col).physical_size += 256;
    }

    (*col).data[(*col).size] = value;
    (*col).size++;
    return 1;
}

// 3: libérer l'espace allouée par une col
void delete_col(IntCol *col) {
    free((*col).data);
    (*col).data = NULL;
    (*col).size = 0;
}

// 4: afficher la colonne
void print_col(IntCol *col) {
    for (size_t i = 0; i < (*col).size; i++) {
        printf("[%zu]: %d\n", i, (*col).data[i]);
    }
}

// autres fonctions
int count_occurrences(IntCol *col, int x) {
    int count = 0;
    for (int i = 0; i < (*col).size; i++) {
        if ((*col).data[i] == x) {
            count++;
        }
    }
    return count;
}

int value_position(IntCol *col, int x) {
    if (x < 0 || x >= (*col).size) {
        return -1;
    }
    return (*col).data[x];
}

int values_supp(IntCol *col, int x) {
    int count = 0;
    for (int i = 0; i < (*col).size; i++) {
        if ((*col).data[i] > x) {
            count++;
        }
    }
    return count;
}

int values_inf(IntCol *col, int x) {
    int count = 0;
    for (int i = 0; i < (*col).size; i++) {
        if ((*col).data[i] < x) {
            count++;
        }
    }
    return count;
}

int values_egales(IntCol *col, int x) {
    int count = 0;
    for (int i = 0; i < (*col).size; i++) {
        if ((*col).data[i] == x) {
            count++;}
    }
    return count;
}


#endif // COLUMN_H
