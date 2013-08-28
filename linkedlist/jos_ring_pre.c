#include <stdio.h>
#include <stdlib.h>

#define N 100 
#define OUT 3

struct node {
	int id;
	struct node *next;
	struct node *prev;
};
typedef struct node *link;


link make_node(int id)
{
	link p;
	p = malloc(sizeof(*p));
	p->id = id;
	p->next = NULL;
	p->prev = NULL;

	return p;
}

link head = NULL;
link tail = NULL;

void insert_tail(link p)
{
	
	if(head == NULL)
	{
		head = tail = p;
		head->next = head;  //环形
		head->prev = head;
		return ;
	}
	// next insert(only one node head == tail
	if(head == tail)
	{
		tail = p;
		head->next = tail;
		head->prev = tail;

		tail->next = head;
		tail->prev = head;
		return ;
	}

	tail->next = p;
//	tail->prev = tail->prev;
	p->next = head;
	p->prev = tail;
	tail = p;


	return ;	
}

void traverse(link t)
{
	link p;
	if(t == NULL)
		return ;
	p = t;
	#if 1
	do
	{
		printf("p->id = %d\n", p->id);
		p = p->next;
	}while(p != t);
	#endif
}
void delete(link p)
{
	link pre;
	if(head->next == head)
	{
		head = tail = NULL;
		free(p);
		return ;
	}
	if(p == head)
	{
		if(head->next == tail)
		{
			head = tail;
			tail->next = tail;
			tail ->prev = tail;
		}
		else
		{
			head->next->prev = head->prev;
			tail->next = head->next;
			head = head->next;
		}
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;

		if(p == tail)
			tail = p->prev;
	}

	free(p);
	return ;
}

int main(void)
{
	link p;
	int i, step = 0;
	int countoff = 0;
	for(i = 0; i < N; i++)
	{
		p = make_node(i + 1);
		insert_tail(p);
	}

	traverse(head);
	p = head;
	while(head != NULL)
	{
		link out;
		link save;
		step++;
		countoff++;
		printf("step %d : %d countoff:%d\n", step, p->id, countoff);

	#if 1
	save = p;
	p = p->next;	
	if(countoff == OUT)
		{
			countoff = 0;
			printf("who is OUR %d\n", save->id);
			delete(save);
		}
	#endif

	}
	
	return 0;
}
