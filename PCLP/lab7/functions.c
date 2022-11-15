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


int este_vocala(char c) {
    char vocale[] = "aeiouAEIOU";
    if (strchr(vocale, c)) {
        return 1;
    }
    return 0;
}
