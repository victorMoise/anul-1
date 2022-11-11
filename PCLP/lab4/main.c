#include <stdio.h>
#include <stdbool.h>

const int N = 100;

void pb1() {
    int n, v[N];
    bool cresc = false, desc = false, constant = false;

    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);
    printf("Introduceti elementele vectorului: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    if (v[0] < v[1]) {
        cresc = true;
    }
    else if (v[0] > v[1]) {
        desc = true;
    }
    else if (v[0] == v[1]) {
        constant  = true;
    }
    for (int i = 1; i < n - 1; i++) {
        if ((v[i] < v[i + 1] && !cresc) ||
            (v[i] > v[i + 1] && !desc) ||
            (constant && (v[i] != v[i + 1]))) {
            printf("aleator");
            return;
        }
    }
    if (cresc)
        printf("crescator");
    if (desc)
        printf("descrescator");
    if (constant)
        printf("constant");
    return;
}

void pb2() {
    int n, v[N], suma = 0, medie = 0, exista_in_vector = false;

    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);
    printf("Introduceti elementele vectorului: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        suma += v[i];
    }

    medie = suma / n;
    for (int i = 0; i < n; i++) {
        if (medie == v[i]) {
            printf("Media apare ca valoare in vector\n");
            exista_in_vector = true;
            break;
        }
    }
    if (!exista_in_vector) {
        printf("Media nu apare ca valoare in vector\n");
    }
    else {
        printf("Valoarea medie apare pe pozitiile: ");
        for (int i = 0; i < n; i++) {
            if (medie == v[i]) {
                printf("%d ", i + 1);
            }
        }
    }
    return;
}

void pb3() {
    int n, v[N];
    int start_sec, lungime = 0, lungime_max = 0;

    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);
    printf("Introduceti elementele vectorului: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        if (v[i] < v[i + 1]) {
            lungime += 1;
        }
        else {
            if (lungime > lungime_max) {
                lungime_max = lungime;
                start_sec = i - lungime;
                lungime = 1;
            }
        }
    }
    if (lungime > lungime_max) {
        lungime_max = lungime;
        start_sec = n - lungime;
    }
    printf("Lungimea celei mai lungi secvente crescatoare este: %d\n", lungime_max);
    printf("Secventa incepe de la pozitia: %d", start_sec + 1);
    return;
}

void pb4() {
    int n, m, vector1[N], vector2[N], ans[2 * N];

    printf("Introduceti numarul de elementele al primului vector: ");
    scanf("%d", &n);
    printf("Introduceti elemetele primului vector ordonat: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector1[i]);
    }
    printf("Introduceti numarul de elementele vectorului al doilea: ");
    scanf("%d", &m);
    printf("Introduceti elemetele celui de-al doilea vector ordonat: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &vector2[i]);
    }

    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (vector1[i] < vector2[j]) {
            if (vector1[i] % 2 != 0) {
                ans[k++] = vector1[i];
            }
            i++;
        }
        else {
            if(vector2[j] % 2 != 0) {
                ans[k++] = vector2[j];
            }
            j++;
        }
    }
    while (i < n) {
        if (vector1[i] % 2 != 0) {
            ans[k++] = vector1[i];
        }
        i++;
    }
    while (j < m) {
        if (vector2[j] % 2 != 0) {
            ans[k++] = vector2[j];
        }
        j++;
    }

    for (int i = 0; i < k; i++) {
        printf("%d ", ans[i]);
    }
    return;
}

void pb5() {
    return;
}

int main() {
    pb4();
    return 0;
}
