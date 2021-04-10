// *************************Implementing stack with Array************************* //

#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack *ptr){
if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr,int val){
    if(isFull(ptr)){
        printf("Stack overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow");
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(struct stack *sp, int i){
    int arrIndex = sp->top-i+1;
    if(arrIndex < 0){
        printf("Not a valid input");
        return -1;
    }
    else{
        return sp->arr[arrIndex];
    }
}

int stackTop(struct stack *sp){
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp){
    return sp->arr[0];
}

int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr =  (int*)malloc(sp->size*sizeof(int));
    
    printf("Before pushing, Full: %d\n",isFull(sp));
    printf("Before pushing, Empty: %d\n",isEmpty(sp));
    
    if(isEmpty(sp)){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is full\n");
    }
    
    push(sp,56);
    push(sp,23);
    push(sp,34);
    push(sp,45);
    push(sp,67);
    push(sp,78);
    push(sp,89);
    push(sp,90);
    push(sp,98);
    push(sp,87);

    printf("After pushing, Full: %d\n",isFull(sp));
    printf("After pushing, Empty: %d\n",isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp));
    
    for(int j = 1; j <= sp->top+1;j++){
         printf("The value at position %d is %d\n", j, peek(sp, j));
    }
    
    printf("The top most value of the stack is %d\n",stackTop(sp));
    printf("The bottom most value of the stack is %d\n",stackBottom(sp));
    
    return 0;
}