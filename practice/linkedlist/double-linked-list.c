#include <stdio.h>
#include <stdlib.h>
#define N 10

struct node {
	int id;
	struct node *next, *prev;

};

typedef struct node *link;

link head = NULL;
link tail = NULL;

link make_node(int id)
{
	link p;
	p = malloc(sizeof(*p));
	p->id = id;
	p->next = NULL;
	p->prev = NULL;

	return p;
}

void insert_node(link t)
{
	link p;
	p = t;
	if(head == NULL)
	{
		head = tail = p;
		head->prev = NULL;
		tail->next = NULL;
	}
	else
	{
		tail->next = p;
		p->prev = tail;
		tail = p;
	}

}

void traverl_node(link t)
{
	link p;
	p = head;
	while(p != NULL)
	{
		printf("p->id = %d\n", p->id);
		p = p->next;
	}
}

void traverl_over_node(link t)
{
	link p;
	p = tail;
	do
	{
		printf("p->id = %d\n", p->id);
		p = p->prev;
	}while(p != NULL);
}

link select_sort(link t)
{
	link min, first, last, p;
	first = last = NULL;
	while(head != NULL)
	{
		for(p = head, min = head; p != NULL; p = p->next)
			if(p->id < min->id)
				min = p;
		if(min == head)
			head = head->next;
		else if(min == tail)
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		else
		{
			min->prev->next = min->next;
			min->next->prev = min->prev;
		}
		if(first == NULL)
		{
			first = last = min;
			first->prev = NULL;
			last->next = NULL;
		}
		else
		{
			last->next = min;
			min->prev = last;
			last = min;
		}
	}
	head = first;
	tail = last;
	head->prev = NULL;
	tail->next = NULL;
	return head;
}

void delet_node(link t)
{
	link p;
	p = t;
	if(p == head)
		head = head->next;
	else if(p == tail)
	{
		tail = p->prev;
		tail->next = NULL;
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
}

int main(void)
{	
	int i;
	int a[N];
	link p;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		p = make_node(a[i]);
		insert_node(p);
	}
	traverl_node(head);
	printf("************************\n");
	traverl_over_node(head);
	printf("************************\n");
	p = select_sort(head);
	traverl_node(p);
	printf("************************\n");
	p = head->next->next;
	delet_node(p);
	traverl_node(head);

	return 0;
}
