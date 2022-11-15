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
    if (varsta1 == varsta2) {
        puts(nume1);
        puts(nume2);
    }
    else if (varsta1 < varsta2) {
        puts(nume1);
    }
    else {
        puts(nume2);
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
        if (i == 0 && este_vocala(str[i])) {
            incepe_cu_vocala = 1;
        }
        if (i == len - 1 && incepe_cu_vocala && este_vocala(str[i])) {
            ans += 1;
        }
        if (str[i] == ' ') {
            if (este_vocala(str[i - 1]) && incepe_cu_vocala) {
                ans += 1;
            }
            incepe_cu_vocala = este_vocala(str[i + 1]);
        }
    }
    printf("Cuvinte care incep si se termina cu vocala: %d\n", ans);
    return;
}


int main() {
    pb6_main();
    return 0;
}
