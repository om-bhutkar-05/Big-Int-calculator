#include "ops.c"

node *add(list num1, list num2)
{
    if (isnegative(num1))
    {
        list res = NULL;
        list temp = positive(num1);
        int n = compare(reverseList(temp), reverseList(num2));

        if (n == 1)
        {
            res = subtract(temp, num2);
            removeTrailingZeros(&res);
            res = negative(res);
            return res;
        }
        else if (n == 2){
            res = subtract(num2, temp);
            removeTrailingZeros(&res);
            return res;
        }
        else if (n == 0)
        {
            res = cnode(0);
            return res;
        }
    }

    list result = NULL;
    int carry = 0;

    while (num1 != NULL && num2 != NULL)
    {
        int sum = num1->digit + num2->digit + carry;
        append(&result, sum % 10);
        carry = sum / 10;

        num1 = num1->next;
        num2 = num2->next;
    }

    while (num1 != NULL)
    {
        int sum = num1->digit + carry;
        append(&result, sum % 10);
        carry = sum / 10;
        num1 = num1->next;
    }

    while (num2 != NULL)
    {
        int sum = num2->digit + carry;
        append(&result, sum % 10);
        carry = sum / 10;
        num2 = num2->next;
    }

    if (carry > 0)
    {
        append(&result, carry);
    }

    return result;
}
node *subtract(list num1, list num2)
{
    if (isnegative(num1) && !isnegative(num2))
    {
        list res = NULL;
        list temp = positive(num1);
        res = add(temp, num2);
        res = negative(res);
        return res;
    }
    else if (isnegative(num2) && !isnegative(num1))
    {
        list res = NULL;
        list temp = positive(num2);
        res = add(temp, num1);
        removeTrailingZeros(&res);  
        return res;
    }
    else if(isnegative(num1)){
       list temp=positive(num2);
       list res=add(num1,temp);
       return res;
    }
    
   
    int borrow = 0;
    int diff;
    list result = NULL;

    while (num1 != NULL || num2 != NULL)
    {
        int digit1 = (num1 != NULL) ? num1->digit : 0;
        int digit2 = (num2 != NULL) ? num2->digit : 0;

        diff = digit1 - digit2 - borrow;

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        append(&result, diff);

        if (num1 != NULL)
        {
            num1 = num1->next;
        }

        if (num2 != NULL)
        {
            num2 = num2->next;
        }
    }
    return result;
}
list multiply(list num1, list num2)
{
    if (isnegative(num1) && !isnegative(num2))
    {
        list res = NULL;
        list temp = positive(num1);
        res = multiply(temp, num2);
        res = negative(res);
        return res;
    }
    if (!isnegative(num1) && isnegative(num2))
    {
        list res = NULL;
        list temp = positive(num1);
        res = multiply(temp, num2);
        res = negative(res);
        return res;
    }
    if (isnegative(num1) && isnegative(num2))
    {
        list res = NULL;
        list temp = positive(num1);
        list temp2 = positive(num2);
        res = multiply(temp, temp2);
        return res;
    }
    list result = NULL;
    int position = 0;

    while (num2 != NULL)
    {
        int carry = 0;
        list currentResult = NULL;

        for (int i = 0; i < position; i++)
        {
            append(&currentResult, 0);
        }

        for (list tempNum1 = num1; tempNum1 != NULL; tempNum1 = tempNum1->next)
        {
            long long int product = carry + (tempNum1->digit * num2->digit);
            carry = product / 10;
            product %= 10;

            append(&currentResult, product);
        }

        while (carry > 0)
        {
            append(&currentResult, carry % 10);
            carry /= 10;
        }

        result = add(result, currentResult);
        num2 = num2->next;
        position++;
    }

    return result;
}

list divide(list num1, list num2)
{
    if(num2->digit==0 && num2->next==NULL){
      printf("error divide by zero");
      return NULL;
}

    if (isnegative(num1))
    {
        list res = NULL;
        list temp = positive(num1);
        res = divide(temp, num2);
        res = negative(res);
        return res;
    }
        if (!isnegative(num1) && isnegative(num2))
    {
        list res = NULL;
        list temp = positive(num1);
        res = divide(temp, num2);
        res = negative(res);
        return res;
    }
    if (isnegative(num1))
    {
        list res = NULL;
        list temp = positive(num1);
        list temp2 = positive(num2);
        printReverse(temp);
        printf("\n");
        printReverse(temp2);
        res = divide(temp, temp2);
        return res;
    }
    list tempn1 = num1;
    list tempn2 = num2;
    list result = NULL;
    long long int res = 0;
    long long int numb1 = linkedListToInteger(tempn1);
    long long int numb2 = linkedListToInteger(tempn2);
    res = numb1 / numb2;
    while (res)
    {
        append(&result, res % 10);
        res /= 10;
    }
    return result;
}

list performOperation(char op, list operand1, list operand2)
{
    switch (op)
    {
    case '+':
        return add(operand1, operand2);
    case '-':
        return subtract(operand1, operand2);
    case '*':
        return multiply(operand1, operand2);
    case '/':
        return divide(operand1, operand2);
    default:
        return NULL;
    }
}