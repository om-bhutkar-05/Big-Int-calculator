#include"charstack.c"
int charToInt(char c) {
    return c - '0';
}
long long int linkedListToInteger(list head) {
  long long int result = 0;
    int multiplier = 1;

    while (head != NULL) {
        result += head->digit * multiplier;
        multiplier *= 10;
        head = head->next;
    }

    return result;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

bool isnegative(list p){
    list l=copyList(p);
    if(l==NULL)return false;
    while(l->next!=NULL){
        l=l->next;
    }
    if(l->digit<0){
        return true;
    }
    return false;
}

int compare(list l1, list l2) {
    int count1 = 0, count2 = 0;

    for (list p1 = l1; p1 != NULL; p1 = p1->next, count1++);
    for (list p2 = l2; p2 != NULL; p2 = p2->next, count2++);

    if (count1 > count2) {
        return 1;
    } else if (count1 < count2) {
        return 2;
    }

    list p1 = l1, p2 = l2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->digit > p2->digit) {
            return 1;
        } else if (p1->digit < p2->digit) {
            return 2;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return 0;
}

list copyList(const list original) {
    if (original == NULL) {
        return NULL;
    }

    list copied = cnode(original->digit);
    list originalPtr = original->next;
    list copiedPtr = copied;

    while (originalPtr != NULL) {
        copiedPtr->next = cnode(originalPtr->digit);
        copiedPtr = copiedPtr->next;
        originalPtr = originalPtr->next;
    }

    return copied;
}

list positive(list l){
    list p=copyList(l);
    list q=p;
while(p->next!=NULL){
    p=p->next;
}
p->digit=p->digit*-1;
return q;
}
list negative(list l){
    list p=copyList(l);
    list q=p;
while(p->next!=NULL){
    p=p->next;
}
p->digit=p->digit*-1;
return q;
}
void removeTrailingZeros(list* head) {
    if (*head == NULL) {
        return;
    }
    list current = *head;
    list lastNonZero = NULL;

    while (current != NULL) {
        if (current->digit != 0) {
            lastNonZero = current;
        }
        current = current->next;
    }

    if (lastNonZero != NULL) {
        lastNonZero->next = NULL;
    } else {
        *head = cnode(0);
    }
}
list reverseList(list head) {
    list p=head;
list rev=NULL;
while(p!=NULL) {
    insert(&rev,p->digit);
    p=p->next;}

    return rev;
}