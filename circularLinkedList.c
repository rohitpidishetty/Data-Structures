/*Circular Linked List */
/* Performing insertion in linked list
** we can insert a value into a linked list at 3 positions basically,
** insertAtBeginning, insertAtIndex, insertAtEnd 
** Basic concept of linked list : 
    it consists of a NODE which has an address stored in it, that points 
    to the next NODE, the current NODE's address is linked to the 
    NEXT NODE by a pointer.
    as the pointer points to the NEXT element in the list
    it becomes a continuous link. and the last NODE is pointed to
    the first NODE of the list thus it is know as 
    (Circular Linked List).
    */
#include<stdio.h>
#include<stdlib.h>

/* Creating a struct user-defined data type Node */
struct Node {
    int data;
    struct Node * next;
    // type var(or)* ptr;
};

/* Displaying circular linked list elements */
void displayCircularLinkedList(struct Node * head) {
    struct Node * ptr = head;
    int i = 0;
    do {
        printf("Data at index[%d] --> %d \n",i,ptr->data);
        ptr = ptr->next;
        i++;
    } while(ptr != head);
    /* until we reach the final NODE in the list,
    print all the values stored in it.
    in this the final NODE should be the condition
    not eqaul to currentPointer as this is a 
    Circular linked list */
}
/*
** insertAtBeginning : in order to insert at beginning in circular
** linked list, first we need to traverse the list and reach the final 
** position and then we need to link the new NODE to the last NODE of the 
** list and new NODE's next should be the head again, and as it should be 
** the first element make head = newNode, and return head.
*/
struct Node * insertAtBeginning(struct Node * head,int data) {
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node * ptr = head;
    while(ptr->next != head) {
        ptr = ptr->next;
    } 
    newNode->data = data;
    ptr->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}
/*
** insertAtIndex : in order to insert the element at a specific index number,
** first we gotta travers the list elemenst to the times of the index value
** and update the ptr(a) & stop the loop at this point we need to 
** delink the pointer and point it to the newNode and link this
** newNode's next to the rest of the elements in the list, in order 
** to link we need to traverse another ptr(b) var which stores
** the next of the current ptr(a), and link the newNode's next to ptr(b).
*/
struct Node * insertAtIndex(struct Node * head, int data, int index) {
    struct Node * ptr = head;
    struct Node * ptr1 = head->next;
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    int i = 0;
    if(index == 0) {
        while(ptr->next != head) {
        ptr = ptr->next;
    } 
    newNode->data = data;
    ptr->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
    }
    else {
        while(i < index-1) {
        ptr = ptr->next;
        ptr1 = ptr1->next;
        i++;
    } 
    ptr->next = newNode;
    newNode->next = ptr1;
    return head;
    }
    /* Visualisation of the traversal and linkage.
    ADDRESS      : FIRST        SECOND      THIRD
    ptr address  : 1197843      1197844     1197845
    ptr1 address : 1197844      1197845     1197846
    if the pointer is at 2 position, then ptr(SECOND's)->next = newNode,
    and newNode->next = ptr1. delinking the third position of the ptr(THIRD).
    by using this technique we are linking the rest elements with ptr1(SECOND)
    then all elements will be present in the list.
    */

}

/*
** insertAtEnd : in order to insert a number in the end of the circular list,
** first of all we need to traverse the list, and reach the final position of the
** list then we need to delink the link that is pointed to head, and link the 
** last NODE to the newNode and newNode's next to the head, and return head.
*/
struct Node * insertAtEnd(struct Node * head, int data) {
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node * ptr = head->next;
    while(ptr->next != head) {
        ptr = ptr->next;
    } 
    ptr->next = newNode;
    newNode->data = data;
    newNode->next = head;
    return head;
}
/* Main function */
int main() {
    int index = 2; /* Specifying index*/
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fifth = (struct Node *)malloc(sizeof(struct Node));
    /* Initialising list elements */
    head->data = 1; head->next = second;
    second->data = 2; second->next = third;
    third->data = 3; third->next = fourth;
    fourth->data = 4; fourth->next = fifth;
    fifth->data = 5; fifth->next = head; /*As it is pointed to head,
    Circular linked list is created*/
    for(int i = 0; i < 17; i++) { printf("%c ",'-'); }
    printf("\nINSERTION in Circular Linked List\n");
    for(int i = 0; i < 17; i++) { printf("%c ",'-'); } 
    printf("\nDisplaying the list elements\n");
    displayCircularLinkedList(head);
    printf("\nInserting data at the Beginning\n");
    head = insertAtBeginning(head,20);
    displayCircularLinkedList(head);
    printf("\nInserting data at the Index[%d] position\n",index);
    head = insertAtIndex(head,22,index);
    displayCircularLinkedList(head);
    printf("\nInserting data in the End\n");
    head = insertAtEnd(head,40);
    displayCircularLinkedList(head);
    return 0;
}

