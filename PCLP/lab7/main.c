#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void pb1_main() {
    const int N = 255;
    
    //citire cu scanf() - citesc pana dau de un enter
    char *str_scanf = (char *)calloc(N, sizeof(char));

    printf("Citire cu scanf(): ");
    scanf("%s", str_scanf);
    printf("Textul citit cu scanf(): %s - citeste un singur cuvant\n", str_scanf);
    free(str_scanf);

    //citire cu gets()
    char *str_gets = (char *)calloc(N, sizeof(char));

    printf("Citire cu gets(): ");
    fgets(str_gets, N, stdin);
    printf("Textul citit cu gets(): %s", str_gets);
    printf("gets() citeste linie cu linie\n");
    free(str_gets);

    return;
}


void pb2_main() {
    const int N = 255;
    char *str = (char *)calloc(N, sizeof(char));

    fgets(str, N, stdin);
    int len = my_strlen(str);
    printf("Lungime sirului de caractere: %d\n", len);
    my_output_str(str);
    free(str);
    return;
}


void pb3_main() {
    char *nume1, *nume2;
    int varsta1, varsta2;
    printf("Numele primei persoane: ");
    nume1 = create_input_str();
    printf("Numele celeilalte persoane: ");
    nume2 = create_input_str();
    scanf("%d", &varsta1);
    scanf("%d", &varsta2);
    if (strcmp(nume1, nume2) != 0) {
        if (varsta1 == varsta2) {
            puts(nume1);
            puts(nume2);
        }
        if (varsta1 < varsta2) {
            puts(nume1);
        }
        else {
            puts(nume2);
        }

    }

    free(nume1);
    free(nume2);
    return;
}


void pb4_main() {
    const int N = 30;
    char *str1 = (char*)calloc(N, sizeof(char));
    char *str2 = (char*)calloc(N, sizeof(char));
    char *str3 = (char *)calloc(N, sizeof(char));

    fgets(str1, N, stdin);
    fgets(str2, N, stdin);
    fgets(str3, N, stdin);

    //cu functie de biblioteca
    char *str_bibl = (char*)calloc(3 * N, sizeof(char));
    strcat(str_bibl, str1);
    strcat(str_bibl, str2);
    strcat(str_bibl, str3);
    puts(str_bibl);

    //cu functie proprie

    return;
}


void pb5_main() {
    const int N = 100;
    char *str = (char*)calloc(N, sizeof(char));
    scanf("%s", str);
    size_t len = strlen(str);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i != j) {
                printf("%c", str[j]);
            }
        }
        printf(", ");
    }
    printf("\n");
    return;
}


void pb6_main() {
    char *str = create_input_str();
    size_t len = strlen(str);
    int ans = 0, incepe_cu_vocala = 0, se_termina_vocala = 0;

    for (int i = 0; i < len; i++) {
        if (i == 0 && is_vowel(str[i])) {
            incepe_cu_vocala = 1;
        }
        if (str[i] == ' ' || i == len - 1) {
            if (is_vowel(str[i - 1]) && incepe_cu_vocala) {
                ans += 1;
            }
            incepe_cu_vocala = is_vowel(str[i + 1]);
        }
    }

    printf("Cuvinte care incep si se termina cu vocala: %d\n", ans);
    free(str);
    return;
}


void pb7_main() {
    char *str = create_input_str();
    int len = strlen(str);

    for (int i = 0 ; i < len; i++) {
        if (str[i] == 'z') {
            str[i] = 'a';
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            str[i] = str[i] + 1;
        }
    }

    puts(str);
    free(str);
    return;
}


void pb8_main() {
    char *str1 = create_input_str();
    char *str2 = create_input_str();

    if (is_sufix(str1, str2) || is_sufix(str2, str1)) {
        printf("Unul dintre cuvinte este sufix al celuilalt\n");
    }
    else {
        printf("Niciun cuvant nu este prefix al celuilalt\n");
    }
    return;
}


void pb9_main() {
    char *str = create_input_str();
    int len = strlen(str);
    int p, q;
    printf("Sa se afiseze subsirul intre pozitiile: ");
    scanf("%d%d", &p, &q);

    if (p > q) {
        swap_int(&p, &q);
    }
    printf("Sirul dintre pozitiile p si q: ");
    for (int i = p; i < q && i < len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    for (int i = 0 ; i < len; i++) {
        if (is_vowel(str[i])) {
            len = remove_leter_at_pos(i, str);
            i -= 1;
        }
    }

    printf("Sirul de caractere fara vocale: %s\n", str);
    free(str);
    return;
}


void pb10_main() {
    printf("Introduceti un cuvant format doar din litere mici: ");
    char *str = create_input_str();
    int len = strlen(str);
    for (int i = 0 ; i < len; i++) { 
        if (is_vowel(str[i])) {
            replace_with_capital(&str[i]);
        }
    }

    printf("Sirul cu toate vocalele litere mari: %s\n", str);
    free(str);
    return;
}


void pb11_main() {
    char *str = create_input_str();
    int len = strlen(str);
    for (int i = 0 ; i < len - 1; i++) {
        //primul si ultimul caracter
        if (i == 0 || str[i + 2] == '\0') {
            replace_with_capital(&str[i]);
        }
        else if (str[i - 1] == ' ' || str[i + 1] == ' ' ) { 
            replace_with_capital(&str[i]);
        }
    }
    
    printf("Noul sir de caractere: %s\n", str);
    free(str);
    return;
}


int main() {
    pb11_main();
    return 0;
}
