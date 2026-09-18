
#include <stdio.h>
#include <stdlib.h>

#define size 50
char stack[size];
int top = -1;

char pop()
{
    if (top == -1) { printf("Stack is underflow.\n"); return '#'; }
    char value = stack[top--];
    printf("Popped element: %c\n", value);
    return value;
}

void push(char c)
{
    if (top == size - 1) printf("Stack is overflow.\n");
    else { stack[++top] = c; printf("%c pushed into stack.\n", c); }
}

int isoperator(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/' ||
            op == '^' || op == '(' || op == ')');
}

int p_n(char c)
{
    switch (c) {
        case '(': return 8;
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        case '^': return 7;
        case ')': return 1;
    }
}

int p_s(char c)
{
    switch (c) {
        case '(': return 1;
        case '+': case '-': return 3;
        case '*': case '/': return 5;
        case '^': return 6;
        case ')': return 1;
        case '#': return 0;
    }
}

char *itp(char *inf)
{
    int i = 0, k = 0;
    char next, *post = malloc(50 * sizeof(char));

    push('#');

    while (inf[i] != '\0') {
        next = inf[i++];
        if (!isoperator(next)) post[k++] = next;
        else {
            while (p_n(next) < p_s(stack[top])) post[k++] = pop();
            if (p_n(next) == p_s(stack[top])) pop();
            else push(next);
        }
    }

    while (stack[top] != '#') post[k++] = pop();
    post[k] = '\0';
    return post;
}

int main()
{
    char ch[50] = "(A+B)/C^(D*E)";
    char *ps = itp(ch);
    printf("%s", ps);
    return 0;
}

