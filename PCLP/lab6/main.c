#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "functions.h"


void pb1_main() {
    int n, *v;
    v = input_vector(&n);

    printf("%d", perechi_elem_consec_identice(n, v));

    free(v);
    return;
}


void pb2_main() {
    int n, *v;
    v = input_vector(&n);

    printf("%d", maxim_impar(n, v));

    free(v);
    return;
}


void pb3_main() {
    int n, *v, pos = 0, neg = 0, null = 0;
    v = input_vector(&n);

    cate_pos_neg_nule(n, v, &pos, &neg, &null);
    printf("%d %d %d", pos, neg, null);

    free(v);
    return;
}
 

void pb4_main() {
    int n, m, *v1, *v2, *v3, size_comune;
    v1 = input_vector(&n);
    v2 = input_vector(&m);

    int maxi;
    if (n > m) {
        maxi = n;
    }
    else maxi = m;
    v3 = (int*)calloc(maxi, sizeof(int));
    size_comune = copiere_comune(n, m, v1, v2, v3);
    output_vector(size_comune, v3);

    free(v1);
    free(v2);
    free(v3);
    return;
}


void pb5_main() {
    int n, *v, *minime;
    v = input_vector(&n);

    int size_minime = pozitiile_minimului(n, v, minime);
    output_vector(size_minime, minime);
    
    free(v);
    free(minime);
    return;
}


void pb6_main() {
    int n, *v;
    v = input_vector(&n);

    elimina_primul_elem_tot(&n, v);
    output_vector(n, v);

    free(v);
    return;
}


void pb7_main() {
    int n, size_pare, size_impare, *v, *pare, *impare;
    v = input_vector(&n);
    pare = (int *)calloc(n, sizeof(int));
    impare = (int *)calloc(n, sizeof(int));

    pare_impare(n, &size_pare, &size_impare, v, pare, impare);
    output_vector(size_pare, pare);
    output_vector(size_impare, impare);

    free(v);
    free(pare);
    free(impare);
    return; 
}


void pb8_main() {
    int n, m, **a;
    char perm_dir, clear;
    a = create_input_matrix(&n, &m);
    fflush(stdin);
    printf("In ce parte sa se efectueze permutarea? (s/d) ");
    scanf("%c%c", &clear, &perm_dir);

    for (int i = 0; i < n; i++) {
        if (perm_dir == 'D' || perm_dir == 'd') {
            for (int j = 0; j <= i; j++) {
                perm_circ_dreapta(m, a[i]);
            }
        } 
        else {
            for (int j = 0; j < i; j++) {
                perm_circ_stanga(m, a[i]);
            }
        }
    }

    output_matrix(n, m, a);
    free(a);
    return;
}


void pb9_main() {
    int n, m, **a, ans_line, ans_col, max_line = INT_MIN, max_col = INT_MIN;
    a = create_input_matrix(&n, &m);

    for (int i = 0; i < n; i++) {
        float suma = 0;
        for (int j = 0; j < m; j++) {
            suma += a[i][j];
        }
        if (suma > max_line) {
            ans_line = i;
            max_line = suma;
        }
    }
    for (int i = 0; i < m; i++) {
        int suma = 0;
        for (int j = 0; j < n; j++) {
            suma += a[j][i];
        }
        if (suma > max_col) {
            ans_col = i;
            max_col = suma;
        }
    }
    printf("Linia cu suma valorilor maxima: %d\n", ans_line);
    printf("Coloane cu cuma elementelor maxima: %d\n", ans_col);
    free(a);
    return;
}


void pb10_main() {
    int row1, col1, row2, col2, **mat1, **mat2;
    printf("Prima matrice:\n");
    mat1 = create_input_matrix(&row1, &col1);
    printf("A doua matrice:\n");
    mat2 = create_input_matrix(&row2, &col2);

    if (matrix_identical(row1, col1, row2, col2, mat1, mat2)) {
        printf("Matricele sunt identice\n");
    }
    else {
        printf("Matricele sunt diferite\n");
    }
    
    free(mat1);
    free(mat2);
    return;
}


