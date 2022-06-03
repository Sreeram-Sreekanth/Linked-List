#include <stdio.h>
#include<stdlib.h>



struct node{
int data;
struct node *link;
};



struct node *head;

void add_at_pos(struct node* head,int data,int pos){

struct node *ptr = (struct node *)malloc(sizeof(struct node));
struct node *ptr2 = head;
ptr->data = data;
ptr->link = NULL;
pos--;
while(pos!=1){
ptr2 = ptr2->link;
pos--;
}
ptr->link = ptr2->link;
ptr2->link= ptr;
}



void create_ll(int data)
{
struct node *tmp = (struct node *) malloc(sizeof(struct node));
if (tmp == NULL)
return;

tmp->data = data;

if(head == NULL)
head = tmp;
else
{
struct node *tmp2;
tmp2 = head;
while(tmp2->link != NULL)
tmp2 = tmp2 ->link;
tmp2->link = tmp;
}
}



int main(int data)
{
{
create_ll(10);
create_ll(20);
create_ll(30);
create_ll(40);
create_ll(50);
int pos;
printf("enter the position to insert:\n");
scanf("%d",&pos);
printf("enter the data to insert:\n");
scanf("%d",&data);
add_at_pos(head,data,pos);

struct node *ptr = head;
while(ptr!=NULL){
printf("%d-->",ptr->data);
ptr=ptr->link;
}
printf("NULL\n");
return 0;
}
}
