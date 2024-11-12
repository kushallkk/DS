#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void concatenateLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, data, n, i;

    do {
        printf("Choose an operation:\n");
        printf("1. Insert in List 1\n2. Insert in List 2\n3. Sort List 1\n4. Reverse List 1\n5. Concatenate Lists\n6. Display List 1\n7. Display List 2\n8. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert in List 1: ");
                scanf("%d", &data);
                insertNode(&list1, data);
                break;
            case 2:
                printf("Enter data to insert in List 2: ");
                scanf("%d", &data);
                insertNode(&list2, data);
                break;
            case 3:
                sortList(list1);
                printf("List 1 sorted.\n");
                break;
            case 4:
                reverseList(&list1);
                printf("List 1 reversed.\n");
                break;
            case 5:
                concatenateLists(&list1, list2);
                printf("Lists concatenated.\n");
                break;
            case 6:
                printf("List 1: ");
                displayList(list1);
                break;
            case 7:
                printf("List 2: ");
                displayList(list2);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 8);

    return 0;
}
