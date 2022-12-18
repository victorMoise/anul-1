#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char nume[26];
    int varsta;
    struct Node *next;
};


struct Node* create_linked_list() {
    int n;
    printf("Cate elemente vor fi introduse? ");
    scanf("%d", &n);
    
    struct Node *head = NULL;
    struct Node *temp = head;

    for (int i = 0; i < n; i++) {
        char name[100];
        int age;
        printf("Introduceti numele si varsta pentru persoana numarul %d: ", i+1);
        scanf("%s %d", name, &age);

        struct Node* new_node = malloc(sizeof(struct Node));
        strcpy(new_node->nume, name);
        new_node->varsta = age;
        new_node->next = NULL;
        if (head == NULL) {
            temp = new_node;
            head = new_node;
        } 
        else {
            temp->next = new_node;
            temp = temp->next;
        }
    }

    return head;
}


void solve(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->nume, "George") == 0 && temp->varsta == 19) {
            if (temp->next == NULL) {
                printf("George este ultima persoana din lista!\n");
                return;
            }
            else {
                if (temp->next->varsta > temp->varsta) {
                    printf("Urmatoarea persoana din lista este mai in varsta!\n");
                }
                else {
                    printf("George este mai in varsta decat urmatoarea persoana din lista!\n");
                }
                return;
            }
        }
        temp = temp->next;
    }
    return;
}


int main() {
    struct Node *head = create_linked_list();
    
    solve(head);


    return 0;
}
