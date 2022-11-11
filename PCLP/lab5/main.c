//MOISE VICTOR
#include <stdio.h>

int pb1_este_palindrom(int n) {
    int oglinda = 0, copie;
    copie = n;
    while (n != 0) {
        oglinda= oglinda * 10 + n % 10;
        n /= 10;
    }
    if (copie == oglinda) {
        return 1;
    }
    else return 0;
}

void pb5(int n, int *nrcif, int *cif1, int *cif2, int *cif3) {
    *nrcif = 0, *cif1 = -1, *cif2 = -1, *cif3 = -1;
    int copie = n;
    while (copie != 0) {
        (*nrcif) += 1;
        copie /= 10;
    }
    if (n < 10) {
        *cif1 = n;
    }
    else if (n < 100) {
        *cif1 = n / 10;
        *cif2 = n % 10;
    }
    else {
        *cif3 = n % 10;
        *cif2 = n / 10 % 10;
        *cif1 = n / 100;
    }
    return;
}

void pb6(int n, int *ans) {
    *ans = 0;
    int cifre[10], p = 0;
    while (n != 0) {
        if (n % 10 % 2 == 0) {
            cifre[p++] = n % 10;
        }
        n /= 10;
    }
    if (p == 0) {
        *ans = -1;
    }
    else {
        for (int i = p - 1; i >= 0; i--) {
            *ans = *ans * 10 + cifre[i];
        }
    }
    return;
}

int pb2_este_nr_perfect(int n) {
    int sum_div = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum_div += i;
        }
    }
    if (sum_div == n) {
        return 1;
    }
    else return 0;
}

char pb3_sunt_ordonate(int a, int b, int c) {
    if (a == b && b == c) {
        return 'I';
    }
    else if (a < b && b < c) {
        return 'C';
    }
    else if (a > b && b > c) {
        return 'D';
    }
    else return 'N';
}

void pb4_trans_lit_mari(char *a, char *b, char *c) {
    if (*a >= 'a' && *a <= 'z') {
        (*a) = (char)(*a - 'a' + 'A');
    }
    if (*b >= 'a' && *b <= 'z') {
        (*b) = (char)(*b - 'a' + 'A');
    }
    if (*c >= 'a' && *c <= 'z') {
        (*c) = (char)(*c - 'a' + 'A');
    }
}

//setul de suplimentare
float expresie(float fibo, float fact) {
    return fibo / fact;
}

float fact_n(float n) {
    float ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

float fibo_n(float n) {
    //Al n-lea termen din sirul lui fibonacci
    if (n <= 1) {
        return n;
    }
    return fibo_n(n - 1) + fibo_n(n - 2);
}

int delta_abc(int a, int b, int c) {
    return b * b - 4 * a * c;
}

void rezultat(int a, int b, int c, float *x1, float *x2) {
    int delta = delta_abc(a, b, c);
    *x1 = (float)((-b + delta) / (2 * a));
    *x2 = (float)((-b - delta) / (2 * a));
}

int main() {
    /*
    fibo(n) / fact(n)
    float n;
    scanf("%f", &n);
    printf("%.3f", expresie(fibo_n(n), fact_n(n)));
    */


    /*
    rezolvarea ecuatiei de gradul 2
    */
    int a, b, c;
    float sol1, sol2;
    scanf("%d%d%d", &a, &b, &c);
    rezultat(a, b, c, &sol1, &sol2);
    printf("%.3f%.3f", sol1, sol2);

    return 0;
}
