#include"numstack.c"
charstack* chnode(char data) {
    charstack* nn = (charstack*)malloc(sizeof(charstack));
    if (nn) {
        nn->data = data;
        nn->next = NULL;
    }
    return nn;
}
void chpush(chstack* top, char data) {
    charstack* nn = chnode(data);
    if (nn) {
        nn->next = *top;
        *top = nn;
    }
}
char chpop(chstack* top) {
    if (*top == NULL) {
        return '\0';
    }

    charstack* temp = *top;
    char poppedData = temp->data;
    *top = (*top)->next;
    free(temp);

    return poppedData;
}
int isempty(chstack top) {
    return top == NULL;
}