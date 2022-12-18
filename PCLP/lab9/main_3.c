#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char cuv[15];
    struct Node *next;
};


struct Node *create_linked_list() {
    struct Node *head = NULL, *tmp = NULL;
    int n;

    printf("Cate cuvinte vor fi introduse? ");
    scanf("%d", &n);
    printf("Introduceti %d cuvinte:\n", n);

    for (int i = 0; i < n; i++) {
        struct Node *new_node = malloc(sizeof(struct Node));
        char input[15];
        scanf("%s", input);
        strcpy(new_node->cuv, input);

        if (head == NULL) {
            head = new_node;
            tmp = new_node;
        }
        else {
            tmp->next = new_node;
            tmp = tmp->next;
        }
    }

    return head;
}


void print_valoare_adresa(struct Node *head) {
    struct Node *temp = head;

    printf("\nPrima cerinta\n------\n");
    while (temp != NULL) {
        printf("Valoare: %s\n", temp->cuv);
        printf("Adresa urm: %p\n------\n", temp->next);
        temp = temp->next;
    }
}


int lungime_lista(struct Node *head) {
    struct Node *temp = head;
    int lungime = 0;

    while (temp != NULL) {
        temp = temp->next;
        lungime += 1;
    }

    return lungime;
}


char *formeaza_propozitie(struct Node *head) {
    char *prop = (char *)calloc(lungime_lista(head), sizeof(struct Node));
    struct Node *temp = head;

    while (temp != NULL) {
        strcat(prop, temp->cuv);
        strcat(prop, " ");
        temp = temp->next;
    }

    return prop;
}


int main() {
    struct Node *head = create_linked_list();

    print_valoare_adresa(head);

    char *prop = formeaza_propozitie(head);
    printf("\nCerinta 2: %s\n", prop);

    return 0;
}
