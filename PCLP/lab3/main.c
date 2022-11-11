#include <stdio.h>

const int N = 100;

int nrDiv(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            ans += 1;
        }
    }
    return ans;
}

void pb1() {
    int n, v[100];
    printf("Introduceti numarul de elemenente: ");
    scanf("%d", &n);
    printf("Introduceti elementele vectorului: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    //Subpunct a
    int val;
    printf("Introduceti valoarea dorita: ");
    scanf("%d", &val);
    printf("Elementele care depasesc valoarea introdusa: ");
    for (int i = 0; i < n; i++) {
        if (v[i] > val) {
            printf("%d de pe pozitia %d, ", v[i], i);
        }
    }
    printf("\n");

    //Subpunct b
    printf("Elementele de pe pozitii pare sunt: ");
    for (int i = 0; i < n; i += 2) {
        printf("%d ", v[i]);
    }
    printf("\n");

    //Subpunctul c
    int copie_n = n, copie_v[N];
    for (int i = 0; i < n; i++) {
        copie_v[i] = v[i];
    }
    printf("Sirul fara 0: ");
    for (int i = 0; i < copie_n; i++) {
        int num = copie_v[i];
        if (!num) {
            for (int j = i; j < copie_n - 1; j++) {
                copie_v[j] = copie_v[j + 1];
            }
            i -= 1;
            copie_n -= 1;
        }
    }
    for (int i = 0; i < copie_n; i++) {
        printf("%d ", copie_v[i]);
    }
    printf("\n");

    //Subpunctul d
    for (int i = 0; i < n; i++) {
        int nr_divizori = nrDiv(v[i]);
        v[i] = nr_divizori;
    }
    printf("Sirul inlocuit este: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return;
}

int main() {
    pb1();
    return 0;
}
