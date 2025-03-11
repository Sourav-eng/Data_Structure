#include <stdio.h>
#include <stdlib.h>



struct stack {
    int max_size;
    int top;
    int *arr;
};
int stacktop(struct stack* ptr){
    return ptr->arr[ptr->top];
}

int stackbottom(struct stack* ptr){
    return ptr->arr[0];
}
int isempty(struct stack *ptr) {
    return (ptr->top == -1);
}

int isfull(struct stack *ptr) {
    return (ptr->top == ptr->max_size - 1);
}

void push(int value, struct stack *ptr) {
    if (isfull(ptr)) {
        printf("Stack overflow\n");
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("Element %d is inserted\n", value);
    }
}

int pop(struct stack *ptr) {
    if (isempty(ptr)) {
        printf("Stack underflow\n");
        return -1;
    } else {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
       
    }
}

int main() {
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->max_size = 45;
    st->top = -1;
    st->arr = (int *)malloc(st->max_size * sizeof(int));

    printf("Stack created successfully\n");
    push(435,st);
    push(35,st);
    push(43,st);
    push(85,st);
    push(3,st);
    printf("Element %d is popped\n", pop(st));
    printf("element at top is %d\n",stacktop(st));
    printf("element at bottom is %d\n",stackbottom(st));
   
    

    /*/int value;
    char ch;

    while (1) {
        // Ask for the value to be inserted
        printf("Enter the value to be inserted (0 to stop): ");
        scanf("%d", &value);

        // If the user enters 0, stop the loop
        if (value == 0) {
            printf("Stopping insertion...\n");
            break;
        }

        push(value, st);

        // Ask if the user wants to continue
        printf("Do you want to continue inserting? (y/n): ");
        scanf(" %c", &ch);  // Note the space before %c to handle newline issue

        if (ch == 'n' || ch == 'N') {
            break;
        }
    }*/

    return 0;
}
