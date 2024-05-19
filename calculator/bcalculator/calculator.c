#include"infix.c"
int main(){
    char expression[100];

    printf("Enter the infix expression: ");
    scanf("%s", expression);
    list result = evaluateInfix(expression);
printf("\nresult: " );
printReverse(result);
}