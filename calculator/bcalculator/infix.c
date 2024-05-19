#include"operations.c"

list evaluateInfix(char* expression) {
    stack numStack = NULL;
    chstack opStack = NULL;
    int i = 0;
    while (expression[i] != '\0') {
        
        if (isdigit(expression[i]) || (expression[i] == '-' && (i == 0 || !isdigit(expression[i - 1])))) {
          list l1=NULL;
      if(expression[i]=='-'){
            insert(&l1,charToInt(expression[i+1])*-1);
            i=i+2;
           }
            while (isdigit(expression[i])) {
                
                insert(&l1,charToInt(expression[i]));
                i++;
            }

            push(&numStack, l1);
            l1=NULL;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!isempty(opStack) && (opStack->data == '*' || opStack->data == '/') &&
                   (expression[i] == '+' || expression[i] == '-')) {
                char op = chpop(&opStack);
                list num2 = pop(&numStack);
                list num1 = pop(&numStack);

                switch (op) {
                    case '+':
                        push(&numStack, add(num1, num2));
                        break;
                    case '-':
                        push(&numStack, subtract(num1, num2));
                        break;
                    case '*':
                        push(&numStack, multiply(num1, num2));
                        break;
                    case '/':
                        push(&numStack, divide(num1, num2));
                        break;
                }
            }
            chpush(&opStack, expression[i]);
            i++;
        } else if (expression[i] == '(') {
            chpush(&opStack, expression[i]);
            i++;
        } else if (expression[i] == ')') {
            while (!isempty(opStack) && opStack->data != '(') {
                char op = chpop(&opStack);
                list num2 = pop(&numStack);
                list num1 = pop(&numStack);

                switch (op) {
                    case '+':
                        push(&numStack, add(num1, num2));
                        break;
                    case '-':
                        push(&numStack, subtract(num1, num2));
                        break;
                    case '*':
                        push(&numStack, multiply(num1, num2));
                        break;
                    case '/':
                        push(&numStack, divide(num1, num2));
                        break;
                }
            }
            if (!isempty(opStack) && opStack->data == '(') {
                chpop(&opStack);  
            }
            i++;
        } else {
            i++;
        }
    }

    while (!isempty(opStack)) {
        char op = chpop(&opStack);
        list num2 = pop(&numStack);
        list num1 = pop(&numStack);

        switch (op) {
            case '+':
                push(&numStack, add(num1, num2));
                break;
            case '-':
                push(&numStack, subtract(num1, num2));
                break;
            case '*':
                push(&numStack, multiply(num1, num2));
                break;
            case '/':
                push(&numStack, divide(num1, num2));
                break;
        }
    }

    return pop(&numStack);
}