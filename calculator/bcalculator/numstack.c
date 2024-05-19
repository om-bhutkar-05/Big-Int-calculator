#include"llfuncs.c"

snode* csnode(list data) {
    snode* newNode = (snode*)malloc(sizeof(snode));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}
void push(stack* top, list data) {
    snode* newNode = csnode(data);
    if (newNode) {
        newNode->next = *top;
        *top = newNode;
    }
}
list pop(stack* top) {
    if (*top == NULL) {
        return NULL;
    }
    snode* temp = *top;
    list popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}
int isEmpty(stack top) {
    return top == NULL;
}