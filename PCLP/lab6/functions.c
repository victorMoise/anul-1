#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *input_vector(int *n) {
    printf("Numarul de elemente: ");
    scanf("%d", n);
    int *v = (int *)calloc(*n, sizeof(int));
    printf("Elementele vectorului: ");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &v[i]);
    }
    return v;
}


void output_vector(int n, int *v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return;
}


int **create_matrix(int rows, int cols) {
    int **matrix = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)calloc(cols, sizeof(int));
    }
    return matrix;
}


int **create_input_matrix(int *rows, int *cols) {
    printf("Numarul de linii: ");
    scanf("%d", rows);
    printf("Numarul de coloane: ");
    scanf("%d", cols);
    int **matrix = (int **)calloc(*rows, sizeof(int *));
    for (int i = 0; i < *rows; i++) {
        matrix[i] = (int *)calloc(*cols, sizeof(int));
    }
    printf("Elementele matricei:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}


void output_matrix(int n, int m, int **matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}


int is_sorted_arr(int n, int *v, int (*compare)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        if (!(*compare)(v[i], v[i + 1])) {
            return 0;
        }
    }
    return 1;
}


int perechi_elem_consec_identice(int n, int *v) {
    int perechi = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == v[i + 1]) {
            perechi += 1;
        }
    }
    return perechi;
}


int exista_x_in_v(int n, int x, int *v) {
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            return 1;
        }
    }
    return 0;
}


void cate_pos_neg_nule(int n, int *v, int *poz, int *neg, int *nule) {
    *poz = *neg = *nule = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            *nule += 1;
        }
        if (v[i] < 0) {
            *neg += 1;
        }
        if (v[i] > 0) {
            *poz += 1;
        }
    }
    return;
}


int copiere_comune(int n, int m, int *v1, int *v2, int *v3) {
    int size_c = 0;
    for (int i = 0; i < n; i++) {
        if (exista_x_in_v(m, v1[i], v2)) {
            if (!exista_x_in_v(m, v1[i], v3)) {
                v3[size_c++] = v1[i];
            }
        }
    }
    return size_c;
}


int val_minim_vector(int n, int *v) {
    int minim = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (v[i] < minim) {
            minim = v[i];
        }
    }
    return minim;
}


int pozitiile_minimului(int n, int *v, int *ans) {
    int poz = 0;
    int minim = val_minim_vector(n, v);
    for (int i = 0; i < n; i++) {
        if (v[i] == minim) {
            ans[poz++] = i;
        }
    }
    return poz;
}


int maxim_impar(int n, int *v) {
    int maxim = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 != 0 && v[i] > maxim) {
            maxim = v[i];
        }
    }
    return maxim;
}


void elimina_primul_elem_tot(int *n, int *v) {
    int element = v[0];
    for (int i = 0; i < *n; i++) {
        if (v[i] == element) {
            for (int j = i; j < *n - 1; j++) {
                v[j] = v[j + 1];
            }
            *n -= 1;
        }
    }
    if (v[*n - 1] == element) {
        *n -= 1;
    }
    return;
}


void pare_impare(int n, int *nr_pare, int *nr_impare, int *v, int *pare, int *impare) {
    *nr_impare = *nr_pare = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            pare[(*nr_pare)++] = v[i];
        }
        else {
            impare[(*nr_impare)++] = v[i];
        }
    }
    return;
}


void perm_circ_stanga(int n, int *v) {
    int primul_elem = v[0];
    for (int i = 0; i < n - 1; i++) {
        v[i] = v[i + 1];
    }
    v[n - 1] = primul_elem;
    return;
}


void perm_circ_dreapta(int n, int *v) {
    int ultimul_elem = v[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        v[i] = v[i - 1];
    }
    v[0] = ultimul_elem;
    return;
}


int arrays_identical(int n, int m, int *v1, int *v2) {
    if (n != m) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (v1[i] != v2[i]) {
            return 0;
        }
    }
    return 1;
}


int matrix_identical(int n1, int m1, int n2, int m2, int **a1, int **a2) {
    if (n1 != n2 || m1 != m2) {
        return 0;
    }   
    for (int i = 0; i < n1; i++) {
        if (!arrays_identical(m1, m2, a1[i], a2[i])) {
            return 0;
        }
    }
    return 1;
}


void interchange_vectors(int n, int *v1, int *v2) {
    for (int i = 0; i < n; i++) {
        int aux = v1[i];
        v1[i] = v2[i];
        v2[i] = aux;
    }
    return;
}


int sort_ascending(int a, int b) {
    return a > b;
}


int sort_descending(int a, int b) {
    return a < b;
}


void sort_vector(int n, int *v, int (*compare)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((*compare)(v[i], v[j])) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    return;
}


void swap_vars(int *a, int *b) {
    int aux= *a;
    *a = *b;
    *b = aux;
    return;
}


int sum_arr(int n, int *v) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    return sum;
}
