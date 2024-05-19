
#include"header.h"

typedef struct node* list;
node* cnode(int digit) {
    node* nn = (node*)malloc(sizeof(node));
    if (nn) {
        nn->digit = digit;
        nn->next = NULL;
    }
    return nn;
}
void insert(list* head, int digit) {
    node* nn = cnode(digit);
    if (nn) {
        nn->next = *head;
        *head = nn;
    }
}
void append(list* head, int digit) {
    node* nn = cnode(digit);
    if (nn) {
        if (*head == NULL) {
            *head = nn;
        } else {
            node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }
}
void del(list* head, int digit) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->digit == digit) {
        node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    node* current = *head;
    while (current->next != NULL && current->next->digit != digit) {
        current = current->next;
    }

    if (current->next != NULL) {
        node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

void printReverse(list head) {
    if (head == NULL) {
        return;
    }

    printReverse(head->next);
    printf("%d ", head->digit);
}
list reverse(list head) {
    list prevNode, currentNode, nextNode;
    prevNode = NULL;
    currentNode = head;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }

    head = prevNode;
    return head;
}
    list createDigitList(int digit) {
    list digitList = cnode(digit);
    return digitList;
}