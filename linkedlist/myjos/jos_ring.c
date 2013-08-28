#include <stdio.h>
#include <stdlib.h>
#define N 6
#define OUT 3

struct node {
	int id;
	struct node *next;
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

	return p;
}

void insert_tail(link p)
{
	if(head == NULL)
	{
		head = tail = p;
		tail->next = head;
		return ;
	}
	tail->next = p;
	tail = p;
	tail->next = head;

	return ;
	
}

void reserves(link t)
{
	link p;
	if(t == NULL)
		return ;
	p = t;
	do
	{
		printf("p->id = %d\n", p->id);
		p = p->next;
	}while(p != t);
}

void delete(link p)
{
	link pre;
	if(head->next == head)
	{
		head = tail = NULL;
		free(p);
		return;
	}
	if(p == head)
	{
		head = p->next;
		tail->next = head;
	}
	else
	{
		link pre;
		pre = head;
		while(1)
		{
			if(pre->next == p)
			{
				pre->next == p->next;
				if(p == tail)
					tail = pre;
				break;
			}
			pre = pre->next;
			if(pre == tail)
				break;
		}
	}
	free(p);
	return ;
}

int main(void)
{
	link p;
	link out;
	int i;
	int counter = 0, tep = 0;
	for(i = 0; i < N; i++)
	{
		p = make_node(i + 1);
		insert_tail(p);
	}
	reserves(head);
	p = head;
	while(head != NULL)
	{
		link save;
		counter++;
		tep++;
		printf("tep = %3d : p->id = %2d counter = %d\n", tep, p->id, counter);
		save = p;
		p = p->next;

		if(counter == OUT)
		{
			counter = 0;
			printf("who is %d\n", save->id);
			delete(save);
		}
	}

	return 0;
}
