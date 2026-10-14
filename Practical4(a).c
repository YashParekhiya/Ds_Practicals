
#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 2;

    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        if ((infix[i] >= 'A' && infix[i] <= 'Z') ||
            (infix[i] >= 'a' && infix[i] <= 'z'))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && stack[top] != '(' &&
                   priority(stack[top]) >= priority(infix[i]))
            {
                postfix[j++] = pop();
            }

            push(infix[i]);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

void infixToPrefix(char infix[], char prefix[])
{
    char temp[50], postfix[50];
    int i, j = 0;

    for (i = strlen(infix) - 1; i >= 0; i--)
    {
        if (infix[i] == '(')
            temp[j++] = ')';
        else if (infix[i] == ')')
            temp[j++] = '(';
        else
            temp[j++] = infix[i];
    }

    temp[j] = '\0';

    infixToPostfix(temp, postfix);

    j = 0;

    for (i = strlen(postfix) - 1; i >= 0; i--)
        prefix[j++] = postfix[i];

    prefix[j] = '\0';
}

int main()
{
    char infix[50], postfix[50], prefix[50];

    printf("Enter infix expression: ");
    scanf("%49s", infix);

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    printf("Postfix expression: %s\n", postfix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
