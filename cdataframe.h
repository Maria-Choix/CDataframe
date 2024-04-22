#ifndef CDATAFRAME_C
#define CDATAFRAME_C

#include <stddef.h>
#include "column.c"

typedef struct {
    int num_cols; // nb de col
    int num_rows; // nb de rangées(lignes)
    Col** cols; // tab de colonnes
} CDataFrame;

// ALIMENTATION
CDataFrame* create_empty_dataframe(size_t num_cols, size_t num_rows) {
    CDataFrame* dataframe = malloc(sizeof(CDataFrame));
    (*dataframe).num_cols = num_cols;
    (*dataframe).num_rows = num_rows;
    (*dataframe).cols = malloc(num_cols * sizeof(IntCol*));

    for (int i = 0; i < num_cols; i++) {
        (*dataframe).cols[i] = malloc(sizeof(IntCol));
        if ((*dataframe).cols[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free((*dataframe).cols[j]);
            }
            free((*dataframe).cols);
            free(dataframe);
            return NULL;}
        create_col((*dataframe).cols[i], num_rows);}
    return dataframe;
}

void remplissage(CDataFrame *dataframe) {
    for (int i = 0; i < (*dataframe).num_rows; i++) {
        for (int j = 0; j < (*dataframe).num_cols; j++) {
            int value;
            scanf("%d", &value);
            insert_value_col((*dataframe).cols[j], value);
        }
    }
}
void remplissage_endur(CDataFrame *dataframe, int values[][MAX_ROWS]) {
    for (int i = 0; i < (*dataframe).num_rows; i++) {
        for (int j = 0; j < (*dataframe).num_cols; j++) {
            insert_value_col((*dataframe).cols[j], values[j][i]);
        }
    }
}


//A FFICHAGE
void afficher_dataframe(CDataFrame *dataframe) {
    for (int i = 0; i < (*dataframe).num_rows; i++) {
        printf("rangée %d:\n", i + 1);
        for (int j = 0; j < (*dataframe).num_cols; j++) {
            printf("colonne %d: ", j + 1);
            print_col((*dataframe).cols[j]);
        }
        printf("\n");}
}
void afficher_lignes_lim(CDataFrame *dataframe, int start_row, int end_row) {
    if (start_row > end_row || end_row >= (*dataframe).num_rows) {
        printf("limites de lignes invalides\n");
        return;
    }
    for (int i = start_row; i <= end_row; i++) {
        printf("rangée %d:\n", i + 1);
        for (int j = 0; j < (*dataframe).num_cols; j++) {
            printf("colonne %d: ", j + 1);
            print_col((*dataframe).cols[j]);
        }
        printf("\n");
    }
}
void afficher_col_lim(CDataFrame *dataframe, int start_col, int end_col) {
    if (start_col > end_col || end_col >= (*dataframe).num_cols) {
        printf("limites de colonnes invalides\n");
        return;
    }
    for (int i = 0; i < (*dataframe).num_rows; i++) {
        printf("rangée %d:\n", i + 1);
        for (int j = start_col; j <= end_col; j++) {
            printf("colonne %d: ", j + 1);
            print_col((*dataframe).cols[j]);
        }
        printf("\n");
    }
}

//OPÉRATIONS USUELLES
void ajt_ligne_dataframe(CDataFrame *dataframe, int *values) {
    for (int i = 0; i < (*dataframe).num_cols; i++) {
        insert_value_col((*dataframe).cols[i], values[i]);
    }
    (*dataframe).num_rows++;
}

void supp_ligne_dataframe(CDataFrame *dataframe, int row_index) {
    if (row_index < 0 || row_index >= (*dataframe).num_rows) {
        printf("index de ligne invalide\n");
        return;
    }
    for (int i = 0; i < (*dataframe).num_cols; i++) {
        delete_value_col((*dataframe).cols[i], row_index);
    }
    (*dataframe).num_rows--;
}
void ajt_col_dataframe(CDataFrame *dataframe, int *values, int col_size) {
    IntCol *new_col = malloc(sizeof(IntCol));
    create_col(new_col, col_size);
    for (int i = 0; i < col_size; i++) {
        insert_value_col(new_col, values[i]);
    }
    (*dataframe).cols[(*dataframe).num_cols++] = new_col;
}

void supp_col_dataframe(CDataFrame *dataframe, int col_index) {
    if (col_index < 0 || col_index >= (*dataframe).num_cols) {
        printf("index de colonne invalide\n");
        return;
    }
    delete_col((*dataframe).cols[col_index]);
    for (int i = col_index; i < (*dataframe).num_cols - 1; i++) {
        (*dataframe).cols[i] = (*dataframe).cols[i + 1];
    }
    (*dataframe).num_cols--;
}

int verifier_val_dataframe(CDataFrame *dataframe, int value) {
    for (int i = 0; i < (*dataframe).num_cols; i++) {
        if (value_exists_in_col((*dataframe).cols[i], value)) {
            return 1;}
    }
    return 0;
}
void acceder_remplacer_valeur(CDataFrame *dataframe, int row_index, int col_index, int new_value) {
    if (row_index < 0 || row_index >= (*dataframe).num_rows || col_index < 0 || col_index >= (*dataframe).num_cols) {
        printf("index de ligne ou de colonne invalide.\n");
        return;
    }
    replace_value_in_col((*dataframe).cols[col_index], row_index, new_value);
}

void afficher_nom_col(CDataFrame *dataframe) {
    printf("Noms des colonnes:\n");
    for (int i = 0; i < (*dataframe).num_cols; i++) {
        printf("Colonne %d\n", i + 1);
    }
}

#endif // CDATAFRAME_C
