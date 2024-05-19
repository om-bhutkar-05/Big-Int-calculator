#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
typedef struct node {
    int digit;
    struct node* next;
} node;
typedef struct node* list;

typedef struct snode {
    list data;
    struct snode* next;
} snode;
typedef struct snode* stack;

 typedef struct charstack {
    char data;
    struct charstack* next;
}charstack;

typedef struct charstack* chstack;

node* add(list num1, list num2);
node* divide(list num1, list num2);
node* multiply(list num1, list num2);
node* subtract(list num1, list num2);
list copyList(const list original);