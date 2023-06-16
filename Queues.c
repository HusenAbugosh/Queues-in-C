#include <stdio.h>
#include <stdlib.h>

// Made by Husain Abugosh 8/6/2023

/*
Queues: is a type of data structure which follows the First-In-First-Out (FIFO) order.
In other words, the first element that was inserted will be the first one to get removed,
just like a real-life queue.

we can  imagin it like queue of Bank Machine the first person came to the Machine, He will be the person
fiish his busniess and so on ..

      👇🏽front            👇🏽Rare
    📇 🚶‍♂️  🚶🏼‍♀️  🚶🏿 🚶🏿 🚶🏿 🚶🏿 🚶🏼‍♀️     //<--  bank queue.


Queues can be implemented using:
1) arrays 2) structures 3) pointer 4) linked-list data

in this program we will implement it using Linked List.

Queue main Operations:
1)Enqueue: Insert element at the end (Called Rear) (insert at the end of the list)
2)Dequeue: Delete and return the element at the begining (Called front) (remove from begining)

Complexity: O(1) running time (WE ARE NOT TRAVERSING EELMENTS)*/


//linked list struct
typedef struct Node {

    int data;
    struct Node* next;

}Node;

/*Queue struct: it will store in it 2 linkedList Nodes (each node have data , *next)
the first node  will save the front node  of the linked list.
the second node will save the rere node  of the linked list.
 */

typedef struct Queue {
     Node *front;  //<-- it will point to the first node(head) of the linkedList.
     Node *rear;  //<-- it will point to the last node(tail) of the linkedList.
}Queue;

// this function will create a new linked lidt node and store the dat in it :
 Node* newNode(int k) {

    Node* temp = (struct Node*)malloc(sizeof(struct Node)); //<-- will search for empty space in memo.

    // handle if there any issue in the  allocating memory:
    if (temp == NULL) {
        printf("Memory overflow. Could not allocate memory.\n");
        exit(0);
    }
    temp->data = k;       //<-- insert the data in the node.
    temp->next = NULL;   //<-- set the pointer.
    return temp;
}

//this function will create a  Queue Node:
 Queue* createQueue() {

    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    // handle if there any issue in the  allocating memory:
    if (q == NULL) {
        printf("Memory overflow. Could not allocate memory.\n");
        exit(0);
    }
    q->front = q->rear = NULL;
    return q;
}

/* this function will Insert element at the end (Called Rear) (insert at the end of the list)
by taking the q we need to insert the elemnet in and the value of the element as parameters:*/
void enQueue(Queue* q, int k) {

    // create a new linkedlist node with the inserted element(K):
     Node* temp = newNode(k);

    // if queue is empty then -> new node will be the front & rear both(the only emelent in the queue):
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    // if the queue is NOT empty then -> add the new node at the end of queue and change the rear:
    q->rear->next = temp;
    q->rear = temp;  //<-- make the last inserted  element  the rear.
}

// this function will remove a key from the front of the given queue:
void deQueue(Queue* q) {

    // if queue is empty -> return NULL(nothing to remove)
    if (q->front == NULL){
       return;
    }
        
    // store previous front and move front one node ahead.
     Node* temp = q->front;
     q->front = q->front->next;

    // if front becomes NULL then -> change rear also to NULL.
    if (q->front == NULL){
       q->rear = NULL;
    }

    printf("element { %d }  removed \n", temp->data);
    free(temp); //<-- free the node.
}

// this function will return the front of the queue
int getFront(Queue* q) {

    // if queue is empty -> return NULL(nothing to remove)
    if (q->front == NULL){
       return;
    }
        
    // store previous front and move front one node ahead.
     Node* temp = q->front;
     q->front = q->front->next;

    // if front becomes NULL then -> change rear also to NULL.
    if (q->front == NULL){
       q->rear = NULL;
    }

    return temp->data;
}


void deleteQueue(Queue* q) {

     Node* currentNode = q->front;
     Node* nextNode;
    
    // go to the front of the linked list then delete it then to next one an so on ..
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    // after deleting all nodes -> set the front and rear pointers to NULL:
    q->front = q->rear = NULL;
    printf("the queue deleted\n");
}





int main() {

    struct Queue* q = createQueue(); //<-- declear a Queue.

    enQueue(q, 10);  //<-- insert an element(10) to the rear of Queue.
    enQueue(q, 20); //<-- insert an element(20) to the rear of Queue.
    enQueue(q, 30); //<-- insert an element(20) to the rear of Queue.
    deQueue(q);    //<-- remove the front element. // 10

    printf("Queue Front: %d \n", q->front->data); // 20
    printf("Queue Rear: %d \n", q->rear->data); // 30

    return 0;

}

