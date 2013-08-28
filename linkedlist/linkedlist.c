#include <stdio.h>
#include <stdlib.h>

struct node {
	char item;
	struct node *next;
};

typedef struct node *link;

link head = NULL;
link make_node(char item)
{
	link p = malloc(sizeof(*p));
	p->item = item;
	p->next = NULL;
	return p;
}

void free_node(link p)
{
	free(p);
}

link search(char key)
{
	link p;
	while(p != NULL)
	{
		if(p->item == key)
			return p;
		p = p->next;
	}
	return NULL;
}

void insert(link p)
{
	p->next = head;
	head = p;
}

void delete(link p)
{
	link pre;
	if(p == head)
		{
			head = p->next;
			return ;
		} 
	while(p != NULL)
	{
		if(pre->next == p)	
		{
			pre->next = p->next;
			return ;
		}
		p = p->next;
	}
}

void traverse(void(*visit)(link))
{
	link p;
	while(p != NULL)
	{
		visit(p);
		p = p->next;
	}
}

void destory(void)
{
	link q, p = head;
	head = NULL;
	while(p)
	{
		q = p;
		p = p->next;
		free_node(q);
	}
}

void push(link p)
{
	insert(p);
}

link pop(void)
{
	if(head == NULL)
		return NULL;
	else
	{
		link p = head;
		head = head->next;
		return p;
	}
}

int main(void)
{
	return 0;
}
