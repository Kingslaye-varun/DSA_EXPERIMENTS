#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100

//Stack Structure
typedef struct {
    int top;
    char items[MAX];
} Stack;

//Function Prototypes
void push(Stack *s, char c);
char pop(Stack *s);
char peek(Stack *s);
int isEmpty(Stack *s);
int precedence(char op);
void infixToPostfix(const char *infix, char *postfix);

//Main function
int main(){
    char infix[MAX],postfix[MAX];

    printf("Enter Infix Expression : ");
    scanf("%s",infix);

    infixToPostfix(infix,postfix);
    printf("Postfix Expression : %s\n",postfix);
    return 0;
}

//Push Function
void push(Stack *s,char c){
    if(s->top == MAX-1){
        printf("Stack Full\n");
        return;
    }
    s->items[++(s->top)] = c;
}

//Pop Function
char pop(Stack *s){
if(isEmpty(s)){
    printf("Stack Empty\n");
    return '\0';
    }
return s->items[(s->top)--];
}

//Peek Function
char peek(Stack *s){
    if(isEmpty(s)){
        printf("Stack Empty\n");
        return '\0';
    }
    return s->items[s->top];
}

//Check if Stack is empty
int isEmpty(Stack *s){
    return s->top == -1;
}

//Function to return precedence of operators
int precedence(char op){
    switch(op){
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

//Function to convert infix expression to postfix expression
void infixToPostfix(const char *infix, char *postfix){
    Stack s;
    s.top = -1;

    int i = 0, j = 0;
    while(infix[i]){
        if(isalnum(infix[i])){
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '('){
            push(&s, infix[i]);
        }
        else if(infix[i] == ')'){
            while(!isEmpty(&s) && peek(&s) != '('){
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else{
            while(!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i])){
                postfix[j++] = pop(&s);
            }
            push(&s,infix[i]);
        }
        i++;
    }
    while(!isEmpty(&s)){
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}
