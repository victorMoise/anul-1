#include "functions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

size_t my_strlen(char *str) {
    int lenght = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        lenght += 1;
    }
    return lenght;
}


void my_output_str(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    return;
}


char *create_input_str() {
    const int N = 255;
    char *str = (char *)calloc(N, sizeof(char));
    fgets(str, N, stdin);
    return str;
}


int is_vowel(char c) {
    char vocale[] = "aeiouAEIOU";
    if (strchr(vocale, c)) {
        return 1;
    }
    return 0;
}


void swap_str(char *str1, char *str2) {
    char *tmp = (char *)calloc(strlen(str1), sizeof(char));
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
    free(tmp);
    return;
}


int is_sufix(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 > len2) {
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[len1 - i - 1] != str2[len2 - i - 1]) {
            return 0;
        }
    }
    return 1;
}


int remove_leter_at_pos(int i, char *str) {
    int len = strlen(str);
    for (int j = i; j < len; j++) {
        str[j] = str[j + 1];
    }
    return len - 1;
}


void swap_int(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
    return;
}


void replace_with_capital(char *c) {
    *c = *c - 'a' + 'A';
    return;
}
