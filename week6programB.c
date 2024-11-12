#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    printf("Popped element: %d\n", temp->data);
    free(temp);
}

void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = *front;
    *front = (*front)->next;
    printf("Dequeued element: %d\n", temp->data);
    free(temp);
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
    struct Node* stack = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;
    int choice, data;

    do {
        printf("Choose an operation:\n");
        printf("1. Push to Stack\n2. Pop from Stack\n3. Enqueue to Queue\n4. Dequeue from Queue\n5. Display Stack\n6. Display Queue\n7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push to Stack: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                printf("Enter data to enqueue to Queue: ");
                scanf("%d", &data);
                enqueue(&queueFront, &queueRear, data);
                break;
            case 4:
                dequeue(&queueFront);
                break;
            case 5:
                printf("Stack: ");
                displayList(stack);
                break;
            case 6:
                printf("Queue: ");
                displayList(queueFront);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}
