//Projet SDD1: un Cdataframe
//Auteurs: Maria Choix et Gautier Anagnostides
//ce fichier contient: définitions et fonctions nécessaires pour manipuler des colonnes de données (entiers) dans le projet.

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Définition de la structure pour une colonne d'entiers
typedef struct {
    int *data;      // pointeur vers les données de la colonne
    int size;       // taille logique de la colonne
    int physical_size; // taille physique de la colonne
} IntCol;

// Définition de l'enum pour les différents types de données
enum enum_type{
    NULLVAL = 1 , UINT, INT,  CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};

typedef enum enum_type ENUM_TYPE;

// Union pour les différents types de données (qui n'est finalement pas utilisée dans le fichier)
union column_type{
    unsigned int    uint_value;
    signed int  int_value;
    char    char_value;
    float    float_value;
    double    double_value;
    char*    string_value;
    void*    struct_value; // Pointeur générique
};

typedef union column_type COL_TYPE;

// Structure pour une colonne générique
struct column {
    char *title;               // Titre de la colonne
    unsigned int size;         // Taille logique de la colonne
    unsigned int max_size;     // Taille physique de la colonne
    ENUM_TYPE column_type;     // Type de données de la colonne
    COL_TYPE **data;           // Tableau de pointeurs vers les données stockées
    unsigned long long int *index; // Tableau des indices
};

typedef struct column COLUMN;

// 1: fonction pour initialiser une colonne d'entiers
// Paramètres: col: pointeur vers la colonne à initialiser; size: taille initiale de la colonne
void create_col(IntCol *col, int size){
    // Allocation mémoire pour les données de la colonne
    (*col).data = malloc(size * sizeof(int));
    (*col).size = size;
    (*col).physical_size = size;
}

// 2: fonction pour insérer une valeur dans une colonne
// Paramètres: col: pointeur vers la colonne;  value: valeur à insérer
// Retourne: 1 si l'insertion est réussie, 0 sinon
int insert_value_col(IntCol* col, int value) {
    // Vérification si la colonne a besoin de plus d'espace
    if ((*col).size == (*col).physical_size) {
        // réallocation de la mémoire pour agrandir la colonne
        int* new_data = realloc((*col).data, ((*col).physical_size + 256) * sizeof(int));
        if (new_data == NULL) {
            return 0; // échec de l'allocation mémoire
        }
        (*col).data = new_data;
        (*col).physical_size += 256;
    }

    // Insertion de la nouvelle valeur
    (*col).data[(*col).size] = value;
    (*col).size++;
    return 1;
}

// 3: fonction pour libérer l'espace alloué par une colonne
// Paramètres: col: pointeur vers la colonne à libérer
void delete_col(IntCol *col) {
    // Libération de la mémoire et réinitialisation des attributs
    free((*col).data);
    (*col).data = NULL;
    (*col).size = 0;
    (*col).physical_size = 0;
}

// 4: fonction pour afficher les valeurs de la colonne
// Paramètres:col: pointeur vers la colonne à afficher
void print_col(IntCol *col) {
    // Parcours de la colonne et affichage de chaque valeur
    for (size_t i = 0; i < (*col).size; i++) {
        printf("[%zu]: %d\n", i, (*col).data[i]);
    }
}

// 5: fonction pour compter les occurrences d'une valeur dans une colonne
// Paramètres: col: pointeur vers la colonne; x: valeur à compter
// Retourne: Le nombre d'occurrences de la valeur x
int count_occurrences(IntCol *col, int x) {
    int count = 0;
    // parcours de la colonne et comptage des occurrences de x
    for (int i = 0; i < (*col).size; i++) {
        if ((*col).data[i] == x) {
            count++;
        }
    }
    return count;
}

// 6: fonction pour obtenir la valeur à une position donnée dans la colonne
// Paramètres: col: pointeur vers la colonne; x: position dans la colonne
// Retourne: La valeur à la position x, ou -1 si x est en dehors des limites
int value_position(IntCol *col, int x) {
    if (x < 0 || x >= (*col).size) {
        return -1; // Position invalide
    }
    return (*col).data[x];
}

// 7: fonction pour compter les valeurs supérieures à un seuil donné
// Paramètres: col: pointeur vers la colonne; x: seuil de comparaison
// Retourne: le nombre de valeurs supérieures à x
int values_supp(IntCol *col, int x) {
    int count = 0;
    // Parcours de la colonne et comptage des valeurs supérieures à x
    for (int i = 0; i < (*col).size; i++) {
        if ((*col).data[i] > x) {
            count++;
        }
    }
    return count;
}

// 8: fonction pour compter les valeurs inférieures à un seuil donné
// Paramètres:col: pointeur vers la colonn; x: seuil de comparaison
// Retourne: le nombre de valeurs inférieures à x
int values_inf(IntCol *col, int x) {
    int count = 0;
    // Parcours de la colonne et comptage des valeurs inférieures à x
    for (int i = 0; i < (*col).size; i++) {
        if ((*col).data[i] < x) {
            count++;
        }
    }
    return count;
}

// 9: fonction pour compter les valeurs égales à une valeur donnée
// Paramètres:  col: pointeur vers la colonne; x: valeur de comparaison
// Retourne: le nombre de valeurs égales à x
int values_egales(IntCol *col, int x) {
    int count = 0;
    // parcours de la colonne et comptage des valeurs égales à x
    for (int i = 0; i < (*col).size; i++) {
        if ((*col).data[i] == x) {
            count++;
        }
    }
    return count;
}
