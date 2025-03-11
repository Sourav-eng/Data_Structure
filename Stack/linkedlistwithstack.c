#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node *head= NULL;

int isfull(struct node * head){
    struct node*p= (struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    } else{
        free(p);
        return 0;
    }
}
int isempty(struct node* head){
     return head==NULL;     

    }

struct node *push(int x, struct node *head){
    if(isfull(head)){
        printf("stack overflow\n");
        return head;
    }
    struct node*p=(struct node*)malloc(sizeof(struct node));
    p->data= x;
    p->next=head;
    head=p;
    return head; 
}
void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("element in stack are %d\n",ptr->data);
        ptr=ptr->next;
    }
}


int main(){
    head=push(89,head);
    head=push(44,head);
    head=push(6,head);
    head=push(7,head);
    traversal(head);

}
