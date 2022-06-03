#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head;

// 1 2 3 4 5
// 1->NULL
// 1 -> 2 > null
// 
void create_ll(int data)
{
	struct node *tmp = (struct node *) malloc(sizeof(struct node));
	struct node *tmp2;
	if (tmp == NULL)
		return;

	tmp->data = data;

	if(head == NULL)
		head = tmp;
	else
	{
		tmp2 = head; 
		while(tmp2->next != NULL)
			tmp2 = tmp2 ->next;
		tmp2->next = tmp;
	}	
}

struct node* reverse(struct node* head)
{
	struct node *prev = NULL;//a
	struct node *next = NULL;//b
	while(head != NULL)
	{
		next = head->next;//b=head->b
		head->next=prev;//head->b=a
		prev=head;//a=b
		head=next;//head=b
	}
	head = prev;//head=a
	return head;
}


void print_ll(void)
{
	struct node *tmp = head;
	struct node *ptr;
	while(tmp != NULL)
	{
		printf("%d-->", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL\n");
}
void main(void)
{
	create_ll(1); //head node
	create_ll(2);
	create_ll(3);
	create_ll(4);
	create_ll(5);
	print_ll();
	head=reverse(head);
	print_ll();
}