void pb11_main() {
    int n, col, line, identical_lines = 0;
    int *v, **a, *line_pos;
    v = input_vector(&n);
    line_pos = calloc(n, sizeof(int));
    a = create_input_matrix(&line, &col);
    
    if (n != col) {
        printf("Dimensiunea vectorului trebuie sa coincida cu numarul de linii al matrice!\n");
        return;
    }        
    for (int i = 0; i < line; i++) {
        if (arrays_identical(n, col, v, a[i])) {
            line_pos[identical_lines++] = i;
        }
    }
    if (identical_lines == 0) {
        printf("Vectorul v nu se regaseste printre liniile matricei!\n");
        printf("Identicele liniei care va schimbata cu vectorul: ");
        int switch_line;
        scanf("%d", &switch_line);
        if (switch_line > line - 1) {
            printf("Nu se poate efectua operatia!\n");
            printf("Matricea nu a fost modificata\n");
            return;
        }
        for (int i = 0; i < col; i++) {
            a[switch_line][i] = v[i];
        } 
        printf("Noua matrice:\n");
        output_matrix(line, col, a);
        return;
    }
    else {
        printf("Vectorul este identic cu liniile matricei cu indicii: ");
        output_vector(identical_lines, line_pos);
    }
    
    free(a);
    free(v);
    free(line_pos);
    return;
}


void pb12_main() {
    int n, m, swap_line1, swap_line2, swap_col1, swap_col2, **a;
    a = create_input_matrix(&n, &m);
    printf("Doua linii ce vor fi interschimbate: ");
    scanf("%d%d", &swap_line1, &swap_line2);
    printf("Doua coloane ce vor fi interchimbate: ");
    scanf("%d%d", &swap_col1, &swap_col2);

    interchange_vectors(m, a[swap_line1], a[swap_line2]);
    for (int i = 0; i < m; i++) {
        int aux = a[i][swap_col1];
        a[i][swap_col1] = a[i][swap_col2];
        a[i][swap_col2] = aux;
    }

    output_matrix(n, m, a);
    
    free(a);
    return;
}


void pb13_main() {
    int rows, cols, **a;
    a = create_input_matrix(&rows, &cols);

    for (int i = 0; i < rows; i++) {
        sort_vector(cols, a[i], sort_ascending);
    }

    printf("Matricea dupa sortare pe linii:\n");
    output_matrix(rows, cols, a);

    free(a);
    return;
}


void pb14_main() {
    int rows, cols, **a;
    a = create_input_matrix(&rows, &cols);

    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            sort_vector(cols, a[i], sort_ascending);
        }
        else {
            sort_vector(cols, a[i], sort_descending);
        }
    }

    printf("Liniile pare au fost ordonate crescator\n");
    printf("Liniile impare au fost ordnate descrescator\n");
    printf("Matricea dupa sortare:\n");
    output_matrix(rows, cols, a);

    free(a);
    return;
}


void pb15_main() {
    int rows, cols, **mat;
    mat = create_input_matrix(&rows, &cols);

    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            int sum1 = sum_arr(cols, mat[i]);
            int sum2 = sum_arr(cols, mat[j]);
            if (sum1 > sum2) {
                for (int k = 0; k < cols; k++) {
                    swap_vars(&mat[i][k], &mat[j][k]);
                }
            }
        }
    }
    printf("Noua matrice:\n");
    output_matrix(rows, cols, mat);
    free(mat);
    return;
}


void pb16_main() {
    int rows, cols, rows_new_mat = 0;
    int **mat = create_input_matrix(&rows, &cols);
    int **new_mat = (int **)calloc(rows, sizeof(int));

    for (int i = 0; i < rows; i++) {
        if (is_sorted_arr(cols, mat[i], sort_ascending) || is_sorted_arr(cols, mat[i], sort_descending)) {
            new_mat[rows_new_mat] = (int *)calloc(cols, sizeof(int));
            for (int j = 0; j < cols; j++) {
                new_mat[rows_new_mat][j] = mat[i][j];
            }
            rows_new_mat += 1;
        }
    } 

    printf("Matricea creata:\n");
    output_matrix(rows_new_mat, cols, new_mat);
    free(mat);
    free(new_mat);
    return;
}


int main() {
    int n;
    int *v = input_vector(&n);
    sort_vector(n, v, sort_ascending);
    output_vector(n, v);
    return 0;
}
