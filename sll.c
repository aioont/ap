#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *nxt;
};

struct node *top;


void push() {
    int val;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL) {
        printf("Mem allocation failed !!! Can't Insert");
    }
    
    else {
        printf("\nEnter value to be inserted : ");
        scanf("%d",&val);
        if(top==NULL) {
            temp->data=val;
            temp->nxt=NULL;
            top=temp;
        }
        else {
            temp->data=val;
            temp->nxt=top;
            top=temp;
        }
      printf("\n %d is inserted successfully !!! ", val);
    }
}

void pop() {
    int val;
    struct node *temp;
    temp=top;
    if(temp==NULL)
        printf("\nStack is empty. Deletion can't be performed !!!");
    else {
        val=temp->data;
        top=top->nxt;
        free(temp);   
        printf("\n%d is deleted ", val);
    }    
}

void display() {
    int i=0;
    struct node *temp=top;
    if(temp==NULL)
        printf("\nStack is empty. Nothing to print");
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
        printf("\n1.Push 2.Pop 3.Display 4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
        }
             
    }
 }
    
