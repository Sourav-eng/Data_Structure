#include <stdlib.h>
#include<stdio.h>
struct node {
    int data;
    struct node* next;
    
};
void traversal(struct node* p){
    while(p!=NULL){
        printf("element are %d\n",p->data);
        p=p->next;
  }
}
/*
struct node* insert(struct node * head, int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
    }*/
/*struct node* insert(struct node * head, int data,int index){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node * p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}*/
struct node* insert(struct node * head, int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    ptr->data=data;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
    }

int main(){
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;
    
    head= (struct node*)malloc(sizeof(struct node));
    second= (struct node*)malloc(sizeof(struct node));
    third= (struct node*)malloc(sizeof(struct node));
    fourth= (struct node*)malloc(sizeof(struct node));
    head->data=8;
    head->next=second;
    second->data=9;
    second->next=third;
    third->data=12;
    third->next=fourth;
    fourth->data=20;
    fourth->next=NULL;
    printf("before inerstion\n");
    traversal(head);
    head= insert(head,56);
    printf("after inerstion\n");
    traversal(head);

}