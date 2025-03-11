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

/*struct node* deletefirstnode(struct node * head){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
    }*/
/*struct node* deleteinbw(struct node * head,int index){
    struct node* p=head;
    struct node*q=head->next;
    int i=0;
   while(i<index-1){
    p=p->next;
    q=q->next;
    i++;
   }
   p->next=q->next;
   free(q);
    return head;
}*/
struct node* deleteatend(struct node * head){
    struct node *p=head;
    struct node* q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
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
    printf("before deletion\n");
    traversal(head);
    head= deleteatend(head);
    printf("after deletion\n");
    traversal(head);

}