#include<stdio.h>
#include<conio.h>

struct node {
    int data;
    struct node *nxt;
};

struct node *front;
struct node *rear;

void enqueue() {
    int val;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
        printf("\nQueue mem allocation failed");
    else {
        printf("\nEnter value : ");
        scanf("%d", &val);
        temp->data=val;
        if(front==NULL) {
            front=temp;
            rear=temp;
            front->nxt=NULL;
            rear->nxt=NULL;
        }
        else {
            rear->nxt=temp;
            rear=temp;
            rear->nxt=NULL;
        }
    }
}

void dequeue() {
    struct node *temp;
    if(front==NULL)
        printf("\nQueue is empty. Nothing to delete !!!");
    else {
        temp=front;
        front=front->nxt;
        free(temp);
    }
    
}

void display() {
    struct node *temp;
    temp=front;
    if(temp==NULL)
        printf("\nQueue is empty !!! Nothing to print ");
    else {
        while(temp!=NULL) {
            printf("%d ", temp->data);
            temp=temp->nxt;
        }
    }
    
}
        

void main() {
    int ch;
    while(1) {
        printf("\n Enqueue 2. Dequeue 3. Display 4. Exit");
        printf("\nEnter ur choice : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
        
    }
}
