#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100

char stack[MAX_STACK_SIZE];
char queue[MAX_QUEUE_SIZE];

int rear = -1;
int front = -1;
int top = -1;

void addq(char data) {
    if (rear == MAX_QUEUE_SIZE - 1)
        printf("Queue is full!!");
    else
        queue[++rear] = data;
}

char deleteq() {
    if (front == rear)
        printf("Queue is Empty");
    else
        return queue[++front];
}

void push(char item) {
    if (top >= MAX_STACK_SIZE - 1)
        printf("Stack is overflow !!!\n");
    else {
        top++;
        stack[top] = item;
    }
}

char pop() {
    if (top == -1)
        printf("Stack is empty!!!");
    else
        return stack[top--];
}

int main(void) {
    char word[100], sword, qword, i, p = 1;
    printf(" Enter word...");
    scanf("%s", word);
    for (i = 0; i < strlen(word); i++) {
        push(word[i]);
        addq(word[i]);
    }
    for (i = 0; i < strlen(word); i++) {
        sword = pop();
        qword = deleteq();
        if (sword != qword) {
            printf("False\n");
            p = 0;
            break;
        }
    }
    if (p == 1)
        printf("True\n");

    return 0;
}
