/*
** STACK : Stack is a linear data structure, in which elements are stored
** using the method push(), and deleted using the method pop(). we can
** even view the element at given Index via using the menthod peek().
** Stack follows Last in First Out (LIFO) principle, in which the last 
** inserted element is been removed first, and the first inserted element
** will be removed at last. 
** ADVANTAGES of STACK using Linked List 
** there are many advantages of STACK using Linked List, as it stores
** 'n' number of values into the STACK.
*/
#include<stdio.h>
#include<stdlib.h>

/* Creating a struct Data type for Stack */
struct Stack {
    int data;
    struct Stack * next;
} * top = NULL; /* Initializing top to NULL primarily */

/* push() : the method push takes in a value and creates a Linked List, 
** that is 'n' number of values can be stored into the Stack.
** As a new element is pushed into the Stack, that new NODE will equalised
** to top. as we add more and more elements into the Stack the top will be
** updating to the Last NODE in the Stack.
*/ 
struct Stack * push(int value) {
    struct Stack * newNode  = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->data = value;
    /* NOTE : the value of the top is equalised to NULL,
    ** so if the top is NULL, then the newNODE is next is NULL
    ** Example : 
    ** [NODE value | NODE pointer]
    ** [value | NULL] -> current Saved NODE.
    ** succeeding elements will be updated to top.
    */
    if(top == NULL) {
        newNode->next = NULL;
    }
    else {
        newNode->next = top;
    }
    top = newNode;
    return top;
}
/*
** pop() : the method pop removes the top element from the
** Stack, and updates the top value.
** Start the pointer 'p' from the current NEXT, then 
** the top  will be neglected. 
*/
struct Stack * pop(struct Stack * ptr) {
    struct Stack * top = ptr;
    struct Stack * p;
    p = top->next;
    /* top is neglected */
    free(top);
    /* clearing the memory of top, and returning the new
    ** pointer p */
    return p;
}
/* 
** the method displayStack() takes in a pointer and
** will traverse until NULL, and returns the pointer values. 
*/
void displayStack(struct Stack * ptr) {
    struct Stack * top = ptr;
    int  i = 0;
    while(top != NULL) {
        printf("%d   ",top->data);
        top = top->next;
        i++;
    }
    printf("\n[ %d elements are stored in Stack ]\n",i);
}
/*
** the method peek() takes in an index, and returns the value
** stored in that respective index.
*/
struct Stack * peek(struct Stack * ptr,int index) {
    int i = 0;
    while(i < index - 1 && ptr->next != NULL) {
        ptr = ptr->next;
        i++;
    }
    printf("%d ", ptr->data);
}
int isEmpty(struct Stack * ptr) {
    if(top == NULL) 
    return 1;
    else  return 0;    
}

/* Main Method */
int main() {
    for(int i=0;i<25;i++) {printf("%c",'-');}
    printf("\nSTACK Using linked list\n");
    for(int i=0;i<25;i++) {printf("%c",'-');}
    struct Stack * a; /* Creating a pointer */
    if(isEmpty(a)) {
        printf("\nStack is Empty\n");
    }
    a = push(23); /* Pushing 23 into Stack */
    /* Pushing values into Stack */
    a = push(30); 
    a = push(411);
    a = push(4);
    a = push(2330);
    printf("\nDisplaying Stack elements\n");
    displayStack(a); /* Displaying Stack */
    printf("\nDeleting Top element\n");
    a = pop(a); /* Removing the top element from Stack */
    displayStack(a);
    printf("\nPeeking at given index\n");
    peek(a,1); /* Viewing the value at this index */
    /* Performing Deletion again */
    printf("\nDeleting Top element\n");
    a = pop(a); /* Removing the top element */
    displayStack(a);
    if(isEmpty(a)) {
        printf("\nStack is Empty\n");
    }
    return 0;
}