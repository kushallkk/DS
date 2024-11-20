#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void insertLeft(Node** head, int target, int data) {
    Node* current = *head;
    while (current && current->data != target) {
        current = current->next;
    }
    if (!current) return;

    Node* newNode = createNode(data);
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev) current->prev->next = newNode;
    else *head = newNode;
    current->prev = newNode;
}

void deleteNode(Node** head, int value) {
    Node* current = *head;
    while (current && current->data != value) {
        current = current->next;
    }
    if (!current) return;

    if (current->prev) current->prev->next = current->next;
    else *head = current->next;
    if (current->next) current->next->prev = current->prev;

    free(current);
}

void displayList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data, target;
   printf("1. Create List\n2. Append to End\n3. Insert Left\n4. Delete Node\n5. Display List\n6. Exit\n");
        printf("Enter your choice: ");
    while (1) {

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the first node: ");
                scanf("%d", &data);
                head = createNode(data);
                break;
            case 2:
                printf("Enter data to append: ");
                scanf("%d", &data);
                append(&head, data);
                break;
            case 3:
                printf("Enter target node and new data: ");
                scanf("%d %d", &target, &data);
                insertLeft(&head, target, data);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                return 0;
        }
    }
}
