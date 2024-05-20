//Projet SDD1: un Cdataframe
//Auteurs: Maria Choix et Gautier Anagnostides

#include <stdio.h>
#include "column.h"
#include "cdataframe.h"

int main() {
    IntCol *mycol = create_col(IntCol *col, 5);
    // utilisation fonctions gestion colonne
    int val1 = 10, val2=11;

    if (insert_value_col(mycol, val1)) {
        printf("Value added successfully to my column\n");}
    else {
        printf("Error adding value to my column\n");}

    if (insert_value_col(mycol, val2)) {
        printf("Value added successfully to my column\n");}
    else {
        printf("Error adding value to my column\n");}

    print_col(IntCol *mycol);

    delete_col(IntCol **mycol);



    return 0;
}
